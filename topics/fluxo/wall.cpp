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
	int lim;
	struct edge{
		int to, cap, rev, flow;
		bool res;
		edge(int to_, int cap_, int rev_, bool res_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
	};
	vector<vector<edge>> g;
	vector<int> lev, beg;
	dinic(int n) : g(n) {}

	void add(int a, int b, int c){
		g[a].pb(edge(b, c, g[b].size(), false));
		g[b].pb(edge(a, 0, g[a].size()-1, true));
	}
	bool bfs(int s, int t){
		lev = vector<int>(g.size(), -1); lev[s] = 0;
		beg = vector<int>(g.size(), 0);
		queue<int> q; q.push(s);
		while(q.size()){
			int u = q.front(); q.pop();
			for(auto&i : g[u]){
				if(lev[i.to] != -1 or (i.flow==i.cap)) continue;
				lev[i.to] = lev[u]+1;
				q.push(i.to);
			}
		}
		return lev[t]!=-1;
	}
	int dfs(int v, int s, int f=INF){
		if(!f or v==s) return f;
		for(int &i=beg[v]; i<g[v].size(); i++){
			auto& e = g[v][i];
			if(lev[e.to] != lev[v]+1) continue;
			int foi = dfs(e.to, s, min(f, e.cap-e.flow));
			if(!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}
		return 0;
	}
	ll max_flow(int s, int t){
		ll f = 0;
		while(bfs(s, t)) while(int ff=dfs(s, t)) f+= ff;
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
int f(int x, int y) {return x*m+y;}
int f2(int x, int y) {return n*m + x*m+y;}
bool val(int x, int y) {return x>=0 and y>=0 and x<n and y<m;}


int main(){ _
	cin >> n >> m;
	int k, l; cin >> k >> l;
	dinic g(2*n*m);

	vector v(n, vector<int>(m));
	for(int i=0;i <k; i++){
		int x, y; cin >> x >> y; x--, y--;
		v[x][y] = -1;
	}
	for(int i=0;i <l; i++){
		int x, y; cin >> x >> y; x--, y--;
		v[x][y] = 1;
	}
	for(int i=0;i <n; i++) for(int j=0; j<m; j++){
		if(v[i][j]==0) g.add(f(i, j), f2(i, j), INF);
		else if(v[i][j]==1) g.add(f(i, j), f2(i, j), 1);
		for(int kk=0; kk<4; kk++){
			int x = i+vx[kk], y = j+vy[kk];
			if(val(x, y)) g.add(f2(i, j), f(x, y), INF);
		}
	}
	int x, y; cin >> x >> y; x--, y--;
	int s = f(x, y);
	cin >> x >> y; x--, y--;
	int t = f(x, y);

	ll flow = g.max_flow(s, t);
	if(flow>=INF) return cout << -1 << endl, 0;
	cout << flow << endl;
	vector<ii> ans = g.get_cut(s, t);
	for(auto p : ans) cout << min(p.f, p.s)/m+1 << " " << min(p.f, p.s)%m+1 << endl;

	exit(0);
}
