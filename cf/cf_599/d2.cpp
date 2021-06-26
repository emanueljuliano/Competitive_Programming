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

int main(){ _
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);

	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].pb(b), g[b].pb(a);
	}

	vector<int> id(n), sz(n), v(n);
	for(int i=0;i<n; i++) v[i]=i, id[i] = i, g[i].pb(i), sz[i]=1;

	function<int(int)> find = [&](int p){
		if(p==id[p]) return p;
		return id[p]=find(id[p]);
	};

	auto une  = [&](int p, int q){
		//cout << p << " "<< q << endl;
		p = find(p), q= find(q);
		if(p==q) return;
		if(sz[p]>sz[q]) swap(p, q);
		id[p] = q, sz[q]+=sz[p];
	};

	vector<int> adj(n);
	sort(v.begin(), v.end(), [&](int p, int q){return g[p].size()<g[q].size();});
	for(auto u : g[v[0]]) adj[u] = true;
	for(int j=0;j <n; j++) if(!adj[j]) {une(v[0], j);}
	for(auto u : g[v[0]]) adj[u] = false;
	for(auto u : g[v[0]]) {
		for(auto w : g[u]) adj[w] = true;
		for(int j=0;j <n; j++) if(!adj[j]) {une(u, j);}
		for(auto w : g[u]) adj[w] = false;
	}

	vector<int> vis(n);
	int ans = -1;
	for(int i=0;i <n; i++) if(!vis[find(i)]) vis[find(i)]=true, ans++;

	cout << ans << endl;
	exit(0);
}
