#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t; cin >> t;
	while(t--){
		ll n; cin >> n;
		ll sz = (2*n+2)/3;
		ll res = n-sz;
		ll ans =  min(sz, sz/2+1+res);
		ans%=(int)1e9+7;
		if(res<=0 or sz<=2) cout << 0 << endl;
		else cout <<ans<< endl;
	}


	exit(0);
}
