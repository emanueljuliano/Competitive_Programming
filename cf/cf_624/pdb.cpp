#include <bits/stdc++.h>
#include <cassert>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// A red-black tree table storing ints and their order
// statistics. Note that since the tree uses
// tree_order_statistics_node_update as its update policy, then it
// includes its methods by_order and order_of_key.
typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  // This policy updates nodes' metadata for order statistics.
  tree_order_statistics_node_update>
set_t;

int main()
{
  // Insert some entries into s.
  set_t s;
  s.insert(12);
  s.insert(505);
  s.insert(30);
  s.insert(1000);
  s.insert(10000);
  s.insert(100);

  // The order of the keys should be: 12, 30, 100, 505, 1000, 10000.
  assert(*s.find_by_order(0) == 12);
  assert(*s.find_by_order(1) == 30);
  assert(*s.find_by_order(2) == 100);
  assert(*s.find_by_order(3) == 505);
  assert(*s.find_by_order(4) == 1000);
  assert(*s.find_by_order(5) == 10000);
  assert(s.find_by_order(6) == s.end());

  // The order of the keys should be: 12, 30, 100, 505, 1000, 10000.
  assert(s.order_of_key(10) == 0);
  assert(s.order_of_key(12) == 0);
  assert(s.order_of_key(15) == 1);
  assert(s.order_of_key(30) == 1);
  assert(s.order_of_key(99) == 2);
  assert(s.order_of_key(100) == 2);
  assert(s.order_of_key(505) == 3);
  assert(s.order_of_key(1000) == 4);
  assert(s.order_of_key(10000) == 5);
  assert(s.order_of_key(9999999) == 6);

  // Erase an entry.
  s.erase(30);

  // The order of the keys should be: 12, 100, 505, 1000, 10000.
  assert(*s.find_by_order(0) == 12);
  assert(*s.find_by_order(1) == 100);
  assert(*s.find_by_order(2) == 505);
  assert(*s.find_by_order(3) == 1000);
  assert(*s.find_by_order(4) == 10000);
  assert(s.find_by_order(5) == s.end());

  // The order of the keys should be: 12, 100, 505, 1000, 10000.
  assert(s.order_of_key(10) == 0);
  assert(s.order_of_key(12) == 0);
  assert(s.order_of_key(100) == 1);
  assert(s.order_of_key(505) == 2);
  assert(s.order_of_key(707) == 3);
  assert(s.order_of_key(1000) == 3);
  assert(s.order_of_key(1001) == 4);
  assert(s.order_of_key(10000) == 4);
  assert(s.order_of_key(100000) == 5);
  assert(s.order_of_key(9999999) == 5);

	set_t se;
	se.insert(1);
	se.insert(10);
	se.insert(100);
	cout << se.order_of_key(100) << endl;
	se.erase(1);
	cout << se.order_of_key(100) << endl;
  return 0;
}

