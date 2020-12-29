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

int main(){ _
	int n, m, g;
	while(cin >> n >> m >> g){
		if(!n) break;	
		vector<int> cap(n);
		vector<vector<int>> jogos(n, vector<int>(n));
		for(int i=0;i <g; i++){
			int a, b; char c;
			cin >> a >> c >> b;
			if(c=='=') cap[a]--, cap[b]--;
			else cap[b]--, cap[b]--;
			jogos[a][b]--;
			jogos[b][a]--;
		}
		for(int i=0;i <n; i++) for(int j=0; j<n; j++) jogos[i][j]+=m;
		int p0 = -cap[0];
		int res = 0;
		for(int i=1; i<n; i++) p0 += 2*jogos[0][i], res+=jogos[0][i];
		
		bool show = true;
		for(int i=1; i<n; i++){
			cap[i] += p0-1;
			if(cap[i]<0) show = false;
		}
		if(!show){cout << "N" << endl; continue;}

		int jo = (n)*(n-1)*m/2 - g - res;
		dinic D(jo + n + 2);
		int s = jo+n, t = jo+n+1;

		for(int i=0;i <jo; i++) D.add(s, i, 2);
		int ptr = 0;
		for(int i=1; i<n; i++) for(int j=i+1; j<n; j++) for(int k=0; k<jogos[i][j]; k++)
			D.add(ptr, jo+i, 2), D.add(ptr, jo+j, 2), ptr++;
		for(int i=1; i<n; i++) D.add(jo+i, t, cap[i]);
		
		int ans = D.max_flow(s, t);
		if(ans==2*jo) cout << "Y" << endl;
		else cout << "N" << endl;
	}
	
	exit(0);
}
