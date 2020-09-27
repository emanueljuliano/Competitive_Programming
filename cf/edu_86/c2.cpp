#include <bits/stdc++.h>
using namespace std;
#define eb emplace_back
#define emp emplace
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll gcd(ll a, ll b) { 
	if (b == 0) 
		return a; 
	return gcd(b, a % b);  
} 

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;

	while (t--) {
		ll a, b, q; cin >> a >> b >> q;

		if (a > b) swap(a, b);

		ll mmc = a*b/gcd(a,b);

		while (q--) {
			ll l, r; cin >> l >> r;

			if (r-l+1 <= 500*500) {
				ll ans = 0;
				for (ll i = l; i <= r; i++) {
					if (i%a%b != i%b%a) {
						ans++;
					}
				}
				cout << ans << " ";
			} else {
				ll L = l+(mmc-l%mmc);
				ll R = r-(r%mmc)-1;
				ll ans = (R-L+1) - (R-L+1)/mmc*b;

				ans += (L-1)-l+1  - (b - (min(b, mmc - ((L-1)-l+1))));
				ans += max(0ll, r-(R+1)+1 - b);

				cout << ans << " ";
			}
		}

		cout << "\n";
	}

	return 0;
}


