#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const ll MOD = 1e9+7;

ll inv(ll a, ll b){
	if(1 < a) return b - inv(b % a, a) * b/a;
	else return 1;
}

int main(){ _

	ll n, m, r, c; cin >> n >> m >> r >> c;

	ll a = n/gcd(n,r), b = m/gcd(m,c);

	ll cycle = lcm(a,b);

	ll a1c = m/b;
	ll a1l = n/a;
	a%= MOD;
	b%= MOD;
	a1c%= MOD;
	a1l%= MOD;
	cycle %= MOD;

	ll sc = (m + a1c) * b%MOD*inv(2, MOD)%MOD;
	ll sl = (n-1 + a1l-1) * a%MOD*inv(2, MOD)%MOD;

	ll ans = (sc*cycle%MOD*inv(b, MOD))%MOD + (sl*m%MOD*cycle%MOD*inv(a, MOD))%MOD;
	cout << ans%MOD << endl;

	return 0;
}

