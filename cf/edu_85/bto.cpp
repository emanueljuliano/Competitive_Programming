#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define forn(i,x,y) for(int i = int(x); i<int(y); i++)
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(V) V.begin(), V.end()
#define on(x, b) (x & (1LL << b))
#define trav(x, v) for(auto &x : v)

#define f first
#define s second

const int N = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int tc; cin >> tc;
    while(tc--) {
        ll n, x; cin >> n >> x;
        vector<ll> a(n); for(ll &i : a) cin >> i;

        sort(all(a), greater<ll>());

        ll sum = 0;
        int i;
        for(i = 0; i < n; i++) {
            sum += a[i];
            double m = (double)sum / (double)(i + 1);
            if(m < x) break;
        }
        cout << i << "\n";

    }


    return 0;
}

/* don't forget to check:
   int overflow
   min/max cases (n = 1)
   printing index of sorted array
   limits for ans (start with inf)
   s = 'x' + s is linear! dont use it!
 */

