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
	int n, m, k; cin >> n >> m >> k;
	vector<int> v(n);
	for(auto &i : v) cin >> i, i--;
	vector<vector<int>> g(n);
	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b; a--, b--;
		
		g[a].pb(b);
		g[b].pb(a);
	}
	vector<int> vis(n);
	vector<int> ap, cor(k);
	function<void(int)> dfs = [&](int x){
		if(!cor[v[x]]) ap.pb(v[x]);
		cor[v[x]]++, vis[x] = 1;
		for(auto u : g[x]) if(!vis[u]) dfs(u);
	};

	int ans = 0;
	for(int i=0;i <n; i++){
		if(!vis[i]){
			dfs(i);
			int maxi = 0;
			for(auto u : ap) maxi = max(maxi, cor[u]), ans+=cor[u], cor[u]=0;
			ap.resize(0);
			ans -= maxi;
		}
	}

	cout << ans << endl;
	
	
	exit(0);
}
