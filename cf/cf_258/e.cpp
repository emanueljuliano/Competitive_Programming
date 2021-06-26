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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const ll MOD = 1e9+7;

ll inv(ll a, ll b) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}

ll comb(ll a, ll b){
	if(b>a) return 0;
	ll ret = 1;
	for(int i=0;i <b; i++) ret = (ret*((a-i)%MOD))%MOD;
	for(int i=1;i <=b; i++) {
		ret = (ret*inv(i, MOD))%MOD;
	}
	return ret;
}

int main(){ _
	ll n, s; cin >> n >> s;
	vector<ll> v(n);
	for(auto &i : v) cin >> i;

	ll ans = 0;
	for(int i=0;i <(1<<n); i++){
		int sz = __builtin_popcount(i);
		
		ll a = s+n-1;
		for(int j=0; j<n; j++) if(i&(1<<j)) a -= v[j]+1;

		if(sz%2==0) ans = ans + comb(a, n-1);
		else ans = ans - comb(a, n-1);
		ans = (ans%MOD+MOD)%MOD;
	}
	
	cout << ans << endl;
	
	exit(0);
}
