#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

pair<ll, ll> val(ll x, ll y) {
	ll gc = gcd(x, y);
	x/=gc, y/=gc;
	if (x == 0) y = 1;
	if (y == 0) x = 1;
	if (y < 0) x = -x, y = -y;
	return {x, y};
}

int main(){ _
	int t; cin >> t;
	while (t--) {
		map<pair<ll, ll>, int> mp;
		map<pair<ll, ll>, set<pair<ll, ll>>> Yv;
		
		int n; cin >> n;
		for (int i=0; i<n; i++) {
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			if (x1 > x2) swap(x1, x2), swap(y1, y2);
			
			auto [dx, dy] = val(x1-x2, y1-y2);
			pair<ll, ll> pi = {dx, dy};

			// yv = y1 - (dy/dx)*x1
			// num(yv) = y1*dx-dy*x1
			// den(yv) = dx
			
			pair<ll, ll> yv;
			if (dx) yv = val(y1*dx - dy*x1, dx);
			else yv = {x1, 0};
			if (!Yv[pi].count(yv)) {
				mp[pi]++;
				Yv[pi].insert(yv);
			}
		}
		
		ll ans = 0;
		for (auto [p, cnt] : mp) {
			int dx = -p.second, dy = p.first;
			ans += 	mp[val(dx, dy)] * ll(cnt);
		}

		cout << ans/2 << endl;
	}
	
	
	
	exit(0);
}
