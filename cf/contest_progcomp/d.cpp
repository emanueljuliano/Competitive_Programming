#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// Dinic
//
// O(min(m * max_flow, n^2 m))
// Grafo com capacidades 1 -> O(sqrt(n)*m)

struct dinic {
	const bool scaling = false; // com scaling -> O(nm log(MAXCAP)),
	ll lim;                    // com constante alta
	struct edge {
		ll to, cap, rev, flow; // para, capacidade, id da reversa, fluxo
		bool res; // se a aresta eh residual
		edge(ll to_, ll cap_, ll rev_, bool res_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
	};

	vector<vector<edge>> g;
	vector<ll> lev, beg;
	dinic(ll n): g(n) {}

	void add(ll a, ll b, ll c) { // de a pra b com cap. c
		g[a].push_back(edge(b, c, g[b].size(), false));
		g[b].push_back(edge(a, 0, g[a].size()-1, true));
	}
	bool bfs(ll s, ll t) {
		lev = vector<ll>(g.size(), -1); lev[s] = 0;
		beg = vector<ll>(g.size(), 0);
		queue<ll> q; q.push(s);
		while (q.size()) {
			ll u = q.front(); q.pop();
			for (auto& i : g[u]) {
				if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
				if (scaling and i.cap - i.flow < lim) continue;
				lev[i.to] = lev[u] + 1;
				q.push(i.to);
			}
		}
		return lev[t] != -1;
	}
	ll dfs(ll v, ll s, ll f = INF){
		if (!f or v == s) return f;
		for (ll& i = beg[v]; i < g[v].size(); i++) {
			auto& e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;
			ll foi = dfs(e.to, s, min(f, e.cap - e.flow));
			if (!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}
		return 0;
	}
	ll max_flow(ll s, ll t) {
		ll f = 0;
		for (lim = scaling ? (1<<30) : 1; lim; lim /= 2)
			while (bfs(s, t)) while (ll ff = dfs(s, t)) f += ff;
		return f;
	}
	vector<pair<ll, ll> > get_cut(ll s, ll t) {
		max_flow(s, t);
		vector<pair<ll, ll> > cut;
		vector<ll> vis(g.size(), 0), st = {s};
		vis[s] = 1;
		while (st.size()) {
			ll u = st.back(); st.pop_back();
			for (auto e : g[u]) if (!vis[e.to] and e.flow < e.cap)
				vis[e.to] = 1, st.push_back(e.to);
		}
		for (ll i = 0; i < g.size(); i++) for (auto e : g[i])
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

vector<pair<ii, ll>> eg;
ll n, m, x;
typedef long double ld;

bool val(ld mm){
	dinic g(n);
	for(ll i=0;i <m; i++) g.add(eg[i].f.f, eg[i].f.s, ll(eg[i].s/mm));
	return g.max_flow(0, n-1) >= x;
}



int main(){ _
	cin >> n >> m >> x;
	ll maxi = 0;
	dinic g(n);
	
	for(ll i=0;i <m; i++){
		ll a, b, c; cin >> a >> b >> c;
		a--, b--;
		g.add(a, b, c);
		eg.pb({{a, b}, c});
		maxi += c;
	}

	if(g.max_flow(0, n-1)==0){
		cout << 0 << endl;
		exit(0);
	}
	ld l = 0, r = 1e7;
	while(x*(r-l)>1e-6){
		ld mid = (l+r)/2;

		if(val(mid)) l = mid;
		else r = mid;
	}

	cout << setprecision(8) << fixed;
	cout << (l+r)/2*x << endl;

	exit(0);
}
