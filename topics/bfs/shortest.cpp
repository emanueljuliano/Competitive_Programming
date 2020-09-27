#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef pair<int, int> ii;
typedef long long ll;

const int MAX = 1e5;
const int INF = 0x3f3f3f3f;

vector<vector<int>> v2(100);
vector<vector<int>> g(MAX);
int n;

int bfs(int x){
	queue<ii> q;
	vector<int> dis(n, 0);
	q.push({x, -1}), dis[x] = 1;
	
	while(q.size()){
		auto at = q.front(); q.pop();
		int v = at.f, pai=at.s;
		for(auto u : g[v]){
			if(!dis[u]) dis[u] = dis[v]+1, q.push({u, v});
			else if(u!=pai) return dis[u]+dis[v]-1;
		}
	}
	return INF;
}

int main(){ _
	cin >> n;
	int ans = INF;
	vector<ll> v;
	for(int i=0;i <n; i++){
		ll a; cin >> a;
		if(a==0) {i--, n--; continue;}
		v.pb(a);
		for(ll j=0;j <62; j++) if(a&(1LL<<j)) v2[j].pb(i);
	}

	for(auto u:v2) if(u.size()>=3) return cout << 3 << endl, 0;

	for(int i=0;i <n; i++) for(int j=i+1; j<n; j++){
		if(v[i]&v[j]) g[i].pb(j), g[j].pb(i);
	}	
	
	for(int i=0;i <n; i++) ans = min(ans, bfs(i)); 

	if(ans!=INF) cout << ans << endl;
	else cout << -1 << endl;

	exit(0);
}
