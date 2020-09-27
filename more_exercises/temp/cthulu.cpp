#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g(100);
int vis[100] = {0};

int dfs(int v, int dest){
	n_ciclos = 0;
	bool ret = false;
	if(v==dest) ret = true; 
	for(int i=0;i <g[v].size(); i++){
		int u = g[v][i];
		if(vis[u]){
			if(u!=pai) n_ciclos++;
			continue;
		}

		vis[u] = vis[v];
		n_ciclos += dfs(u);
	}
	return ret;
}

int main(){
	int n, m; cin >> n >> m;
	
	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int cmp = 1;
	n_ciclos = 0;
	for(int i=0;i <n; i++){
		if(vis[i] != 0) continue;
		
		vis[i] = cmp;
		cmp++;
		n_ciclos += dfs(i);
	}

	if(cmp==2 and n_ciclos/2 == 1) cout << "FHTAGN!" << endl;
	else cout << "NO" << endl;

}
