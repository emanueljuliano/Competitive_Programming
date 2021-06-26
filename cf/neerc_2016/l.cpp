#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 505;
int d[MAX][(1<<15) + 1];

int msb(int x) { return __builtin_clz(1)-__builtin_clz(x); }

int main(){ _
	int n, m, k, kk;
	cin >> n >> m >> kk;
	k = (kk-1)/40;
	
	vector<pair<int, int>> eg(m);
	vector<vector<int>> g(m);
	for (int i=0; i<m; i++) {
		int u, v, c; cin >> u >> v >> c;
		eg[i] = {u, v};
		for (int j=0; j<c; j++) {
			int r; cin >> r; r--; g[i].push_back(r);
		}
	}
	
	memset(d, INF, sizeof d);
	queue<pair<int, int>> q;
	for (int i=0; i<m; i++) if (eg[i].first == 1) 
		q.push({i, 1}), d[i][1] = 0; 
	
	int ans = -1;
	while (!q.empty()) {
		auto [u, msk] = q.front(); q.pop();
		vector<int> path;
		int v = u;
		path.push_back(eg[v].first);
		for (int i=msb(msk)-1; i>=0; i--) {
			v = g[v][!!(msk & (1 << i))];
			path.push_back(eg[v].first);
		}
		path.push_back(eg[v].second);

		//cout << u << " " << bitset<3>(msk) << " path: ";
		//for (auto w : path) cout << w << " ";
		//cout << endl;

		if (path.back() == n) {ans = d[u][msk]; break;}
	
		for (int i=0; i<g[v].size(); i++) {
			int w = g[v][i];
			bool can = true;
			for (int j=max(0, int(path.size())-k); j<path.size(); j++) { 
		//		cout << "comparing " << path[j] << " " << eg[w].second << endl;
				if (path[j] == eg[w].second) can = false;
			}
			if (!can) continue;

			int msk2;
			int u2 = u;
			if (msb(msk) == k) {
				msk2 = ((msk ^ (1 << k)) << 1) | (1<<k) | i;
				if (k) u2 = g[u2][!!(msk & (1 << (k-1)))];
				else u2 = g[u2][i];
			}
			else {
				msk2 = (msk << 1) | i;
			}
			if (d[u2][msk2] > d[u][msk] + 1) {
				d[u2][msk2] = d[u][msk] + 1;
				q.push({u2, msk2});
			} 
		}
	}

	if (ans == -1) cout << "No chance" << endl;
	else cout << (ans+1)*1000 + kk*25 << endl;
	
	
	exit(0);
}
