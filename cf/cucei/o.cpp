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

int visk[110], vis[(int)1e5+10];
int dist[(int)1e5+10];
vector<vector<int>> v;
int k;
vector<vector<int>> g((int)1e5+10);

void bfs(int a){
	memset(dist, -1, sizeof(dist));
	queue<int> q; q.push(a); dist[a]=0, vis[a]=1;
	while(!q.empty()){
		a = q.front(); q.pop();
		if(!visk[a%k]){
			for(auto u : v[a%k]) if(!vis[u]) q.push(u), vis[u]=1, dist[u]=dist[a]+1;
			visk[a%k] = 1;
		}
		for(auto u : g[a]) if(!vis[u]) q.push(u), vis[u]=1, dist[u] = dist[a]+1;
	}
}

int main(){ _
	int n, m; cin >> n >> m >> k;
	v.resize(k);
	for(int i=0;i <n; i++) v[i%k].pb(i);
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].pb(b);
	}
	
	int a, b; cin >> a >> b; a--, b--;
	bfs(a);
	cout << dist[b] << endl;

	exit(0);
}
