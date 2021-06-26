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
		ll n; cin >> n;
		
		vector<vector<int>> g(n);
		for(int i=0;i <n; i++){
			int a, b; cin >> a >> b; a--, b--;
			g[a].pb(b), g[b].pb(a);
		}

		vector<int> vis(n);
		ll ans = 0;
		bool found = false;
		function<int(int, int)> dfs = [&](int x, int p){
			int ret = 0;
			vis[x] = 1;
			for(auto u : g[x]) if(u!=p){
				if(vis[u]==1) vis[x] = 2, ret = 1;
				else if(vis[u]==2) vis[x] = 2, ret = 0;
				else ret |= dfs(u, x);
			}
			if(ret) vis[x] = 2;
			return ret;
		};
		dfs(0, 0);
		for(int i=0;i <n; i++) if(vis[i]==1) found = true;
		if(!found){
			cout << n*(n-1) << endl;
		}
		else{
			//for(int i=0;i <n; i++) cout << i+1 << " " << vis[i] << endl;
			vector<int> vis2(n);
			function<int(int, int)> dfs2 = [&](int x, int p){
				vis2[x] = 1;
				int ret = 1;
				for(auto u : g[x]) if(u!=p and vis[u]!=2){
					ret += dfs2(u, x);
				}
				return ret;
			};
			ans = n*(n-1);
			ll cic = 0;
			for(int i=0;i <n; i++) if(vis[i]==2) cic++;

			for(int i=0;i <n; i++) if(vis[i]==2){
				if(g[i].size()==2) ans += n-1;
				else{
					ll d=0;
					for(auto u : g[i]) if(vis[u]==1) d += dfs2(u, i);
					ans += d*(n-d-1);
					ans += (n-d-1);
				}
			}
			ans/=2;
			cout << ans << endl;
		}
		
	}
	
	
	
	exit(0);
}
