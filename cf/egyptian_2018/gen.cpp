#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

int main(int argc, char** argv) {
    srand(atoi(argv[1]));
    
    int T = 1; // uniform(1, 10);
    cout << T << endl;
    for (int i = 0; i < T; i++) {
        int N, L, R;
        N = uniform(1, 10);
        L = uniform(1, 100);
        R = uniform(1, 100);
        if (L > R) swap(L, R);

        cout << N << ' ' << L << ' ' << R << endl;
        
        set<pair<int,int>> st;
        while (st.size() < N) {
            int x = uniform(-10, 10), y = uniform(-10, 10);
            st.emplace(x, y);
        }

        for (auto [x, y] : st) cout << x << ' ' << y << endl;
    }
}
