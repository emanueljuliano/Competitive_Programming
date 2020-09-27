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

const int MAX = 1e6+10;

vector<vector<int>> g(MAX), ids(MAX), val(MAX);
vector<int> vis(MAX);
vector<int> v;

void dfs(int x){
	for(auto u : g[x]){
		if(vis[u]) continue;
		vis[u] = vis[x];
		ids[vis[u]].pb(u);
		val[vis[u]].pb(v[u]);
		dfs(u);
	}
}


int main(){ _
	int n, m; cin >> n >> m;
	v.resize(n);
	for(auto &i: v) cin >> i;
	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}	
	int cmp = 0;
	for(int i=0;i <n; i++){
		if(!vis[i]){
			cmp++;
			vis[i] = cmp;
			ids[cmp].pb(i);
			val[cmp].pb(v[i]);
			dfs(i);
		}
	}
	vector<int> ans(n);
	for(int i=1;i <=cmp; i++){
		sort(ids[i].begin(), ids[i].end());
		sort(val[i].begin(), val[i].end(), greater<>());
		for(int j=0; j<ids[i].size(); j++) ans[ids[i][j]] = val[i][j];
	}
	for(auto x : ans) cout << x << " ";
	cout << endl;
	
	exit(0);
}
