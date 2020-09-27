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

vector<int> vis;
vector<vector<int>> g((int)2e5+10);
bool dfs(int x){
	bool ret = true;
	for(int i=0;i <g[x].size(); i++){
		int u = g[x][i];
		if(vis[u]==1) return false;
		if(vis[u]==2) continue;
		vis[u] = 1;
		ret &= dfs(u);
	}
	vis[x] = 2;
	return ret;
}

int main(){ _
	int n, m; cin >> n >> m;
	vector<int> dg(n, 0);
	vis = dg;
	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b; a--; b--;
		g[a].pb(b);
		dg[b]++;
	}
	bool ans = true;
	for(int i=0;i <n; i++){
		if(!vis[i]){
			vis[i] = 1;
			ans&=dfs(i);
			vis[i] = 2;
		}
	}
	int val = 0;
	string out;
	if(!ans) cout << -1 << endl;
	else{
		for(int i=0;i <n; i++){
			if(dg[i]==0) out+="A", val++;
			else out+="E";
		}
		cout << val << endl;
		cout << out << endl;
	}

	
	
	
	exit(0);
}
