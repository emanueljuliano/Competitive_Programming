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
const ll MOD = 998244353;

ll fexp(ll x, ll y) { // recursivo
	if (!y) return 1;
	ll ans = fexp((x*x)%MOD, y/2)%MOD;
	return y%2 ? (x*ans)%MOD : ans;
}


ll pow(ll x, ll y, ll m) { // iterativo
	ll ret = 1;
		while (y) {
				if (y & 1) ret = (ret * x) % m;
						y >>= 1;
								x = (x * x) % m;
									}
										return ret;
										}

ll inv(ll x){
	return pow(x, MOD-2, MOD);
}
int main(){ _
	ll n, m, l, r; cin >> n>> m >> l >> r;
	r= r-l+1;
	ll mu = n*m;
	ll tot = fexp(r, mu);
	ll par = (r+1)/2;
	ll imp = r/2;
	ll ans = pow(imp, mu, MOD);
	ans = (ans+pow(par, mu, MOD))%MOD;

	if(n*m%2==0){
		if(imp!=par){
			ans = (tot+1)*inv(2)%MOD;
		}
		else ans = tot*inv(2)%MOD;


		cout << ans << endl;
	}
	else{
		cout << tot%MOD << endl;
	}
	
	
	
	exit(0);
}
