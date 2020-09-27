#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 200200;
ll t1[4*N], t2[4*N], lz1[4*N], lz2[4*N];

void update1(ll i, ll l, ll r, ll ql, ll qr, ll val) {
	if (ql <= l && r <= qr) {
		t1[i] += val+ql-l;
		lz1[i]++;
		return;
	}
	if (qr < l || r < ql) return;
	ll m = (l+r)/2;
	update1(2*i, l, m, ql, qr, val);
	update1(2*i+1, m+1, r, ql, qr, val);
}

ll query1(ll i, ll l, ll r, ll pos, ll x) {
	if (l == r) return t1[i];
	ll m = (l+r)/2;
	if (pos <= m)
		if(t1[i]!=0)
			return t1[i] + query1(2*i, l, m, pos, x+lz1[i]);
		else
			return t1[i] + query1(2*i, l, m, pos, x);
	else {
		if(t1[i]!=0)
			return t1[i] + query1(2*i+1, m+1, r, pos, x+lz1[i]) + (l-m-1)*(x+lz1[i]);
		else
			return t1[i] + query1(2*i+1, m+1, r, pos, x) + (l-m-1)*x;	
	}
	
}

void update2(ll i, ll l, ll r, ll ql, ll qr, ll val) {
	if (ql <= l && r <= qr) {
		t2[i] += val+r-qr;
		lz2[i]++;
		return;
	}
	if (qr < l || r < ql) return;
	ll m = (l+r)/2;
	update2(2*i, l, m, ql, qr, val);
	update2(2*i+1, m+1, r, ql, qr, val);
}

ll query2(ll i, ll l, ll r, ll pos, ll x) {
	if (l == r) return t2[i];
	ll m = (l+r)/2;
	if (pos <= m){ 
		if(t2[i]!=0)
			return t2[i] + query2(2*i, l, m, pos, x+lz2[i]) - (r-m)*(x+lz2[i]);
		else
			return t2[i] + query2(2*i, l, m, pos, x) - (r-m)*x;
	}
	else
		if(t2[i]!=0)
			return t2[i] + query2(2*i+1, m+1, r, pos, x+lz2[i]);
		else
			return t2[i] + query2(2*i+1, m+1, r, pos, x);
}


int main(){ ios_base::sync_with_stdio(0);cin.tie(0);
	ll n, m;
	cin >> n >> m;
	for(int i=1; i<4*n; i++){
		t1[i] = 0; t2[i] = 0;
		lz1[i] = 0; lz2[i] = 0;
	}

	for(ll j=0; j<m; j++){
		ll l, r, op;
		cin >> op;
		if(op==3){
			cin >> r;
			ll q1 = query1(1, 1, n, r, 0);
			ll q2 = query2(1, 1, n, r, 0);
			cout << q1 + q2 << endl;
		}
		if(op==2){
			cin >> l >> r;
			update2(1, 1, n, l-r+1, l, r);
		}
		if(op==1){
			cin >> l >> r;
			update1(1, 1, n, l, l+r-1, r);
		}
	}
	exit(0);
}
