#include <bits/stdc++.h>

using namespace std;

#define pb push_back
typedef long long ll;

int main(){
	vector<ll> v;
	ll n, k; cin >> n >> k;
	ll soma = k;
	for(ll i=0; i<n; i++){
		ll a;
		cin >> a;
		soma += a;
		v.pb(a);
	}
	ll ans = 1;
	for(ll i=1; i<10000000; i++){
		ll s = 0;
		for(ll j=0; j<n; j++){
			s += (i-v[j]%i)%i;
		}
		if(s<=k) ans = i;
	}
	cout << ans << endl;
}
