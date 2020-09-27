#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef pair<int, int> ii;
typedef long long ll;

const int MAX = 1e4+10;

int n;
vector<int> g[MAX];
stack<int> s;
int vis[MAX], comp[MAX];
int id[MAX], p;

// se quiser comprimir ciclo em grafo nao direcionado,
// colocar um if na dfs para nao voltar pro vertice que veio
int dfs(int k) {
	int lo = id[k] = p++;
	s.push(k);
	vis[k] = 2; // ta na pilha

	// calcula o menor cara q ele alcanca
	// que ainda nao esta em um scc
	for (int i = 0; i < g[k].size(); i++) {
		if (!vis[g[k][i]])
			lo = min(lo, dfs(g[k][i]));
		else if (vis[g[k][i]] == 2)
			lo = min(lo, id[g[k][i]]);
	}

	// nao alcanca ninguem menor -> comeca scc
	if (lo == id[k]) while (1) {
		int u = s.top();
		s.pop(); vis[u] = 1;
		comp[u] = k;
		if (u == k) break;
	}

	return lo;
}

void tarjan() {
	memset(vis, 0, sizeof(vis));

	p = 0;
	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);
}

vector<vector<int>> g2(MAX);
vector<int> val(MAX);

int dfs2(int x){
	int ret = 0;
	for(auto u : g2[x]){
		if(u==x) continue;
		if(!vis[u]) vis[u] = 1, dfs2(u);
		ret = max(ret, val[u]);
	}
	return val[x] = ret+1;
}

int main(){ _
	int m; cin >> n >> m;
	vector<ii> e;
	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].pb(b);
		e.pb({a, b});
	}
	tarjan();
	
	for(int i=0;i <m; i++){
		int a = comp[e[i].f], b = comp[e[i].s];
			g2[a].pb(b);
	}
	memset(vis, 0, sizeof(vis));

	int ans = 0;
	for(int i=0;i <n; i++){
		if(!vis[i]) vis[i] = 1, ans = max(ans, dfs2(i)); 
	}
	cout << ans << endl;

	exit(0);
}

