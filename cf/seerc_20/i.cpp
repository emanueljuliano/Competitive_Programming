#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MOD = 1e9 + 7;

int main(){ _
	// the main observation is that between (1, ..., 2) and (2, ..., 1) 
	// all values must be sorted in decreasing order
	// dp[x] stores the number of ways of dividing the values at [n, ..., x]
	// such that x is between (1, .., 2) and x+1 between (2, .., 1)
	
	int n; cin >> n;		
	if (n <= 2) return cout << n << endl, 0;
	
	vector<ll> dp(n+3, 0);
	dp[3] = 1;
	ll ans = 1;

	for (int i = 4; i<=n; i++) {
		dp[i] = (dp[i] + 1) % MOD;
		ans = (ans + dp[i])%MOD;
		for (int j=i-1; j<=n; j+=i-1) {
			for (int q = max(i+1, j); q <= j+2; q++)
				dp[q] = (dp[q] + dp[i])%MOD;
		}
	}
	ans = 2ll*n*ans % MOD;

	cout << ans << endl;
	
	exit(0);
}
