#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;

	while(t--){
		ll a, b, c, d; cin >> a >> b >> c >> d;

		if(a>b*c) {cout << -1 << endl; continue;}
		if(c<=d) {cout << a << endl; continue;}

		auto val = [&](ll x){
			ll heal = x*b*d;
			if(x*d>c) heal += d%c*b;
			return heal<a;
		};

		ll l = 0, r = c/d+2;
		while(l<r){
			ll m = (l+r+1)/2;
			if(val(m)) l = m;
			else r = m-1;
		}
		l++;
		//d*b + 2*d*b + ... l*d*b
		ll ans = l*a - d*b*(l-1)*(l)/2;
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
