#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t; cin >> t;
	while(t--){
		ll n, m; cin >> n >> m;
		//if(m==0) {cout << 0 << endl; continue;}
		ll ans = (n*(n-1))/2 + n;
		ll sobra = n-m;
		ll at = sobra/(m+1);
		ll x = sobra - (m+1)*at;
		ll y = (m+1)-x;
		at++;
		ans -= x*(at*(at-1)/2 + at);
		at--;
		ans -= y*(at*(at-1)/2 + at);
		cout << ans << endl;

	}


	exit(0);
}
