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

const int MOD = 998244353;
int inv2 = (MOD+1)/2;
int n;
const int MAX = 2e5+10;
ll dp[MAX];
//dp[i] = dp[i-1] + dp[i-3] + dp[i-5] +
// == dp[i-1] + dp[i-2]
int main(){ _
	ll ans = 0;
	
	cin >> n;
	dp[1] = 1, dp[2] = 1;

	for(int i=3; i<=n; i++){
		dp[i] = (dp[i-1]+dp[i-2])%MOD;
	}
	ll deno = 1;
	for(int i=0; i<n; i++) deno = (deno*inv2)%MOD;
	cout << dp[n]*deno%MOD << endl;

	
	exit(0);
}
