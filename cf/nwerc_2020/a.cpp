#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e4+10;
ll dp[MAX];

int main(){ _
	memset(dp, INF, sizeof dp);
	int n, q; cin >> n >> q;
	vector<ll> v(n);
	for (auto &i : v) cin >> i;

	dp[0] = 0;
	for (int i=1; i<=n; i++) dp[i] = v[i-1];
	for (int i=1; i<MAX; i++) {
		for (int j=1; j<=n and i+j<MAX; j++) {
			if (i < n and i+j<=n) continue;
			dp[i+j] = min(dp[i+j], dp[i] + v[j-1]);
		}
	}
	
	while (q--) {
		int k; cin >> k;
		ll ans = LINF, sz = 0;
		for (int i=1; i<=n; i++) {
			sz = 0;
			if (k >= MAX) sz = (k - MAX + i) / (i);
			ans = min(ans, sz * v[i-1] + dp[k - sz * i]);
		}
		cout << ans << endl;
	}
	
	exit(0);
}
