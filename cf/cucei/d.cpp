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

const int MOD = 1e9+7;
const int MAX = 1e5+7;
const int MNG = 8;
const int CONG = 5;

vector<ii>g[MAX];
int dp[MAX][MNG][CONG];

int pth(int u, int v){
	int ret = 0;
	while(ret<g[u].size() and g[u][ret].f!=v) ret++;
	return ret;
}

void solve(int v, int p){
	if(dp[v][p][0] != -1) return; 
	vector<int> ng, png, wei;
	for(int i=0;i <g[v].size(); i++){
		ii u = g[v][i];
		if(i!=p) ng.pb(u.f), png.pb(pth(u.f, v)), wei.pb(u.s);
	}
	for(int i=0;i <ng.size(); i++) solve(ng[i], png[i]);

	vector<ll> ret(CONG);
	ret[0] = 1;
	for(int j=0; j<CONG; j++) 
		if(ng.size()) ret[j] += dp[ng[0]][png[0]][(j-wei[0]+CONG)%CONG];
	for(int i=1;i <ng.size(); i++){
		vector<ll> up(CONG);
		for(int j=0;j <CONG; j++){
			for(int k=0; k<CONG; k++)
				up[j] = up[j] + ret[k]*dp[ng[i]][png[i]][(j-wei[i]-k+2*CONG)%CONG],
				up[j] %= MOD;
		}
		for(int j=0; j<CONG; j++) ret[j] = (ret[j] + up[j])%MOD;
	}
	for(int j=0; j<CONG; j++) dp[v][p][j] = ret[j];
}

int main(){ _
	int n; cin >> n;
	for(int i=0;i <n-1; i++){
		int a, b; ll c; cin >> a >> b >> c; a--, b--, c%=CONG;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}

	for(int i=0;i <MAX; i++) for(int j=0;j <MNG; j++) for(int k=0; k<CONG; k++)
		dp[i][j][k] = -1;

	int q; cin >> q;
	while(q--){
		int a; cin >> a; a--;
		solve(a, g[a].size());
		cout << dp[a][g[a].size()][0] << endl;
	}

	exit(0);
}
