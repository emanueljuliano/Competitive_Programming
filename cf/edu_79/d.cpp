#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
const int MOD = 998244353;

ll fexp(ll a, ll k){
	if(k==0) return 1;
	if(k==1) return a%MOD;
	if(k%2==0) return (fexp((a*a)%MOD, k/2)%MOD)%MOD;
	return (a*fexp(a, k-1)%MOD)%MOD;
}

ll inv(ll a){
	return fexp(a, MOD-2)%MOD;
}

int main(){ _

	ll n;
	cin >> n;
	ll tot=0;
	map<int, ll> p;

	map<int, vector<int > >  v;
	for(int i=0; i<n; i++){
		ll k;
		cin >> k;
		tot+=k;
		for(int j=0; j<k; j++){
			int a;
			cin >> a;
			p[a]++;
			v[i].pb(a);
		}
	}
	ll ans = 0;
	tot = inv(tot);
	ll d = inv(n);
	for(int i=0; i<n; i++){
		ll soma=0;
		for(int j=0; j<v[i].size(); j++){
			soma = (soma+ p[v[i][j]]%MOD*d%MOD)%MOD;
//			cout << soma << " ";
		}
//		cout << endl;
		ans = ans +(soma%MOD*inv((ll)v[i].size())%MOD)%MOD;
		ans %= MOD;
//		cout << ans << endl;
	}

	cout << (ans%MOD*d%MOD)%MOD << endl;

	exit(0);
}
