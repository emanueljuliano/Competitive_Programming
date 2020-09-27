#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 112345;
ll t[4*N], lz[4*N];
ll a[N];

void build(int i, int l, int r) {
	if (l == r) {
		t[i] = a[l];
	} else {
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		t[i] = t[2*i] + t[2*i+1];
	}
}

void push(int i, int l, int r) {
	if (lz[i]) {
		t[i] += lz[i] * (r-l+1);
		if (l != r) {
			lz[2*i] += lz[i];
			lz[2*i+1] += lz[i];
		}
		lz[i] = 0;
	}
}

ll query(int i, int l, int r, int ql, int qr) {
	push(i, l, r);
	if (ql <= l && r <= qr) return t[i];
	if (qr < l || r < ql) return 0;
	int m = (l+r)/2;
	return query(2*i, l, m, ql, qr)
		 + query(2*i+1, m+1, r, ql, qr);
}

void update(int i, int l, int r, int ql, int qr, ll x) {
	// nao esqueçam!!!
	push(i, l, r);
	if (qr < l || r < ql) return;
	if (ql <= l && r <= qr) {
		lz[i] += x;
		push(i, l, r);
	} else {
		int m = (l+r)/2;
		update(2*i, l, m, ql, qr, x);
		update(2*i+1, m+1, r, ql, qr, x);
		
		t[i] = t[2*i] + t[2*i+1];
	}
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, c;
		cin >> n >> c;
		for(int i=1; i<=n; i++) a[i]=0;
		for(int i=1; i<=4*n; i++) lz[i]=0;
	
		build(1, 1, n);
		for(int i=0; i<c; i++){
			int o, p, q;
			cin >> o >> p >> q;
			if(p>q) swap(p, q);
			if(o==0){
				ll v;
				cin >> v;
				update(1, 1, n, p, q, v);
			}
			else{
				cout << query(1, 1, n, p, q) << endl;
			}
		}
	}
}
