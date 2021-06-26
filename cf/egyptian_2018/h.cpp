#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	#warning FILE IN 
    freopen("path.in", "r", stdin);	
	
	int t; cin >> t;
	while (t--) {
		int n, m, u, l, k; cin >> n >> m >> u >> l >> k;
		u--;
		vector<vector<int>> g(n);
		vector<tuple<int, int, int>> eg;
		for (int i=0; i<m; i++) {
			int a, b, c; cin >> a >> b >> c; a--, b--;
			g[a].push_back(b), g[b].push_back(a);
			eg.push_back({c, a, b});
		}

		vector<int> d(n, INF);
		queue<int> q; q.push(u); d[u] = 0;
		while (!q.empty()) {
			int x = q.front(); q.pop();
			for (auto y : g[x]) if (d[y]>d[x]+1) {
				d[y] = d[x]+1; q.push(y);
			}
		}

		sort(eg.begin(), eg.end(), greater());

		int ans = -1;
		for (auto [c, a, b] : eg) {
			if (d[a] > k or d[b] > k) continue;
			if (d[a] == d[b] and d[a] == k) continue;
			ans = c; break;
		}
		cout << ans << endl;
	}
	
	
	exit(0);
}
