#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

vector<ll> divi;
ll tot(ll n){
	ll ret = n;
	for(ll i=0; i<divi.size(); i++){
		ret -= ret / divi[i];
	}
	return ret;
}

int main(){// _
	int t; cin>> t;
	while(t--){
		divi.resize(0);
		ll a, m; cin >> a >> m;
//		cout <<"hm" << endl;
		ll gc = __gcd(a, m);
		a/= gc;
		m/=gc;
		
//		cout <<"hmd" << endl;
		ll n = m;
		for (ll i = 2; i*i <= n; i++) if (n % i == 0) {
			while (n % i == 0) n /= i;
			divi.pb(i);
		}
		if (n > 1) divi.pb(n);

//		cout <<"hmd" << endl;
		ll ans = tot(a+m);
//		cout <<"hms" << endl;
		ans -= tot(a);

		cout << ans << endl;
	}


	exit(0);
}
