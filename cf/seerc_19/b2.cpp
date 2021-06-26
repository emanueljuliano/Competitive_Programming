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

const int MAX = 205;
ll dp[MAX][MAX][MAX];
int x[MAX], t[MAX], y[MAX], r[MAX];
int n, S1, S2;

ll solve(int i, int s1, int s2){
	if(i==n and s1<=0 and s2<=0) return 0;
	if(i==n) return LINF;
	ll &ret = dp[i][max(s1, 0)][max(s2, 0)];
	if(ret != -1) return ret;
	
	ret = solve(i+1, s1, s2);
	ret = min(ret, solve(i+1, s1, s2-y[i]) + r[i]);
	if(s1>0){
		int res = max(0, x[i]-s1);
		ret = min(ret, solve(i+1, s1-x[i], s2-res) + t[i]);
	}
	return ret;
}

int main(){ _
	cin >> n >> S1 >> S2;
	for(int i=0;i <n; i++){
		cin >> x[i] >> t[i] >> y[i] >> r[i];
	}	
	memset(dp, -1, sizeof dp);

	ll ans = solve(0, S1, S2);
	if(ans>=LINF) cout << -1 << endl;
	else cout << ans << endl;
	
	exit(0);
}
