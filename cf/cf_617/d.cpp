#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define ff first
#define ss second

typedef long long ll;


int main(){ _
	
	ll n, a, b, k; cin >> n >> a >> b >> k;
	map<ll, ll> ma;
	ll mod = a+b;
	ll ans = 0;
	for(ll i=0; i<n; i++){
		ll h; cin >> h;
		if(h%mod==0) ma[b]++;
		else if(h%mod<=a) ans++;
		else if(h%mod>a) ma[h%mod-a]++;
	}
	for(auto x : ma){
		if (x.ff>k*a) break;
		for(int i=0; i<x.ss; i++){
			if(x.ff>a*k) break;
			k -= (x.ff+a-1)/a;
			ans++;
		}
	}
	cout << ans << endl;
	exit(0);
}
