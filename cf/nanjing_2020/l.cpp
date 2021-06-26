#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		
		vector<pair<int, int>> red, blue;
		set<int> bb;
		for (int i=0; i<n; i++) {
			int a; cin >> a;
			red.push_back({a, i});
		}
		for (int i=0; i<m; i++) {
			int b; cin >> b;
			blue.push_back({b, i});
			bb.insert(b);
		}
		sort(red.begin(), red.end());
		sort(blue.begin(), blue.end());

		auto lo_red = [&](pair<int, int> p) {
			return int(lower_bound(red.begin(), red.end(), p) - red.begin());
		};
		auto lo_blue = [&](pair<int, int> p) {
			return int(lower_bound(blue.begin(), blue.end(), p) - blue.begin());
		};

		int ans = 0;
		for (auto [a, i] : red) {
			if (bb.count(a))
				continue;
			
			int at = 0;
			if (a > *bb.rbegin()) {
				at = n - lo_red({blue[m-1].first+1, -INF});
			}
			else if (a < *bb.begin()) {
				at = lo_red({blue[0].first-1, INF});
			}
			else {
				int r = lo_blue({a, -INF});
				int l = r-1;
				at = lo_red({blue[r].first-1, INF}) - lo_red({blue[l].first+1, -INF});
			}
			ans = max(ans, at);
		}
		if (ans) cout << ans << endl;
		else cout << "Impossible" << endl;
	}
	
	
	
	exit(0);
}
