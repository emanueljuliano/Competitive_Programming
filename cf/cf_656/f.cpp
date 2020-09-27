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


int main(){ _
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		vector<vector<int>> g(n);
		for(int i=0;i <n-1; i++){
			int a, b; cin >> a >> b; a--, b--;
			g[a].pb(b);
			g[b].pb(a);
		}

		vector<int> vis(n), val(n);
		queue<int> q;
		for(int i=0;i <n; i++){
			if(g[i].size()==1) q.push(i);
		}
		
		int ans = 0;
		while(!q.empty()){
			int x = q.front(); q.pop();
			vis[x] = 1;
		//	cout << x << " " << val[x] << endl;
			for(auto u : g[x]){
				if(vis[u]) continue;
				val[u]++;
				if(val[u]%k==0){
					ans++;
					if(val[u]==g[u].size()-1)q.push(u);
				}	
			}
		}
		cout << ans << endl;
	
	}
	
	
	
	exit(0);
}
