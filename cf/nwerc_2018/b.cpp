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

const int MAX = 4e5+10;

vector<int> v, dp;
vector<vector<int>> g(MAX);
int maxi = 0;

int dfs(int x){
	int ret = -1;
	for(auto u : g[x]){
		if(dp[u]==-1) ret = max(ret, dfs(u));
		else ret = max(ret, dp[u]);
	}

	return dp[x] = ret+1;
}

int main(){ _
		
	int n; cin >> n;
	vector<int> dg(n);
	dp.resize(n);

	for(int i=0; i<n; i++){
		int x, m; cin >> x >> m;
		v.pb(x); dp[i] = -1;
		
		for(int j=0; j<m; j++){
			int a; cin >> a; a--;
			g[i].pb(a);
			dg[a]++;
		}
	}

	priority_queue<ii> pq;
	for(int i=0;i <n; i++){
		if(dp[i]==-1) dfs(i);
		if(dg[i]==0) pq.push({-v[i], i});
	}
	
	int tot = n;
	int ans = 0;
	while(!pq.empty()){
		auto at = pq.top(); 
		pq.pop();
		tot--;
		int tam = -at.f, u=at.s;
		ans = max(ans, tam+tot);
		for(auto x : g[u]){
			dg[x]--;
			if(dg[x]==0) pq.push({-v[x], x});
		}
	}
	cout << ans << endl;
	
	exit(0);
}
