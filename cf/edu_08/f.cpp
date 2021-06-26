#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

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
};

int main(){ _
	int n, b, q; cin >> n >> b >> q;
	
	vector<pair<int, int>> query;
	for (int i=0; i<q; i++) {
		int up, qt; cin >> up >> qt;
		query.push_back({up, qt});
	}
	query.push_back({b, n});
	q++;
	
	dinic G(q+b+7);
	int s = q+b+5, t = q+b+6;
	
	sort(query.begin(), query.end());
	int it = 1, at = 0, pt = 0;
	for (auto [up, qt] : query) {
		int real = qt-at;
		//cout << up << " " << qt << " " << real << " " << it << " " << pt << endl;
		if (real < 0) return cout << "unfair" << endl, 0;
		G.add(s, pt, real);
		for (int i=it; i<=up; i++) {
			G.add(pt, i+q-1, 1);
		}
		pt++, at = qt, it = up+1;
	}
	for (int i=1; i<=b; i++) G.add(i+q-1, q+b+i%5, 1);
	for (int i=0; i<5; i++) G.add(q+b+i, t, n/5);
	
	ll ans = G.max_flow(s, t);
	if (ans == n) cout << "fair" << endl;
	else cout << "unfair" << endl;

	exit(0);
}