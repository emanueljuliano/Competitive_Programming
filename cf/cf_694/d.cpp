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
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n>> m;
		vector<vector<int>> g(n);
		for(int i=0;i <m; i++){
			int a, b; cin >> a >> b; a--, b--;
			g[a].pb(b), g[b].pb(a);
		}

		vector<int> vis(n);
		function<void(int)> dfs = [&](int x){
			for(auto u : g[x]) if(!vis[u]) vis[u] = 1, dfs(u);
		};
		
		bool conected = true;
		vis[0]=1, dfs(0);
		for(int i=0; i<n; i++) if(!vis[i]) conected = false;
		if(!conected){cout << "NO" << endl; continue;}

		cout << "YES" << endl;
		for(int i=0;i <n; i++) vis[i] = 0;
		vector<int> color(n);

		function<void(int)> dfs2 = [&](int x){
			bool can = true;
			for(auto u : g[x]) if(color[u]) can = false;
			color[x] = can;
			for(auto u : g[x]) if(!vis[u]) vis[u] = 1, dfs2(u);
		};
		dfs2(0);
		vector<int> ans;
		for(int i=0;i <n; i++) if(color[i]) ans.pb(i);

		cout << ans.size() << endl;
		for(auto u : ans) cout << u+1 << " ";
		cout << endl;

	}
	
	
	
	exit(0);
}
