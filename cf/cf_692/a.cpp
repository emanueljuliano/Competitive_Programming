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
		int n, m; cin >> n >> m;
		vector<vector<int>> g(n);
		for(int i=0;i <m; i++){
			int a, b; cin >> a >> b; a--, b--;
			if(a==b) continue;
			g[a].pb(b), g[b].pb(a);
		}

		vector<int> vis(n);
		int ans=0, cic=0;
		function<void(int, int)> dfs = [&](int x, int p){
			for(auto u : g[x]) if(u!=p){
				if(!vis[u]) vis[u]=1, dfs(u, x), ans++;
				else cic = 1;
			}
		};
		for(int i=0;i <n; i++) if(!vis[i]){
			cic = 0,  vis[i]=1, dfs(i, i);
			ans += 2*cic;
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
