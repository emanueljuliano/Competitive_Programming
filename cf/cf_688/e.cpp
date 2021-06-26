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

const int MAX = 2e5+10;
vector<int> g[MAX];
int dp[MAX];

int dfs(int x, int p){
	vector<int> ng;
	for(auto u : g[x]) if(u!=p) ng.pb(u);
	if(ng.size()==0){
		return dp[x] = 0;
	}
	else if(ng.size()==1){
		return dp[x] = 1+dfs(ng[0], x);
	}
	else{
		vector<int> val;
		for(auto u : ng) val.pb(dfs(u, x));
		sort(val.begin(), val.end(), greater<>());
		if(x==p) sort(val.begin(), val.end());
		int maxi = 0;
		for(int i=0; i<val.size()-1; i++) maxi = max(maxi, val[i]+2);
		maxi = max(maxi, val.back()+1);
		dp[x] = maxi;
		return val.back()+1;
	}
}


int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i=0;i <=n; i++) g[i].clear();
		for(int i=0;i <n-1; i++){
			int a, b; cin >> a >> b; a--, b--;
			g[a].pb(b), g[b].pb(a);
		}
		dfs(0, 0);
		int ans = 0;
		for(int i=0;i <n; i++) ans=max(ans, dp[i]);
		//for(int i=0;i <n; i++) cout << i+1 << " " << dp[i] << endl;
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
