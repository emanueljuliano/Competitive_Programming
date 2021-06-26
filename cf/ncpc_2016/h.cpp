#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;
	vector<vector<int>> g(2*n);
	map<int, int> mp;
	vector<int> rev(2*n), vals;
	int sz = 0;

	for (int i=0; i<n; i++) {
		int s, t; cin >> s >> t;
		if (!mp.count(s)) mp[s] = sz++, vals.push_back(s);
		if (!mp.count(t)) mp[t] = sz++, vals.push_back(t);
		rev[mp[s]] = s, rev[mp[t]] = t;

		g[mp[s]].push_back(mp[t]);
		g[mp[t]].push_back(mp[s]);
	}
	
	sort(vals.begin(), vals.end(), greater<>());
	ll ans = 0;	
	vector<bool> vis(vals.size());
	
	int n_vts, n_edges;
	function<void(int)> dfs = [&](int i) {
		vis[i] = 1;
		ans += rev[i] * ll(g[i].size() - 1);
		n_vts++, n_edges += g[i].size()-1;

		for (int j : g[i]) if (!vis[j]) dfs(j);
	}; 

	for (auto c : vals) if (!vis[mp[c]]) {
		n_vts = 0, n_edges = 0;
		dfs(mp[c]);
		if (n_vts > n_edges) ans += c;
	}
	
	cout << ans << endl;

	exit(0);
}
