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

const int MAX = 1e5+10;
vector<vector<int>> g(MAX), vis(MAX);

int dfs(int v, int pos){
	if(pos == g[v].size()) return 0;
	int &ret = vis[v][pos];
	if(ret) return ret;
	
	int u = g[v][pos];
	int new_pos = upper_bound(g[u].begin(), g[u].end(), v) - g[u].begin();
	return ret = max(1+dfs(u, new_pos), dfs(v, pos+1));
}

int main(){ _
	int n, m; cin >> n >> m;	
	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
		vis[a].pb(0);
		vis[b].pb(0);
	}

	for(int i=1;i <=n; i++)
		sort(g[i].begin(), g[i].end());
	
	for(int i=1; i<=n; i++)
		cout << dfs(i, 0)+1 << " ";
	cout << endl;
	
	
	exit(0);
}
