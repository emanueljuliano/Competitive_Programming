#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const ld eps = 1e-3;

int main(){ _
	ll n, d; cin >> n >> d;
	vector<ll> v(n);
	for(auto &i : v) cin >> i;

	auto val = [&](ld x){
		ld at = -1e18;
		for(auto u : v) at = max(at+d, u-x);
		bool show = true;
		for(int i=n-1; i+1; i--){
			if(abs(at-v[i]) > x+eps) show = false;
			at -= d;
		}
		
		if(show) return true;
	
		at = 1e18;
		for(auto u : v) at = min(at-d, u+x);
		show = true;
		for(int i=n-1; i+1; i--){
			if(abs(at-v[i]) > x+eps) show = false;
			at += d;
		}
		return show;
	};
	
	ld l = 0, r = 1e17;
	while(abs(l-r)>eps){
		ld m = (l+r)/2;
		if(val(m)) r=m;
		else l = m;
	}

	cout << setprecision(1) << fixed;
	cout << ((l+r)/2+2*eps) << endl;
	
	
	exit(0);
}
