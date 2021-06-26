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

const int MAX = 1e5+10;
int d[MAX];
vector<pair<int,int>> g[MAX]; // {vizinho, peso}

int n;

void dijkstra(vector<int> v) {
	for(int i=0; i < n; i++) d[i] = INF;
	queue<pair<int,int>> pq;
	for(auto u : v) d[u]=0, pq.push({0, u});

	while(pq.size()) {
		auto [ndist,u] = pq.front(); pq.pop();
		if(-ndist > d[u]) continue;

		for(auto [idx,w] : g[u]) if(d[idx] > d[u] + w) {
			d[idx] = d[u] + w;
			pq.push({-d[idx], idx});
		}
	}
}

int main(){ _
	int m, k, s; cin >> n >> m >> k >> s;
	vector<int> A(n);
	for(auto &i : A) cin >> i;
	
	for(int i=0;i <m; i++){
		int a, b; cin>> a >> b;
		a--, b--;
		g[a].pb({b, 1});
		g[b].pb({a, 1});
	}
	
	vector<vector<int>> v(n);

	for(int i=1; i<=k; i++){
		vector<int> w;
		for(int j=0; j<n; j++) if(A[j]==i) w.pb(j);
		dijkstra(w);
		for(int j=0; j<n; j++) v[j].pb(d[j]);
	}

	for(int i=0;i <n; i++){
		sort(v[i].begin(), v[i].end());

		int tot = 0;
		for(int j=0; j<s; j++) tot+=v[i][j];
		cout << tot << " ";
	}
	cout << endl;

	
	
	
	exit(0);
}
