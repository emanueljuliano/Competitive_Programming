#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

int main(){ _
	int n, m; cin >> n >> m;
	ll ans = 0, x = 0, tot = n*ll(n-1)/2 - m;
	
	vector<vector<int>> g(n);
	vector<tuple<int, int, int>> eg;
	
	for (int i=0;i <m; i++) {
		int a, b, c; cin >> a >> b >> c; a--, b--;
		g[a].push_back(b), g[b].push_back(a);
		eg.push_back({c, a, b});
		x ^= c;
	}
	
	set<int> st;
	for (int i=0;i <n; i++) st.insert(i);
	vector<int> id(n), id2(n); iota(id.begin(), id.end(), 0), iota(id2.begin(), id2.end(), 0);
	function<int(int)> f = [&](int a) { return id[a] = a == id[a] ? a : f(id[a]); };
	function<int(int)> f2 = [&](int a) { return id2[a] = a == id2[a] ? a : f2(id2[a]); };
	auto une = [&](int a, int b) { a = f(a), b = f(b); id[a] = b; };
	auto une2 = [&](int a, int b) { a = f2(a), b = f2(b); id2[a] = b; };

	function<void(int)> dfs = [&](int i) {
		st.erase(i);
		sort(g[i].begin(), g[i].end());
		for (int j = 0; j < n; j++) {
			auto it = st.lower_bound(j);
			if (it == st.end()) return;
			j = *it;
			if (!binary_search(g[i].begin(), g[i].end(), j))
				tot--, une(i, j), dfs(j);
		}
	};
	
	for (int i=0; i<n; i++) if (st.count(i)) dfs(i);

	if (tot) x = 0;	
	sort (eg.begin(), eg.end());
	for (auto [c, a, b] : eg) {
		if (f(a) != f(b)) ans += c, une(a, b), une2(a, b);
		else if (f2(a) != f2(b)) x = min<int>(x, c);
	}
	ans += x;

	cout << ans << endl;

	exit(0);
}
