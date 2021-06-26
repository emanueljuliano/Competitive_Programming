#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 2e5+10;


ll d[MAX][2][2];
vector<ii> g[MAX]; // {vizinho, peso}

int n;

void dijkstra(int x) {
	for(int i=0; i < n; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++)  d[i][j][k] = LINF;
	d[x][0][0] = 0;
	priority_queue<pair<pair<ll, ii>,ll>> pq;
	pq.push({{0, {0, 0}},x});

	while(pq.size()) {
		auto [T, u] = pq.top(); pq.pop();
		ll ndist = -T.f, mn=T.s.f, mx=T.s.s;
		//cout << ndist << " " << u << " " << mn << " " << mx << endl;
		if(ndist > d[u][mn][mx]) continue;
		for(auto [idx,w] : g[u]) {
			ll dist = d[idx][mn][mx];
			if(dist > ndist + w) {
				dist = d[idx][mn][mx] = ndist + w;
				pq.push({{-dist, {mn, mx}}, idx});
			}
			dist = d[idx][mn][1];
			if(!mx and dist > ndist) {
				dist = d[idx][mn][1] = ndist;
				pq.push({{-dist, {mn, 1}}, idx});
			}	
			dist = d[idx][1][mx];
			if(!mn and dist > ndist + 2LL*w) {
				dist = d[idx][1][mx] = ndist + 2*w;
				pq.push({{-dist, {1, mx}}, idx});
			}
			dist = d[idx][1][1];
			if(!mn and !mx and dist > ndist + w) {
				dist = d[idx][1][1] = ndist + w;
				pq.push({{-dist, {1, 1}}, idx});
			}	
		}
	}
}

int main(){ _
	int m; cin >> n >> m;
	for(int i=0;i <m; i++){
		int a, b, c; cin >> a >> b >> c; a--, b--;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	dijkstra(0);

	for(int i=1; i<n; i++) cout << d[i][1][1] << " ";

	cout << endl;
	
	
	exit(0);
}
