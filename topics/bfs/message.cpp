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

const int MAX = 1e5+10;

vector<vector<int>> g(MAX);
vector<bool> vis(MAX);
vector<int> pai(MAX);

void bfs(int s){
	queue<int> q;
	q.push(s); vis[s]=1;

	pai[s] = s;
	while(!q.empty()){
		int v = q.front(); q.pop();

		for(auto u : g[v]) if(!vis[u]){
			q.push(u), vis[u]=1;
			pai[u] = v;
		}
	}
}

vector<int> path(int v){
	vector<int> ret;
	if(!vis[v]) return ret;

	ret.pb(v);
	while(pai[v]!=v){ // v != s
		v = pai[v];
		ret.pb(v);
	}

	// 1 2 3 4
	// 4 3 2 1
	reverse(ret.begin(), ret.end());

	return ret;
}

int main(){ _
	int n, m; cin >> n >> m;

	
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].pb(b), g[b].pb(a);
	}
	
	bfs(0);
	vector<int> ans = path(n-1);

	if(ans.size()==0) cout << "IMPOSSIBLE" << endl;
	else{
		cout << ans.size() << endl;
		for(auto u : ans) cout << u+1 << " ";
		cout << endl;
	}

	exit(0);
}
