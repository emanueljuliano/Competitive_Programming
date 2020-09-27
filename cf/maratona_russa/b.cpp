#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	ll m, b;
	cin >> m >> b;
	ll maxi =	b*(b+1)/2;
	for(ll i=0; i<=b*m; i++){
		ll at = i/m;
		if(at*m!=i) at++;
		ll y = b-at;
		ll pa =  (y+1)*y/2;
		ll ans = pa*(i+1)+(y+1)*((i*(i+1))/2);
		maxi = max(maxi, ans);
	}
	cout << maxi << endl;
	exit(0);
}
