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

int n, k;
vector<int> va, vb;

ll val(int a, int b){
	ll ret = n-1;
	vector<pair<ll, ll>> v;
	ll ml=0, mr=0;
	for(int i=0;i <k; i++){
		ll dl = va[(a+i)%k] - vb[(b+i)%k]; dl = (dl+n)%n;
		ll dr = vb[(b+i)%k] - va[(a+i)%k]; dr = (dr+n)%n;
		v.pb({dl, dr});
		mr = max(mr, dr);
		ml = max(ml, dl);
	}
	ret = min(ret, mr);
	ret = min(ret, ml);
	sort(v.begin(), v.end());

	vector<ii> st;
	st.pb(v[0]);
	for(auto [x, y] : v){
		while(st.size() and st.back().s<=y) st.pop_back();
		if(st.size() and st.back().f==x) continue;
		st.pb({x, y});
	}
	for(int i=0; i<int(st.size())-1; i++){
		ll x = st[i].f, y = st[i+1].s;
		ret = min(ret, 2*min(x, y) + max(x, y));
	}

	return ret;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> n >> k;
		va.resize(k), vb.resize(k);
		
		for(auto &i : va) cin >> i;
		for(auto &i : vb) cin >> i;
		sort(va.begin(), va.end());
		sort(vb.begin(), vb.end());

		ll ans = n-1;
		for(int i=0;i <k; i++){
			ans = min(ans, val(0, i));	
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
