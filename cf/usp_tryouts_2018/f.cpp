#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<ll, int, int> T;;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e5+10;
ll d[2][MAX];
vector<pair<int,int>> g[MAX]; // {vizinho, peso}
vector<pair<int,int>> tree[MAX]; // {vizinho, peso}
set<ii> eg_tree;
int n;

void dijkstra(int x, int who) {
	for(int i=0; i < n; i++) d[who][i] = LINF;
	d[who][x] = 0;
	priority_queue<T> pq;
	pq.push(tuple(0, x, x));

	while(pq.size()) {
		auto [ndist, u, v] = pq.top(); pq.pop();
		if(-ndist > d[who][u]) continue;
		if(u!=v and who==0) {
			int w_edge = d[who][u] - d[who][v];
			tree[u].pb({v, w_edge}), tree[v].pb({u, w_edge});
			eg_tree.insert({u, v});
			eg_tree.insert({v, u});
		}
		for(auto [idx,w] : g[u]) if(d[who][idx] > d[who][u] + w) {
			d[who][idx] = d[who][u] + w;
			pq.push(tuple(-d[who][idx], idx, u));
		}
	}
}

int s, t;
bool is_path[MAX], vis[MAX];

bool dfs_path(int v){
	vis[v] = true;
	if(v==t) return is_path[v] = true;
	for(auto [u, w] : tree[v]) if(!vis[u]) is_path[v] |= dfs_path(u);
	return is_path[v];
}

ll ans;
set<pair<ll, ii>> st;

void dfs(int v){
	vis[v] = true;
	if(v==t) return;
	for(auto [u, w] : tree[v]) {
		if(!is_path[u] and !vis[u]) dfs(u);
	}
	for(auto [u, w] : g[v]) {
		if(!eg_tree.count({u, v})){
			st.insert({w + d[0][v] + d[1][u], {v, u}});
		}
	}

	if(is_path[v]){
		bool has_edge = false;
		while(st.size()){
			auto IT = *st.begin();
			if(vis[IT.s.f] and vis[IT.s.s]) {st.erase(IT); continue;}
			has_edge = true;
			ans = max(ans, IT.f);
			break;
		}
		if(!has_edge){
			cout << -1 << endl;
			exit(0);
		}
	}
	for(auto [u, w] : tree[v]) {
		if(is_path[u] and !vis[u]) dfs(u);
	}
}

int main(){ _
	int m; cin >> n >> m;
	cin >> s >> t; s--, t--;
	for(int i=0;i <m; i++){
		int a, b, c; cin >> a >> b >> c; a--, b--;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}	
	if(s==t or n==1) return cout << 0 << endl, 0;
	dijkstra(s, 0);
	if(d[0][t] == LINF) return cout << -1 << endl, 0;
	dijkstra(t, 1);
	dfs_path(s);
	ans = d[0][t];
	memset(vis, 0, sizeof vis);
	dfs(s);

	cout << ans << endl;
	exit(0);
}
