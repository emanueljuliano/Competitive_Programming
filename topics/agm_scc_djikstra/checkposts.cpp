#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define inf 0x3f3f3f3f

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAX = 1e5 + 100;
int n;
vector < vector <int > > g(MAX);
vector <vector <int> > gi(MAX);
int vis[MAX];
int comp[MAX];
stack <int> S;

void dfs(int k){
	vis[k] = 1;
	for(int i=0; i<g[k].size(); i++){
		if(!vis[g[k][i]]) dfs(g[k][i]);
	}
	S.push(k);
}

void scc(int k, int c){
	vis[k] = 1;
	comp[k] = c;
	for(int i=0; i<gi[k].size(); i++){
		if(!vis[gi[k][i]]) scc(gi[k][i], c);
	}
}

void kosaraju(){
	for(int i=0; i<n; i++) vis[i] = 0;
	for(int i=0; i<n; i++) if(!vis[i]) dfs(i);
	
	for(int i=0; i<n; i++) vis[i] =0;
	while(S.size()){
		int u = S.top();
		S.pop();
		if(!vis[u]) scc(u, u);
	}
}


int main(){ 
	cin >> n;
	int p[MAX];
	for(int i=0; i<n; i++) cin >> p[i];

	int m; cin >> m;
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		gi[b].pb(a);
	}

	kosaraju();
	ll preco[MAX], num[MAX];
	for(int i=0; i<n; i++) preco[i] = inf, num[i] = 1;
	for(int i=0; i<n; i++){
		int com = comp[i];
		if(p[i] < preco[com]){
			num[com] = 1;
			preco[com] = p[i];
		}
		else if(p[i] == preco[com])
			num[com]++;
	}
	ll ans1 = 0;
	ll ans2 = 1;
	for(int i=0; i<n; i++){
		if(preco[i] != inf) ans1 = ans1 + preco[i];
		ans2 = ans2*num[i];
		ans2 %= MOD;
	}

	cout << ans1 << " " << ans2 << endl;
	exit(0);
}



