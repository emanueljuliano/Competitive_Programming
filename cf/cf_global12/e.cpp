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

const int MAX = 220;

vector<vector<int>> g(MAX);
int n;
int d[MAX][MAX];

bool floyd_warshall() {
	for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	for (int i = 0; i < n; i++)
		if (d[i][i] < 0) return 1;

	return 0;
}

int main(){ _
	int  m; cin >> n >> m;

	memset(d, INF, sizeof d);
	for(int i=0;i <n; i++) d[i][i] = 0;
	for(int i=0;i <m; i++){
		int a, b, c; cin >> a >> b >> c; a--, b--;
		if(!c) d[a][b] = 1, d[b][a] = 1;
		else d[a][b] = 1, d[b][a] = -1;
		g[a].pb(b), g[b].pb(a);
	}
	
	vector<int> c(n), vis(n);
	bool bp = true;
	function<void(int)> dfs = [&](int v){
		for(auto u : g[v]){
			if(!vis[u]) vis[u]=1, c[u]=!c[v], dfs(u);
			else if(c[u]==c[v]) bp = false;
		}
	};
	vis[0] = 1, dfs(0);
	if(!bp) return cout << "NO" << endl, 0;
	if(floyd_warshall()) return cout << "NO" << endl, 0;

	int maxi=0, a=0;
	for(int i=0;i <n; i++) for(int j=0; j<n; j++)
		if(d[i][j] >maxi) maxi = d[i][j], a = i;

	cout << "YES" << endl;
	cout << maxi << endl;
	for(int i=0;i <n; i++) cout << d[a][i] << " ";
	cout << endl;

	exit(0);
}
