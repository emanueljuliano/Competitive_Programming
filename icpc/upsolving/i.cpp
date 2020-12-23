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

const int MOD = 1e9+7;
const int MAX = 1e5+10;
ll dp[MAX][2];
ll pref[MAX], suf[MAX];
vector<int> g[MAX];
int solve(int i, bool know){
	ll &res = dp[i][know];
	if(res != -1) return res;
	if(!g[i].size()) return res = 1;
	res = 0;
	int dg = g[i].size();
	for(auto u : g[i]) solve(u, 1), solve(u, 0);
	pref[0] = dp[g[i][0]][1];
	for(int j=1; j<dg; j++) pref[j] = pref[j-1]*dp[g[i][j]][1]%MOD;
	suf[dg-1] = dp[g[i][dg-1]][1];
	for(int j=dg-2; j>=0; j--) suf[j] = suf[j+1]*dp[g[i][j]][1]%MOD;

	ll at = 1;
	if(know){
		for(auto u : g[i]) at = at*dp[u][1]%MOD;
		res = (res+at)%MOD, at = 1;
	}
	for(int j=0; j<dg; j++){
		at = dp[g[i][j]][0];
		if(j) at = at*pref[j-1]%MOD;
		if(j<dg-1) at = at*suf[j+1]%MOD;
		res = (res+at)%MOD;
	}
	return res;
}

int main(){ _
	int n; cin >> n;
	memset(dp, -1, sizeof dp);
	for(int i=0;i <n-1; i++){
		int a; cin >> a; a--;
		g[a].pb(i+1);
	}
	cout << solve(0, 1) << endl;
	
	
	
	exit(0);
}
