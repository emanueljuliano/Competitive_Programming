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
const int MAX = 2e5 + 10;
vector<vector<int>> g(MAX);
int dist[MAX][3];
int n;

void bfs(int x, int f){
	for(int i=0;i <n; i++) dist[i][f] = -1;
	queue<int> q;
	q.push(x);
	dist[x][f] = 0;
	while(!q.empty()){
		x = q.front(); q.pop();
		for(int i=0;i <g[x].size(); i++){
			int u = g[x][i];
			if(dist[u][f]==-1){
				dist[u][f] = dist[x][f]+1;
				q.push(u);
			}
		}
	}
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int m, a, b, c; cin >> n >> m>> a >> b >> c;
		vector<int> p;
		for(int i=0;i <n; i++) g[i].clear();
		for(int i=0;i <m; i++){int x; cin >> x; p.pb(x);}
		for(int i=0;i <m; i++){
			int x, y; cin >> x >> y;
			x--; y--;
			g[x].pb(y);
			g[y].pb(x);
		}
		a--, b--, c--;
		bfs(a, 0); bfs(b, 1); bfs(c, 2);
		sort(p.begin(), p.end());
		vector<ll> soma;
		soma.pb(0);
		for(int i=0; i<m; i++){
			soma.pb(soma[i]+p[i]);
		}
		ll ans = LINF;
		for(int i=0;i <n; i++){
			int x, y, z;
			x = dist[i][0];
			y = dist[i][1];
			z = dist[i][2];
			// y = 2;
		//	cout << i <<"  x= " << x << " y= " << y << " z= " << z << endl;
			if(x+y+z<=m) ans = min(ans, soma[x+y+z] + soma[y]);
		}

		cout << ans << endl;
	}
	
	
	
	exit(0);
}
