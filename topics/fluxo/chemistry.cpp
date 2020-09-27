#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

struct dinic {
	const bool scaling = false; // com scaling -> O(nm log(MAXCAP)),
	int lim;                    // com constante alta
	struct edge {
		int to, cap, rev, flow; // para, capacidade, id da reversa, fluxo
		bool res; // se a aresta eh residual
		edge(int to_, int cap_, int rev_, bool res_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
	};

	vector<vector<edge>> g;
	vector<int> lev, beg;
	dinic(int n): g(n) {}

	void add(int a, int b, int c) { // de a pra b com cap. c
		g[a].push_back(edge(b, c, g[b].size(), false));
		g[b].push_back(edge(a, 0, g[a].size()-1, true));
	}
	bool bfs(int s, int t) {
		lev = vector<int>(g.size(), -1); lev[s] = 0;
		beg = vector<int>(g.size(), 0);
		queue<int> q; q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto& i : g[u]) {
				if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
				if (scaling and i.cap - i.flow < lim) continue;
				lev[i.to] = lev[u] + 1;
				q.push(i.to);
			}
		}
		return lev[t] != -1;
	}
	int dfs(int v, int s, int f = INF){
		if (!f or v == s) return f;
		for (int& i = beg[v]; i < g[v].size(); i++) {
			auto& e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;
			int foi = dfs(e.to, s, min(f, e.cap - e.flow));
			if (!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		ll f = 0;
		for (lim = scaling ? (1<<30) : 1; lim; lim /= 2)
			while (bfs(s, t)) while (int ff = dfs(s, t)) f += ff;
		return f;
	}
	vector<pair<int, int> > get_cut(int s, int t) {
		max_flow(s, t);
		vector<pair<int, int> > cut;
		vector<int> vis(g.size(), 0), st = {s};
		vis[s] = 1;
		while (st.size()) {
			int u = st.back(); st.pop_back();
			for (auto e : g[u]) if (!vis[e.to] and e.flow < e.cap)
				vis[e.to] = 1, st.push_back(e.to);
		}
		for (int i = 0; i < g.size(); i++) for (auto e : g[i])
			if (vis[i] and !vis[e.to] and !e.res) cut.push_back({i, e.to});
		return cut;
	}
};

int n, m;
int vx[4] = {1, -1, 0, 0}, vy[4] = {0, 0, 1, -1};
int f(int x, int y){ return x*m+y;}
bool val(int x, int y){return x>=0 and x<n and y>=0 and y<m;}

int main(){ _
	cin >> n >> m;
	dinic g(n*m+2);
	int s = n*m, t = n*m+1;
	vector v(n, vector<int> (m));
	ll tot1 = 0, tot2=0;
	for(int i=0;i <n; i++) for(int j=0; j<m; j++){
		char a; cin >> a;
		if(a=='H') v[i][j] = 1;
		if(a=='O') v[i][j] = 2;
		if(a=='N') v[i][j] = 3;
		if(a=='C') v[i][j] = 4;	
	}
	for(int i=0;i <n; i++) for(int j=0; j<m; j++){
		if((i%2)==(j%2)){
			g.add(s, f(i, j), v[i][j]);
			tot1+=v[i][j];

			for(int k=0; k<4; k++){
				int x = i + vx[k], y = j+vy[k];
				if(val(x, y)) g.add(f(i, j), f(x, y), 1);
			}
		}
		else g.add(f(i, j), t, v[i][j]), tot2 += v[i][j];
	}

	ll ans = g.max_flow(s, t);
	if(ans==tot1 and ans==tot2 and ans) cout << "Valid" << endl;
	else cout << "Invalid" << endl;

	exit(0);
}
