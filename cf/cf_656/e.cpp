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
		int n, m; cin >> n >> m;
		vector<int> dg(n);
		vector<vector<ii>> g(n);
		vector<ii> ans;
		for(int i=0;i<m; i++){
			int x, a, b; cin >> x >> a >> b; a--; b--;
			if(x) dg[b]++;//ans.pb({a, b});
			g[a].pb({b, x});
			if(!x) g[b].pb({a, x});
		}
		queue<int> q;
		vector<int> vis(n);
		for(int i=0;i <n; i++) if(dg[i]==0) q.push(i);
		while(!q.empty()){
			int x = q.front(); q.pop();
			vis[x] = 1;
			for(auto p : g[x]){
				int d = p.s, u = p.f;
			//	cout << d << " " << u << " " << vis[u] << endl;
				if(vis[u]) continue;
				
				ans.pb({x, u});
				if(d==1){
					dg[u]--;
					if(dg[u]==0) q.push(u);
				}
			}
		}
		bool show = true;
		for(auto x : vis) show &=x;
		if(show){
			cout << "YES" << endl;
			for(auto p : ans) cout << p.f+1 << " " << p.s+1 << endl;
		}
		else cout << "NO" <<endl;
	
	}
	
	
	
	exit(0);
}
