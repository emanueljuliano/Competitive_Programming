#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f

typedef long long ll;
const int N = 200345;
vector<ll> t[4*N];
ll v[N];

void build(ll i, ll l, ll r) {
	t[i].resize(0);
	if (l == r) {
		t[i].push_back(v[l]);
	} else {
		ll m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		merge(t[2*i].begin(), t[2*i].end(), t[2*i+1].begin(), t[2*i+1].end(), back_inserter(t[i]));
	}
}

ll query(ll i, ll l, ll r, ll ql, ll qr, ll b) {
	if (ql <= l && r <= qr) {
		return upper_bound(t[i].begin(), t[i].end(), b)
		- t[i].begin();		
	}
	if (qr < l || r < ql) return 0;
	ll m = (l+r)/2;
	return query(2*i, l, m, ql, qr, b)
		 + query(2*i+1, m+1, r, ql, qr, b);
}

int main(){ ios_base::sync_with_stdio(0);cin.tie(0);
	ll tc;
	cin >> tc;
	while(tc--){
		ll n;
		cin >> n;
		if(n==0){cout << 0 << endl; continue;}
		for(ll i=1; i<=n; i++){
			cin >> v[i];
		}

		build(1, 1, n);
		ll ans = 0;
		for(ll i=1; i<n; i++){
			ans += query(1, 1, n, i+1, n, v[i]-1);
		}
		cout << ans << endl;
	}

}
