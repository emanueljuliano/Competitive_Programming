#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back


typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10;
int dist[MAX], dg[MAX];
int n;

vector<vector<int>> g(MAX);
void bfs(int x){
	for(int i=0;i <MAX; i++) dist[i] = -1;
	queue<int> q;
	q.push(x);
	dist[x] = 0;
	while(!q.empty()){
		x =q.front();
		q.pop();
		for(int i=0; i<g[x].size(); i++){
			int u = g[x][i];
			if(dist[u]==-1){
				q.push(u);
				dist[u] = dist[x]+1;
			}
		}
	}
}

int dist2[MAX];
int dfs(int x){
	dist2[x] = 0;
	for(int i=0;i <g[x].size(); i++){
		int u = g[x][i];
		if(dist2[u]==-1){
			dist2[x] += dfs(u) + 1;
		}
	}
	return dist2[x];
}

int main(){ _
	int  k; cin >> n >> k;
	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b;
		a--, b--;
		dg[a]++;
		dg[b]++;
		g[a].pb(b);
		g[b].pb(a);
	}
	bfs(0);
	for(int i=0;i <MAX; i++) dist2[i] = -1;
	dfs(0);
	vector<pair<ll, int>> v;
	for(int i=0;i <n; i++){
		//cout << i<< " " << dist[i] <<"  " << dist2[i] << endl;
		ll d = dist[i] - dist2[i];
		v.pb({d, i});
	}
	sort(v.begin(), v.end(), greater<>());
	ll ans = 0;
	for(int i=0;i <k; i++){
		ans += v[i].f;
	}
	cout << ans << endl;
	exit(0);
}
