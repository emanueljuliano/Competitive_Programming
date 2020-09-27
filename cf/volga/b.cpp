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
const int MAX = 2e5+10;
int cor[MAX];
int vis[MAX];
int inter[MAX];
vector<vector<int>> g(MAX);
int dfs(int x, int pai){
	int s = 0;
	for(int i=0;i <g[x].size(); i++){
		int u = g[x][i];
		if(u==pai) continue;
		s+= dfs(u, x);
	}
	if(s==g[x].size()-1 and !cor[x]) inter[x]=1;
	return s>0 or cor[x];
}


int main(){ _
	memset(cor, 0, sizeof(cor));
	memset(vis, 0, sizeof(vis));
	memset(inter, 0, sizeof(inter));
	int n, k; cin >> n >> k;
	int cat;
	for(int i=0;i <k; i++){
		int a; cin >> a; a--;
		cat = a;
		cor[a]++;
	}
	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b; a--; b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(cat, -1);
	vector<int> ans;
	for(int i=0;i <n; i++){
		if(inter[i])ans.pb(i+1);
	}
	cout << ans.size() << endl;
	for(auto k : ans) cout << k << " ";
	cout << endl;
	
	
	exit(0);
}
