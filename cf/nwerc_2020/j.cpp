#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int main(){ _
	int n, m; 
	cin >> n >> m;
	vector<vector<int>> g(n), ans(3);
	vector<int> c(n);
	int sza = n, szb = 0, szm = 0;

	for (int i=0; i<m; i++) {
		int a, b; cin >> a >> b; a--, b--;
		g[a].push_back(b), g[b].push_back(a);
	}
	
	auto resp = [&]() {
		cout << szm << " " << sza << endl;
		for (int i=0; i<n; i++) if (c[i] != 1) ans[c[i]].push_back(i);
		for (int i : {1, 0, 2}) {
			for (int j : ans[i]) cout << j+1 << " ";
			cout << endl;
		}
		exit(0);
	};

	function<void(int)> dfs = [&](int i) {
		sza--, szm++, c[i] = 1, ans[1].push_back(i);
		if (sza == szb) resp(); 

		for (int j : g[i]) if (!c[j]) dfs(j);
		
		szm--, szb++, c[i] = 2, ans[1].pop_back();
		if (sza == szb) resp();
	};

	dfs(0);
}
