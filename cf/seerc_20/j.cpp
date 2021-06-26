#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;
	vector<vector<int>> g(n);
	for (int i=0; i<n-1; i++) {
		int a, b; cin >> a >> b; a--, b--;
		g[a].push_back(b), g[b].push_back(a);
	}

	vector<int> d(n);
	int mini = n;
	for (auto &i : d) cin >> i, mini = min(mini, i);
	int cnt = 0;
	for (auto i : d) if (i == mini) cnt++;

	vector<int> dist(n, -1), sz(n, 0), subtree(n, -1);
	function<void(int, int)> dfs = [&](int i, int c) {
		subtree[i] = c;
		if(dist[i] == mini) sz[c]++;
		for (int j : g[i]) if (dist[j] == -1) dist[j] = dist[i]+1, dfs(j, c);
	};

	vector<int> center;
	for (int i=0; i<n; i++) if (d[i] == mini) center.push_back(i);
	int c = 0;
	for (auto v : center) dist[v] = 0, subtree[v] = c, sz[c]=1, c++;
	if (center.size() > 1) mini--;
	for (int v : center) {
		for (int i : g[v]) if (dist[i] == -1)
			dist[i] = 1, dfs(i, c += (center.size() == 1));
		c++;
	}
	vector<pair<int, int>> ans;
	for (int i=0; i<n; i++) {
		if (dist[i] == mini) ans.push_back({sz[subtree[i]], i});
		else if(dist[i] < mini) ans.push_back({n, i});
		else ans.push_back({n+1, i});
	}

	sort(ans.begin(), ans.end());
	for (auto [ord, v] : ans) cout << v+1 << " ";
	cout << endl;


	exit(0);
}
