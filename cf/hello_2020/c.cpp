#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	ll n, m;
	ll ans=0;
	cin >> n >> m;
	
	ll fact[250500];
	fact[0] = 1;
	for(ll i=1; i<=n; i++){
		fact[i] = (i*fact[i-1])%m;
	}
	for(ll x=1; x<=n; x++){
		ans = (ans%m+ (fact[x]%m * (n-x+1)%m*(n-x+1)%m * fact[n-x]%m)%m)%m;
		ans %=m;
	}
	cout << ans << endl;
	exit(0);
}
