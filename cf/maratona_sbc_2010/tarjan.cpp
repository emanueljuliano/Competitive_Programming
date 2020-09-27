#include <bits/stdc++.h>

using namespace std;

const int MAX = 5500;

int n, m;
vector<vector<int> > g(MAX);
stack<int > s;
int vis[MAX], comp[MAX];
int id[MAX], p;

int dfs(int k){
	int lo = id[k] = p++;
	int viz;
	s.push(k);
	vis[k] = 2; // ta na pilha

	// calcula o menor cara q ele alcanca
	// que ainda nao esta em um scc
	for(int i=0; i<g[k].size(); i++){
		viz = g[k][i];
		if(!vis[viz])
			lo = min(lo, dfs(viz));
		else if(vis[viz]==2)
			lo = min(lo, id[viz]);
	}

	// nao alcanca ninguem menor > comeca scc
	if(lo == id[k]) while(true){
		int u = s.top();
		s.pop();
		vis[u] = 1;
		comp[u] = k;
		if(u==k) break;
	}

	return lo;
}


void tarjan(){
	p =0;
	memset(vis, 0, sizeof(vis));
	for(int i=0; i<n; i++) if(!vis[i]) dfs(i);
}

int main(){
	while(true){
		cin >> n >> m;
		if(n==0 and m==0) break;		
		for(int i=0; i<n; i++){
			id[i]=i; comp[i]=i; g[i].resize(0);
		}

		for(int i=0; i<m; i++){
			int a, b, c;
			cin >> a >> b >> c;
			a--;
			b--;
			if(c==1)
				g[a].push_back(b);
			else{
				g[a].push_back(b);
				g[b].push_back(a);
			}
		}

		tarjan();
		bool flag = false;
		for(int i=0; i<n; i++){
			// cout << comp[i] << " ";
			flag |= comp[i];
		}
		if(flag) cout << 0 << endl;
		else cout << 1 << endl;
	}
	exit(0);
}

