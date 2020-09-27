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
	int qt=0;
	struct edge{
		int to, cap, rev, flow;
		bool res;
		int id;
		edge(int to_, int cap_, int rev_, bool res_, int id_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_), id(id_) {}
	};
	vector<vector<edge>> g;
	vector<int> lev, beg;
	dinic(int n) : g(n) {}

	void add(int a, int b, int c){
		g[a].pb(edge(b, c, g[b].size(), false, qt));
		g[b].pb(edge(a, 0, g[a].size()-1, true, qt++));
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
};

int main(){ _
	int n, m; cin >> n >> m;
	dinic g(n);
	for(int i=0;i <m; i++){
		int a, b, c; cin >> a >> b >> c; a--, b--;
		g.add(a, b, c);
	}
	cout << g.max_flow(0, n-1) << endl;
	vector<ii> ans;
	for(int i=0;i <n; i++) for(auto e : g.g[i]) if(!e.res)
		ans.pb({e.id, e.flow});
	sort(ans.begin(), ans.end());
	for(auto x : ans) cout << x.s << endl;
	
	exit(0);
}
