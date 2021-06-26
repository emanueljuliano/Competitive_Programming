#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int main(){ _
	int n; cin >> n;
	
	vector<vector<int>> g(n);
	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].push_back(b), g[b].push_back(a);
	}

	function<int(int , int)> dfs = [&](int v, int p){
		int d = 0;
		for(auto u : g[v]) if(u!=p) d += dfs(u, v);
		return d == 0 ? 1 : d-1;
	};

	if(dfs(0, 0)) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	
	exit(0);
}
