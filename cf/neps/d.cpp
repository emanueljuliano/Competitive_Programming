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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<pair<ii, ii>> v;
int n;
ll k;
bool show(ll x){
	ll ret = 0;
	for(int i=0;i <n; i++){
		ll xa, ya, xb, yb;
		xa = v[i].f.f;
		ya = v[i].f.s;
		xb = v[i].s.f;
		yb = v[i].s.s;

		if(x>=yb) ret += (xb-xa)*(yb-ya);
		else if(x>=ya) ret += (xb-xa)*(x-ya);
	}
	return ret>=k;
}

ll bb(ll l, ll r){
//	cout << "HM" << endl;
	if(l==r) return l;
	ll m = (l+r)/2;
	if(show(m)) r = m;
	else l = m+1;
	return bb(l, r);
}

int main(){ //_
	cin >> n >> k;
	ll tot = 0;
	for(int i=0;i <n; i++){
		ll xa, ya, xb, yb; cin >> xa >> ya >> xb >> yb;
		v.pb({{xa, ya}, {xb, yb}});
		tot += abs(xa-xb) * abs(ya-yb);
		
	}
	if(tot<k){
		cout << "PERDAO MEU REI" << endl;
		exit(0);
	}

	ll ans = bb((ll)-1e9, (ll)1e9);
	cout << ans << endl;
	
	
	
	exit(0);
}
