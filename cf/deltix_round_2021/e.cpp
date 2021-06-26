#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int MOD = 1e9 + 7;
const int MAX = 1e5+10;

ll inv(ll a, ll b=MOD) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}

ll fat[MAX];
ll choose(ll a, ll b) {
	if (a < b) return 0;
	return fat[a]*inv(fat[b])%MOD*inv(fat[a-b])%MOD;
}

int main(){ _
	// A valid state is a state where there is no segment with at least two lights on
	// Let p_i the the probability of a state with i lights turned on be a valid state
	// The expected number of lights turned on after the device finishes
	// is equal to 1 + sum 1<=i<=n of p_i 
	// The +1 arrives from the fact that we can always turn another light on,
	// then either the device ends, or we continue on a valid state

	fat[0] = 1;
	for (ll i = 1; i < MAX; i++) fat[i] = i * fat[i-1] % MOD;
	
	int t; cin >> t;
	while (t--) {
		ll n, k; cin >> n >> k;

		ll ans = 0;
		for (ll i = 1; i<=n; i++) {
			// Number of states with i lights on
			ll den = choose(n, i); 
			
			// For a state to be valid, we need (i-1)*(k-1) lights off
			// those lights will be placed between the i lights on
			// at the remaining positions, we place the i lights on
			ll valid = choose(n - (k-1)*(i-1), i);

			ans = (ans + valid*inv(den)%MOD)%MOD;
		}
		cout << (ans+1)%MOD << endl;
	}	
	
	exit(0);
}
