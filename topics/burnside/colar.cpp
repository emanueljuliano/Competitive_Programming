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

const int MOD = 1000000007;
ll pow(ll x, ll y, ll m) {
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % m;
		y >>= 1;
		x = (x * x) % m;
	}
	return ret;
}


int main(){ _
	int t; cin >> t;
	int cs = 0;
	while(t--){ cs++; cout << "Case " << cs << ": ";
		ll n, k; cin >> n >> k;
		ll ans = pow(k, n, MOD);
		ll den = 1;
		for(ll i=1; i<n; i++){
			den++, ans = (ans+pow(k, __gcd(i, n), MOD))%MOD;
		}
		den = pow(den, MOD-2, MOD);
		cout << (ans*den)%MOD << endl;
	}



	exit(0);
}
