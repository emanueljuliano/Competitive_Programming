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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

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
	int t; cin >> t;
	while(t--){
		int n, m, k; cin >> n >> m >> k;
		map<ii, int> mp;
		vector<ii> eg;
		vector<int> dg(n);
		int pt = 0;
		vector<vector<int>> g(n);
		
		for(int i=0;i <m; i++){
			int a, b; cin >> a >> b; a--, b--;
			if(a>b) swap(a, b);
			ii p = {a, b};
			eg.pb(p), mp[p] = pt++;
			dg[a]++, dg[b]++;
			g[a].pb(b), g[b].pb(a);
		}

		int s = n+m, st = n+m+1;
		dinic D(n+m+2);
		bool has = true;
		for(int i=0;i <n; i++){
			if(dg[i]<=k) continue;
			if(dg[i]>2*k) {has = false; break;}
			
			D.add(s, i, 2*(dg[i]-k));
			for(auto u : g[i]){
				ii p = {i, u};
				if(i>u) p = {u, i};
				D.add(i, n+mp[p], 1);
			}
		}
		for(auto p : eg) D.add(mp[p]+n, st, 1);
		
		D.max_flow(s, st);
		for(auto e : D.g[s]) {
			if(e.flow < e.cap) has = false;
		}	
		if(!has){
			for(int i=0;i <m; i++) cout << 0 << " ";
			cout << endl;
			continue;
		}

		int color = 1;
		vector<int> ans(m);
		for(int i=0;i <n; i++) if(dg[i]>k){
			vector<int> v;
			for(auto e : D.g[i]) if(e.cap==e.flow) v.pb(e.to-n);
			for(int j=0; j<int(v.size()); j+=2){
				ans[v[j]] = ans[v[j+1]] = color++;
			}
		}

		for(int i=0; i<m; i++) if(!ans[i]) ans[i] = color++;
		for(auto u : ans) cout << u << " ";
		cout << endl;
	}
	
	
	
	exit(0);
}
