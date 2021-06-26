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

const int MAX = 1e5+10;
int res[MAX], num[MAX], ans[MAX];
map<ii, int> up;

int dfs(int i, int p){
	res[i] = true;	
	for(auto u : g[i]) if(u!=p){
		num[i] += dfs(u, i);
	}
	return res[i] = !num[i];
}

void dfs2(int i, int p){
	ans[i] = res[i] and !up[{i, p}];
	if(up[{i, p}] or num[i]>=2){
		for(auto u : g[i]) up[{u, i}] = false;
	}
	else if(num[i]==0){
		for(auto u : g[i]) up[{u, i}] = true;
	}
	else{
		for(auto u : g[i]) up[{u, i}] = res[u];
	}
	for(auto u : g[i]) if(u!=p){
		dfs2(u, i);
	}
}

int main(){ _
	int n; cin >> n;
	g.resize(n);
	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].pb(b), g[b].pb(a);
	}
	up[{0, 0}] = 0;
	ans[0] = dfs(0, 0);
	dfs2(0, 0);

	bool alice = false;
	for(int i=0;i <n; i++) if(ans[i]==1) alice = true;
	
	if(alice) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	
	exit(0);
}
