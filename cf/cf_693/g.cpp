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
			g[a].pb(b);
		}

		vector<int> d(n, -1);
		queue<int> q;
		q.push(0);
		d[0] = 0;
		while(!q.empty()){
			int x = q.front(); q.pop();
			for(auto u : g[x]) if(d[u]==-1) d[u]=d[x]+1, q.push(u);
		}
		for(int i=0;i <n; i++){
			//cout<< i+1 << " dist "<< d[i] << endl;
		}	
		vector ans(n, vector<int>(2, -1));
		function<int(int, bool)> dfs = [&](int x, bool used){
			int &ret = ans[x][used];
			if(ret != -1) return ret;
			ret = d[x];
			for(auto u : g[x]){
				if(d[u]<=d[x] and !used){
					ret = min(ret, dfs(u, 1));
				}
				if(d[u]>d[x]) ret = min(ret, dfs(u, used));
			}
			return ret;
		};	
		for(int i=0;i <n; i++){
			cout << dfs(i, 0) << " ";
		}
		cout << endl;
	}
	
	
	
	exit(0);
}
