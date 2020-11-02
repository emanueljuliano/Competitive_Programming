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

const int MAX = 1e3+10;
int d[MAX];
vector<pair<int,int>> g[MAX]; // {vizinho, peso}

int n;

void dijkstra(int x) {
	for(int i=0; i < n; i++) d[i] = INF;
	d[x] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push({0,x});

	while(pq.size()) {
		auto [ndist,u] = pq.top(); pq.pop();
		if(-ndist > d[u]) continue;

		for(auto [idx,w] : g[u]) if(d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
			pq.push({-d[idx], idx});
		}
	}
}

int main(){ _
	
	int m, k; cin >> n >> m >> k;
	vector<pair<ii, int>> eg;
	for(int i=0;i <m; i++){
		int a, b, c; cin >> a >> b >> c; a--, b--;
		eg.pb({{a, b}, c});
	}
	vector<ii> w(k);
	for(auto &i:w) cin >> i.f >> i.s;

	int ans=INF;
	for(int i=0;i <m; i++){
		int at = 0;
		for(int j=0; j<n; j++) g[j].clear();
		for(int j=0; j<m; j++){
			auto e = eg[j];
			if(i==j) g[e.f.f].pb({e.f.s, 0}), g[e.f.s].pb({e.f.f, 0});
			else g[e.f.f].pb({e.f.s, e.s}), g[e.f.s].pb({e.f.f, e.s});
		}
		for(auto [a, b] : w) dijkstra(a-1), at+=d[b-1];
		
		ans = min(ans, at);
	}
	cout << ans << endl;
	
	exit(0);
}
