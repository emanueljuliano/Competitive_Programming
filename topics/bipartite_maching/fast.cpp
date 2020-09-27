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
const int MAX = 5e4+10;
const int MAX2 = 5e4+10;

int n, m;
vector<vector<int>> g(MAX);
int vis[MAX2], mb[MAX2], ma[MAX];

bool dfs(int v){
	for(auto u : g[v]) if(!vis[u]){
		vis[u]=1;
		if(mb[u]==-1 or dfs(mb[u])){
			ma[v]=u, mb[u] = v;
			return true;
		}
	}
	return false;
}

int kuhn(){
	int ret = 0;
	for(int j=0; j<m; j++) mb[j] = -1;
	for(int i=0; i<n; i++) ma[i] = -1;

	bool aux = true;
	while(aux){
		for(int j=0; j<m; j++) vis[j] = 0;
		aux = false;
		for(int i=0;i <n; i++) if(ma[i]==-1){
			if(dfs(i)) ret++, aux=true;
		}
	}
	return ret;
}

int main(){ _
	int p; cin >> n >> m >> p;
	for(int i=0;i <p; i++){
		int a, b; cin >> a >> b; a--; b--;
		g[a].pb(b);
	}
	int ans = kuhn();
	cout << ans << endl;


	exit(0);
}
