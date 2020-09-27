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

int forb[2020][2020];

const int MOD = 1e9+7;

map<ii, int> dp;
int n, e, k;

ll solve(int a, int mask){
//	cout << a << " " << mask << endl;
	if(a==n-1){
		int falta = 0;
		int ini = max(0, a-e);
		for(int i=ini; i<min(a+e+1, n); i++){
			if(mask & 1<<(i-ini)) continue;
			falta++;
		}
		if(falta!=1) return 0;
		else return 1;
	}
	if(a-e>=0 and !(mask&1)){
		if(forb[a][a-e]) return 0;
		return solve(a+1, mask>>1);
	}

	ii at = {a, mask};
	if(dp.count(at)) return dp[at];

	ll ret = 0;
	int ini = max(0, a-e);
	for(int i=max(0, a-e); i<min(a+e+1, n); i++){
		if(forb[a][i]) continue;
		if(mask & 1<<(i-ini)) continue;
		int nmask = mask|(1<<(i-ini));
//		cout << a << " "<< i << " " << nmask << endl;
		if(a-e>=0) nmask = nmask>>1;
		ret = (ret + solve(a+1, nmask))%MOD;
	}
	return dp[at] = ret;
}

int main(){ _
	memset(forb, 0, sizeof forb);
	cin >> n >> e >> k;
	for(int i=0;i <k; i++){
		int a, b; cin >> a >> b; a--, b--;
		forb[a][b] = 1;
	}

	ll ans = 0;
	
	ans = solve(0, 0);
	cout << ans << endl;
	
	exit(0);
}
