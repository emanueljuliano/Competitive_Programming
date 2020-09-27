#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;


int main(){ _
	ll k, n;
	cin >> n >> k;
	long double ans = 0.0;
	long double w = n-k+1;
	long double a1 = 0.0, a2=0.0;
	vector<ll> v;
	for(int i=0; i<n; i++){
		ll a; cin >> a;
		v.pb(a);
	}
	for(ll i =0; i<k; i++){
		ll a;
		a1 += v[i];
	}
	ans += a1;
	for(ll i=k; i<n; i++){
		a1 -= v[i-k];
		a1 += v[i];
		ans += a1;
	}
	cout << setprecision(6) << fixed;
	cout << double(ans)/w << endl;
	exit(0);
}
