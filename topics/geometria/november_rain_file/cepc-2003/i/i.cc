#define NDEBUG
#include <cstring>
#include <cassert>
#include <algorithm>
#include <cstdio>

static const int MAX_INPUTS  =  50000;
static const int MAX_SORTERS = 500000;
static const int INF = MAX_SORTERS*2;

/*
It is easy to see that Maximizer works correctly iff it works correctly for
the input consisting of '1' on the first input and '0's on all remaining
inputs (see "01-principle" in Corman, Leiserson, Rivest "Introduction to
Algorithms"). Thus the problem boils down to finding the length of the
shortest subsequence of the initial sequence sorters that moves the '1'
from the index 1 to the index n.

For each prefix of the initial sequence of sorters we define
function:

  length(q,k) =
    the shortest subsequence of first q sorters that moves
    '1' from index 1 to index k.

It is easy to see that

  length(0,1) = 0
  length(0,k) = infinity     for all k in [2..n]

  length(q,sorter[q].upper) = 
      min(
          length(q-1,sorter[q].upper)
        , 1 + min{ length(q-1,i) : i in [sorter[q].lower..sorter[q].upper-1] }
      )
      for q > 0
  
  length(q,k) = length(q-1,k)   
      for q > 0  and  k != sorter[q].upper

The value length(m,n) is the answer.

Program computes values of length(q,k) for consecutive values of q.

The values of the function 'length' are stored in tournament tree,
so that updating the function value and computing a minimum over
a range takes logarithmic time. 

Total time:   Theta(n + m log n)
Total memory: Theta(n)

*/

using namespace std;

namespace ceil_of_bin_log_impl {
    template <bool cond, int n, int exp> struct compute;
    
    template <int n, int exp> struct compute<false, n, exp> {
        static const int exp2  = exp+1;
        static const int power = 1<<exp2;
        static const int value = compute<(n<=power),n,exp2>::value;
    };
    
    template <int n, int exp> struct compute<true, n, exp> {
        static const int value = exp;
    };
}

template <int n>
struct ceil_of_bin_log
{
    static const int value = ceil_of_bin_log_impl::compute<(n<=1),n,0>::value;
};



template <int capacity>
class tournament_tree
{
public:
    tournament_tree()
    {
        fill(data_, data_ + size_, INF);
    }
    
    void update(int non_normalized_index, int value)
    {
        int index = leaf_index(non_normalized_index);
        data_[index] = value;
        fix_invariant(index);
    }
    
    int get(int non_normalized_index) const
    {
        return data_[leaf_index(non_normalized_index)];
    }
    
    int find_min(int lower_non_norm_index, int upper_non_norm_index) const
    {
        int lower = leaf_index(lower_non_norm_index);
        int upper = leaf_index(upper_non_norm_index);
        int minimum = min(data_[lower], data_[upper]);
        while (upper - lower > 1)
        {
            if (is_left_child(lower))  minimum = min(minimum, data_[lower+1]);
            if (!is_left_child(upper)) minimum = min(minimum, data_[upper-1]);
            lower = parent(lower);
            upper = parent(upper);
        }
        return minimum;
    }
    
private:
    static bool is_left_child(int index)
    {
        return index & 1;
    }
    
    void fix_invariant(int index)
    {
        while (index > 0)
        {
            int minimum = min(data_[index], data_[sibling(index)]);
            index = parent(index);
            if (data_[index] == minimum) return;
            data_[index] = minimum;
        }
    }
    
    static int sibling(int index)
    {
        return index + ((1 & index) << 1) - 1;
    }
    
    static int parent(int index)
    {
        return (index - 1) >> 1;
    }
    
    static int leaf_index(int non_normalized_index)
    {
        assert(1 <= non_normalized_index && non_normalized_index <= capacity);
        int index = non_normalized_index - 1;
        return (1 << (levels_ - 1)) + index - 1;
    }
    
private:
    static const int levels_ = 1 + ceil_of_bin_log<capacity>::value;
    static const int size_   = 1 << levels_;
    int data_[size_];
};

tournament_tree<MAX_INPUTS> length;

int main() {
    int input_count, sorter_count;
    scanf("%d %d", &input_count, &sorter_count);
    assert(2 <= input_count  &&  input_count <= MAX_INPUTS);
    assert(2 <= sorter_count &&  sorter_count <= MAX_SORTERS);

    length.update(1, 0); // no sorters necessary to lift maximum to index 1
    
    for(int j = 0; j < sorter_count; ++j) {
        int lower, upper;
        scanf("%d %d", &lower, &upper);
        assert(1 <= lower  &&  lower <= MAX_INPUTS);
        assert(1 <= upper  &&  upper <= MAX_INPUTS);
        
        int minimum = length.find_min(lower, upper);
        length.update(upper, min(length.get(upper), 1 + minimum));
    }
    
    assert(length.get(input_count) != INF);
    printf("%d\n", length.get(input_count));
}
