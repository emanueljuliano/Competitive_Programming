#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 205;

int n;
vector<vector<int>> g(MAX);
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

int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i=0;i <=n; i++)	g[i].resize(0);
		
		int m; cin >> m;
		for(int i=0; i<m; i++){
			int a, b; cin >> a >> b;
			g[a].pb(b);
		}
		tarjan();
		set<int> st;
		for(int i=0;i <n; i++) st.insert(comp[i]);
		cout << st.size() << endl;
	
	}
	
	
	
	exit(0);
}
