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

const int MAX = 3e5+10;
ll d[MAX];
int vd[MAX];
vector<pair<int,ll>> g[MAX]; // {vizinho, peso}

int n;
 
void dijkstra(int x) {
	for(int i=0; i < n; i++) d[i] = LINF;
	d[x] = 0;
	priority_queue<pair<ll,ll>> pq;
	pq.push({0,x});
 
	while(pq.size()) {
		auto [ndist,u] = pq.top(); pq.pop();
		if(vd[u]) continue;
 		vd[u] = 1;

		for(auto [idx,w] : g[u]) if(d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
			pq.push({-d[idx], idx});
		}
	}
}

int main(){ _
	int m, k; cin >> n >> m >> k;

	map<ii, int> mp;
	int pt = 0;
	for(int i=0;i <m; i++){
		int a, b, c; cin >> a >> b >> c; a--, b--;
		ii pa = {a, b};
		ii pb = {b, a};
		mp[pa]=pt;
		mp[pb]=pt++;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}

	dijkstra(0);

	vector<int> vis(m), vvis(n); 
	queue<int> q;
	q.push(0);
	vvis[0] = true;
	int ans = 0;
	while(!q.empty()){
		int x = q.front(); q.pop();

		for(auto [a, y] : g[x]){
			if(ans<k and !vvis[a] and !vis[mp[{a, x}]] and y+d[x]==d[a]){
				vvis[a] = 1;
				ii p = {x, a};
				vis[mp[p]] = true;
				ans++;
				q.push(a);
			}
		}
	}

	cout << ans << endl;
	for(int i=0;i <m; i++) if(vis[i]) cout << i+1 << " ";
	cout << endl;


	
	exit(0);
}
