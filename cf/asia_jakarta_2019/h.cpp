#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;
typedef long double ld;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ld eps = 1e-4;
int main(){ _
	ll n; cin >> n;
	ld ans = 0;
	vector<ii> v(n);
	for(auto &i : v) cin >> i.f >> i.s, ans=max(ans, (ld)i.f/2.0*i.s);
	
	vector<pair<ii, ll>> ev;
	for(ll i=0;i <n; i++) ev.pb({v[i], i}), ev.pb({{v[i].s, v[i].f}, i});
	sort(ev.begin(), ev.end());

	vector<pair<ii, ll>> st;
	for(auto IT : ev){
		ll x = IT.f.f, y = IT.f.s, id = IT.s;
		while(st.size() and st.back().f.s<=y){
			if(id != st.back().s) ans = max(ans, (ld)st.back().f.f*st.back().f.s);
			st.pop_back();
		}
		if(st.size() and x==st.back().f.f){
			if(id!=st.back().s) ans = max(ans, (ld)x*y);
			continue;
		}
		st.pb({{x, y}, id});
	}
	
	for(ll i=0;i <ll(st.size())-1; i++){
		ll x = st[i].f.f, y = st[i+1].f.s;
		ll id1 = st[i].s, id2 = st[i+1].s;
		if(id1==id2) continue;
	//	cout << x << " " << y << endl;
		ans = max(ans, (ld)x*y);
	}
	ans += eps;
	cout << setprecision(1) << fixed;
	cout << ans << endl;
	
	
	
	exit(0);
}

