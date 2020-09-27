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
ll fa[200], ifa[200];
ll gcd(ll a, ll b){
	return !b ? a : gcd(b, a % b);
}

ll pow(ll x, ll y, ll m) { // recursivo
	if (!y) return 1;
		ll ans = pow(x*x%MOD, y/2, m)%MOD;
			return y%2 ? x*ans%MOD : ans%MOD;
			}

ll facto(ll x){
	if(fa[x] != -1) return fa[x];
	fa[0] = 1;
	ll ret = 1;
	for(int i=1;i <=x; i++){
		fa[i] = ret*i%MOD;
		ifa[i] = pow(fa[i], MOD-2, MOD);
		ret  = (ret*i)%MOD;
	}
	return ret;
}

ll inv(ll x){
	if(ifa[x] != -1) return ifa[x];
	return pow(x, MOD-2, MOD)%MOD;
}

ll seq(vector<int> v){
	ll ret = fa[v.size()];
	int at = 1;
	if(v.size())for(int i=0;i <v.size()-1; i++){
		if(v[i]==v[i+1]) at++;
		else{
			ret = ret*inv(at)%MOD;
			at = 1;
		}
	}
	ret = ret*inv(at)%MOD;
	return ret;
}

int main(){ _
	for(int i=0; i<200; i++) fa[i] = -1;
	facto(190);
	vector<ll> pri;

	ll d; cin >> d;
	for(ll i=2; i*i<=d; i++){
		if(d%i==0){
			pri.pb(i);
			while(d%i==0) d/=i;
		}
	}
	if(d>1) pri.pb(d);
	int q; cin >> q;
	while(q--){
		ll a, b; cin >> a >> b;
		if(a>b) swap(a, b);
		ll g = gcd(a, b);
		a /= g;
		b /= g;

		vector<int> v, w;
		int it = 0;
		for(ll i : pri){
			if(a%i==0){
				while(a%i==0){v.pb(it);  a/=i;}
				it+=2;
			}
		}
		it++;
		if(a>1) v.pb(it);
		it = 0;
		for(ll i : pri){
			if(b%i==0) {while(b%i==0){w.pb(it); b/=i;} it+=2;}
		}
		it++;
		if(b>1) w.pb(it);
		/*cout <<"vez " <<  q << endl;
	
		if(v.size()){
		cout << "TAm v" << endl;
		for(auto i: v) cout << i << " ";
		cout << endl;
		}
		if(w.size()){
		cout << "Tam w" << endl;
		for(auto i: w) cout << i << " ";
		cout << endl;
		}*/
		
		ll ans = seq(v);
		ans = ans*seq(w)%MOD;
		cout << ans << endl;
	
	
	}
	
	
	
	exit(0);
}

