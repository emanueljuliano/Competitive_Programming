#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
const int MOD = 1e9 + 7;

ll fexp(ll a, ll k){
	if(k==0) return 1;
	if(k%2) return a*(fexp(a, k-1)%MOD)%MOD;
	return fexp(a*a%MOD, k/2);
}

int main(){ _
	int t; cin >> t;
	while(t--){
		ll n; cin >> n;
		if(n%2)
			cout << (fexp(2, n/2+2) -2+MOD)%MOD << endl;
		else
			cout << (3*fexp(2, n/2)-2+MOD)%MOD << endl;
	}


	exit(0);
}
