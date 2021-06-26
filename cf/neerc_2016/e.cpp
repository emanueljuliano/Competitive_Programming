#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MOD = 1e9+7;
const int MAX = 3e5+10;

ll inv[MAX], fat[MAX], i_fat[MAX];

ll choose(int n, int m) {
	if (n < m or n < 0) return 0;
	if (n == m) return 1;
	ll ret = fat[n] * i_fat[m] % MOD * i_fat[n-m] % MOD;
	return ret;
}

ll inverse(ll a, ll b) {
	return a > 1 ? b - inverse(b%a, a)*b/a : 1;
}

int main(){ _
	
	fat[0] = 1, i_fat[0] = 1;
	inv[1] = 1, fat[1] = 1, i_fat[1] = 1;
	for (int i = 2; i < MAX; i++) inv[i] = MOD - MOD/i*inv[MOD%i]%MOD;
	for (int i = 2; i < MAX; i++) fat[i] = i*fat[i-1]%MOD;
	for (int i = 2; i < MAX; i++) i_fat[i] = inv[i]*i_fat[i-1]%MOD;

	int k; cin >> k;
	int n = 1<<k;
	vector<ll> a(n);
	for (auto &i : a) cin >> i;
	
	ll ans = 0;
	for (int m=k-1; m>=0; m--) {
		// number of ways of j be at round m+1
		vector<ll> f(n);
		for (int j=0; j<n; j++) {
			f[j] = choose(n - j - 1, (1<<m) - 1) * fat[1<<m] % MOD;
		}

		// number of ways of i<j be at round m+1 with j
		vector<ll> g(n);
		for (int i=0; i<n; i++) {
			g[i] = choose(n - i - 1 - (1<<m), (1<<m) - 1) * fat[1<<m] % MOD;
		}

		// ans += sum for every i<j of a[i]*a[j]*f[i]*g[j]
		// pref[i] = sum for every i of a[i]*g[i]
		// ans += sum for every j of a[j]*f[j] * pref[j]
		vector<ll> pref(n+1);
		for (int i=0; i<n; i++) {
			pref[i+1] = (pref[i] + a[i]*g[i]) % MOD;
		}
		ll cur = 0;
		for (int j=0; j<n; j++) 
			cur = (cur + a[j] * f[j] % MOD * pref[j]) % MOD;
		
		// multiply the current value by the number of matches at this round
		cur = cur * (1<<(k-m-1)) % MOD;

		// normalize the answer by g[i]*f[j]
		vector<ll> pref_g(n+1);
		for (int i=0; i<n; i++) {
			pref_g[i+1] = (pref_g[i] + g[i]) % MOD;
		}
		ll div = 0;
		for (int i=0;i <n; i++) 
			div = (div + f[i] * pref_g[i])%MOD; 

		ans = (ans + cur * inverse(div, MOD)) % MOD;
	}

	cout << ans << endl;	
	
	
	exit(0);
}
