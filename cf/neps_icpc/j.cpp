#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;


int main(){ _
	int m, c; cin >> m >> c;
	set<pair<int, int>> st;
	vector<pair<int, int>> ch, mon;
	map<int, int> mpx, mpy;
	
	for (int i=0; i<m; i++) {
		int x, y; cin >> x >> y;
		mon.push_back({x, y});
	}
	for (int i=0; i<c; i++) {
		int x, y; cin >> x >> y;
		ch.push_back({x, y});
	}
	
	set<int> visx, visy;
	for (int i=0; i<m; i++) for (int j=i+1; j<m; j++) {
		if (mon[i].first == mon[j].first) {
			int x = mon[i].first;
			visx.insert(x);
		}
		if (mon[i].second == mon[j].second) {
			int y = mon[i].second;
			visy.insert(y);
		}
	}

	for (int i=0; i<c; i++) {
		auto [x, y] = ch[i];
		if (!visx.count(x) and !visy.count(y)) {
			mpx[x]++, mpy[y]++, st.insert({x, y});
		}
	}
	
	int ans = 0, ansx = 0, ansy = 0;
	for (int i=0; i<m; i++) {
		auto [x, y] = mon[i];
		if (mpx[x] > ans) {
			ansx = x;
			ans = mpx[x];
		}
		if (mpy[y] > ans) {
			ansy = y;
			ans = mpy[y];
		}
		if (mpx[x] + mpy[y] > ans) {
			ansx = x, ansy = y, ans = mpx[x]+mpy[y];
		}

		for (int j=i+1; j<m; j++) {
			auto [x2, y2] = mon[j];
			if (x2 != x and y2 != y) {
				int val = mpx[x] + mpy[y2] - st.count({x, y2});
				if (val > ans) {
					ansx = x, ansy = y2, ans = val;
				}
				val = mpx[x2] + mpy[y] - st.count({x2, y});
				if (val > ans) {
					ansx = x2, ansy = y, ans = val;
				}
			}
		}
	}

	cout << ansx << " " << ansy << endl;
	cout << ans << endl;

	
	exit(0);
}
