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
const int MOD = 998244353;


ll pow(ll x, ll y, ll m) { // iterativo
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % m;
		y >>= 1;
		x = (x * x) % m;
	}
	return ret;
}

ll inv(ll a){
	return pow(a, MOD-2, MOD);
}

ll fat[200200];
void fato(){
	fat[0] = 1;
	fat[1] = 1;
	for(ll i=2; i<200020; i++){
		fat[i] = i*fat[i-1]%MOD;
	}
}

ll comb(ll a, ll b){
	if(a<b) return 1;
	if(b==0 or a==0) return 1;
	ll ret = fat[a];
	ret = ret * inv(fat[b])%MOD *inv(fat[a-b])%MOD;
	return ret;
}

int main(){ _
	ll n, m;
	fato();
	cin >> n >> m;
	if(n==2) return cout << 0 << endl, 0;
	ll ans = 0;

	ll g = n-1;
	for(g; g<=m; g++){
		ll mul = g-1;
		ll com = comb(g-2, n-3);
		ll n_caras = n-3;
	//	cout << "ans " << ans << " g " << g <<" mul " << mul << " com " << com << " pow " << pow(2, n_caras) << endl;
		ans = ans + mul%MOD*com%MOD*pow(2, n_caras, MOD)%MOD;
		ans %= MOD;
	}
	cout << ans << endl;
	
	
	exit(0);
}
