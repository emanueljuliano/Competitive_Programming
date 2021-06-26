#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ld p_elev[20][int(2e5)];

int main(){ _
	int t; cin >> t;
	
	for (int i = 1; i<20; i++) {
		ld p = (1-i*1e-4);
		for (int j=1; j<int(2e5); j++) {
			p_elev[i][j] = p;

			p = p*(1-i*1e-4);
		}
	}

	while (t--) {
		ll n, m, pp; cin >> n >> m >> pp;
		ld p = pp*1e-4;
		ld pneg = 1-p;
		ld ans = (n+m)/p;
		
		if (pp >= 20) {
			for (ll x=1; x<1e4; x++) {
				if (n*x+m > ans)
					break;
				ld at = ld(n*x+m)/(1-pneg);
				//cout << x << " " << at << endl;
				ans = min(ans, at);
				pneg *= (1-p);
			}
			cout << setprecision(10) << fixed;
			cout << ans << endl;
		}
		else{
			auto f = [&](ll x) {
				return ld(n*x+m)/(1-p_elev[pp][x]);
			};
			ll l = 1, r = 2e5-1;

			while (l < r) {
				if (r-l < 10) {
					for (int i=l; i<=r; i++) {
						ans = min(ans, f(i));
					}
					break;
				}
				int ml = l+(r-l)/3, mr = r-(r-l)/3;
				if (f(ml) > f(mr)) l = ml;
				else r = mr;
			}
			cout << setprecision(10) << fixed;
			cout << ans << endl;
		}
	}


	exit(0);
}
