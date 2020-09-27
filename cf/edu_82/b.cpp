#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	int t; cin >> t;
	while(t--){
		int n, g, b; cin >> n >>g >> b;
		int m = (n+1)/2;
		int mod = g+b;
		if(b<=g){
			cout <<n << endl;
			continue;

		}
		if(m<=g){
			cout << n << endl;
			continue;
		}
		ll ans = 0;
		if(b>=g){
			ll d = (m+g-1)/g;
			ans += d*((ll)g+b);
			ans -= b;
			if(g*d>m) ans -= g*d-m;
			if(ans<n) ans = n;
			cout << ans << endl;
		}
	
	}


	exit(0);
}
