#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef int64_t ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll pg(ll x){
	return (ll)x*(x+1)/2;
}

int main(){ _
	int n; ll x; cin >> n >> x;	
	vector<ll> v;
	ll ans = x;
	for(int i=0;i <n; i++){
		ll a; cin >>a; v.pb(a);
		if(x<=a) ans = max(ans, pg(a)-pg(a-x));
	}
	// Ao contrario
	for(int i=0;i <n; i++) v.pb(v[i]);

	reverse(v.begin(), v.end());
	vector<ll> soma, val;
	soma.pb(v[0]); val.pb(pg(v[0]));
	ll maxi = 0;
	for(int i=1;i <v.size(); i++){
		soma.pb(soma[i-1]+v[i]);
		val.pb(val[i-1]+pg(v[i]));
		maxi = max(maxi, val[i]);
	}
	ll at = 0;
	ll pgat = 0;
	for(int i=0;i <n; i++){
		int lo = upper_bound(soma.begin(), soma.end(), at+x) - soma.begin();
		bool inv = false;
		if(lo<=i) inv = true;
		lo--;
		ll sat = soma[lo];
		ll res = x+at-sat;
		
		ll vat = val[lo] - pgat;
		lo++;
		vat += pg(v[lo]) - pg(v[lo]-res);
		if(!inv)ans = max(ans, vat);
		
		at += v[i];
		pgat += pg(v[i]);
	}

	cout << ans << endl;

	exit(0);
}
