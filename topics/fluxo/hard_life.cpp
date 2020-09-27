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

struct frac{
	#define T ll
	ll p, q;

	frac() : p(0), q(1) {}
	frac(T p_) : p(p_), q(1) {}
	frac(T p_, T q_) : p(p_), q(q_) {
		assert(q);
		T g = __gcd(p, q);
		if (g > 1) p /= g, q /= g;
	}

	frac operator + (const frac& f) { return frac(p*f.q + q*f.p, q*f.q); }
	frac operator - (const frac& f) { return frac(p*f.q - q*f.p, q*f.q); }
	frac operator * (const frac& f) { return frac(p*f.p, q*f.q); }
	frac operator / (const frac& f) { return (*this)*frac(f.q, f.p); }
	bool operator < (const frac& f) { return p*f.q < q*f.p; }
};

vector<ii> eg;
int n, m;

bool val(ll p, ll q){
	dinic g(n+m+2);
	for(int i=0;i <n; i++) g.add(i, n+m+1, p);
	for(int i=0;i <m; i++) g.add(n+m, n+i, q), g.add(n+i, eg[i].f,INF), g.add(n+i, eg[i].s,INF);
	ll tot = q*m;

	return g.max_flow(n+m, n+m+1) < tot;
}


int main(){ _
	freopen("hard.in", "r", stdin);
	freopen("hard.out", "w", stdout);

	cin >> n >> m;

	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b; a--, b--;
		eg.pb({a, b});
	}

	if(m==0) return cout << 1 << endl << 1 << endl, 0;
	
	frac l=0, r=n*n;
	
	while(frac(1, n*n)<(r-l)){
		frac mid = (l+r)/2;
		
		if(val(mid.p, mid.q)) l = mid;
		else r = mid;
	}

	dinic g(n+m+2);
	for(int i=0;i <n; i++) g.add(i, n+m+1, l.p);
	for(int i=0;i <m; i++) g.add(n+m, n+i, l.q),g.add(n+i, eg[i].f,INF), g.add(n+i, eg[i].s,INF);
	
	vector<ii> v = g.get_cut(n+m, n+m+1);
	vector<int> ans;
	for(auto u : v) if(u.f >=0 and u.f <n) ans.pb(u.f);
	
	cout << ans.size() << endl;
	for(auto u : ans) cout << u+1 << endl;

	exit(0);
}
