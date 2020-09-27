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
};

int main(){ _
	int n, m; cin >> n >> m;

	vector<map<int, int>> fat(n);
	map<int, int> id; int pt = 0;
	set<int> st;
	for(int i=0;i <n; i++){
		int a; cin >> a;
		for(ll j=2; j*j<=a; j++) if(a%j==0){
			if(!id.count(j)) id[j] = pt++;
			while(a%j==0) a/=j, fat[i][id[j]]++;
		}
		if(a!=1){
			if(!id.count(a)) id[a] = pt++;
			fat[i][id[a]]++;
		}
	}

	int s = n, t = n+1;
	vector<dinic> g(pt, dinic(n+2));
	for(int i=0;i <n; i++) for(auto x : fat[i]){
		if(i%2==0) g[x.f].add(s, i, x.s);
		else g[x.f].add(i, t, x.s);
	}

	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b; a--, b--;
		if(a%2) swap(a, b);
		for(int i=0;i <pt; i++) g[i].add(a, b, INF);
	}

	ll ans = 0;
	for(int i=0;i <pt; i++){
		ans += g[i].max_flow(n, n+1);
	}
	cout << ans << endl;

	exit(0);
}
