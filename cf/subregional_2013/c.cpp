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

int MAX = 550;
vector<int> v;
vector<vector<int>> g(MAX);

vector<int> vis(MAX);
int dfs(int a){
	int ret = INF;
	for(auto u : g[a]){
		if(vis[u]) continue;
		vis[u] = 1;
		ret = min({ret, v[u], dfs(u)});
	}
	return ret;
}

int main(){ _
	int n, m, q; cin >> n >> m >> q;
	v.resize(n);
	for(auto &i:v) cin >> i;
	
	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[b].pb(a);
	}
	vector<int> id(n);
	for(int i=0;i <n; i++) id[i] = i;

	while(q--){
		char c; cin >> c;
		if(c=='P'){
			int a; cin >> a; a--;
			vis[id[a]] = 1;
			int x = dfs(id[a]);
			if(x<INF) cout << x << endl;
			else cout << "*" << endl;
			for(int i=0;i <n; i++) vis[i] = 0;
		}
		else{
			int a, b; cin >> a >> b; a--, b--;
			swap(v[id[a]], v[id[b]]);
			swap(id[a], id[b]);
		}
	}
	
	
	exit(0);
}
