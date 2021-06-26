#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

typedef tuple<int, int, int> T;

const int MAX = 1e5+10;

vector<vector<int>> g(MAX), filhos(MAX);
vector<int> vis(MAX);
vector<T> ans;


int dfs(int v, int p){
	vis[v] = 2;
	for(auto u : g[v]) if(u!=p){
		if(!vis[u]) {
			int ret = dfs(u, v);
			if(ret==-1) filhos[v].push_back(u);
			else ans.push_back({v, u, ret});
		}
		else if(vis[u]==2) filhos[u].push_back(v);
	}
	vis[v] = 1;
	while(filhos[v].size()>1) {
		int u = filhos[v].back(); filhos[v].pop_back();
		int w = filhos[v].back(); filhos[v].pop_back();
		ans.push_back({u, v, w});
	}
	if(filhos[v].size()) return filhos[v].back();
	return -1;
}

int main(){ _
	int n, m; cin >> n >> m;
	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].push_back(b), g[b].push_back(a);
	}
	
	for(int i=0;i <n; i++)
		if(!vis[i]) dfs(i, i);
	cout << ans.size() << endl;
	for(auto [a, b, c] : ans) cout << a+1 << " " << b+1 << " " << c+1 << endl;
	
	exit(0);
}
