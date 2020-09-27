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

// MinCostMaxFlow Papa

// min_cost_flow(s, t, f) computa o par (fluxo, custo)
// com max(fluxo) <= f que tenha min(custo)
// min_cost_flow(s, t) -> Fluxo maximo de custo minimo de s pra t
// Se tomar TLE, aleatorizar a ordem dos vertices no SPFA

template<typename T> struct mcmf {

	struct edge {
		int to, rev, flow, cap; // para, id da reversa, fluxo, capacidade
		bool res; // se eh reversa
		T cost; // custo da unidade de fluxo
		edge() : to(0), rev(0), flow(0), cap(0), cost(0), res(false){}
		edge(int to_, int rev_, int flow_, int cap_, T cost_, bool res_)
			: to(to_), rev(rev_), flow(flow_), cap(cap_), res(res_), cost(cost_){}
	};

	vector<vector<edge>> g;
	vector<int> par_idx, par;

	mcmf(int n) : g(n), par_idx(n), par(n) {}

	void add(int u, int v, int w, T cost) { // de u pra v com cap w e custo cost
		edge a = edge(v, g[v].size(), 0, w, cost, false);
		edge b = edge(u, g[u].size(), 0, 0, -cost, true);

		g[u].push_back(a);
		g[v].push_back(b);
	}

	bool spfa(int s, int t) {
		deque<int> q;
		vector<bool> is_inside(g.size(), 0);
		T inf = numeric_limits<T>::max() / 3;
		vector<T> dist(g.size(), inf);

		dist[s] = 0;
		is_inside[s] = true;
		q.push_back(s);

		while (!q.empty()) {
			int u = q.front();
			is_inside[u] = false;
			q.pop_front();

			for (int i = 0; i < (int)g[u].size(); i++)
				if (g[u][i].cap > g[u][i].flow && dist[u] + g[u][i].cost < dist[g[u][i].to]) {
					dist[g[u][i].to] = dist[u] + g[u][i].cost;
					par_idx[g[u][i].to] = i;
					par[g[u][i].to] = u;

					if (is_inside[g[u][i].to]) continue;
					if (!q.empty() && dist[g[u][i].to] > dist[q.front()]) q.push_back(g[u][i].to);
					else q.push_front(g[u][i].to);

					is_inside[g[u][i].to] = true;
				}
		}

		return dist[t] != inf;
	}

	pair<int, T> min_cost_flow(int s, int t, int flow = INF) {
		int f = 0;
		T ret = 0;
		while (f <= flow && spfa(s, t)) {
			int mn_flow = flow - f, u = t;
			while (u != s){
				mn_flow = min(mn_flow, g[par[u]][par_idx[u]].cap - g[par[u]][par_idx[u]].flow);
				u = par[u];
			}

			u = t;
			while (u != s) {
				g[par[u]][par_idx[u]].flow += mn_flow;
				g[u][g[par[u]][par_idx[u]].rev].flow -= mn_flow;
				ret += g[par[u]][par_idx[u]].cost * mn_flow;
				u = par[u];
			}

			f += mn_flow;
		}

		return make_pair(f, ret);
	}

	// Opicional: Retorna todas as arestas originais por onde passa fluxo = capacidade.
	vector<pair<int,int>> recover() {
		vector<pair<int,int>> used;
		for (int i = 0; i < g.size(); i++) for (edge e : g[i])
			if(e.flow == e.cap && !e.res) used.push_back({i, e.to});
		return used;
	}
};
int main(){ _
	int n, m; cin >> n >> m;
	mcmf<int> g((int)(n+m+2));
	int s = n+m;
	int t = n+m+1;
	vector<int> v;
	for(int i=0;i <n; i++){
		int a; cin >> a; v.pb(a);
	}
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;a--; b--;
		g.add(i+n, a, 1, 0);
		g.add(i+n, b, 1, 0);
	}
	for(int i=0;i <n; i++){
		g.add(i, t, v[i], 0);
	}
	for(int i=0;i <m; i++){
		g.add(s, i+n, 2, 0);
	}
	vector<ii> edge = g.recover();
	vector<int> ans(m, 0);
	for(auto p : edge){
		int a = p.f, b = p.s;
		cout << a << " " << b << endl;
		if(a==s) swap(a, b);
		else if(a<b) swap(a, b);
		if(a==t) continue;
		a -= n;
		ans[a]++;
	}
	bool alive = true;
	for(auto i : ans) if(i==0) alive = false;
	if(!alive) cout << "DEAD" << endl;
	else{
		cout << "ALIVE" << endl;
		for(int i=0;i <m; i++) if(ans[i]==2) cout << i << " ";
		for(int i=0;i <m; i++) if(ans[i]==1) cout << i << " ";
		cout << endl;
	}
	
	
	exit(0);
}
