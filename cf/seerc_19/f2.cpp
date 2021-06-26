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

vector<vector<int>> g;

const int MAX = 1e3+10;
int res[MAX];
int ans[MAX][MAX]; 

int dfs(int x, int i, int p){
	res[i] = true;	
	for(auto u : g[i]) if(u!=p){
		res[i] &= !dfs(u, i);
	}
	return ans[x][i] = res[i];
}

int main(){ _
	int n; cin >> n;
	g.resize(n);
	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].pb(b), g[b].pb(a);
	}
	int root = 0;
	for(int i=0; i<n; i++) if(g[i].size()==1) root = i;
	ans[root] = dfs(root, -1);
	for(auto u : g[root])
		dfs2(u, root);

	bool alice = false;
	for(int i=0;i <n; i++) if(ans[i]==1) alice = true;
	
	if(alice) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	
	exit(0);
}
