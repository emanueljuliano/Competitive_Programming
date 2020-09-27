#include <bits/stdc++.h>

using namespace std;

const int N = 112345;

int t[2000100];
int a[500500];

void build(int i, int l, int r) {
	if (l == r)
		t[i] = a[l];
	else {
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		t[i] = 0;
	}
}

void update(int i, int l, int r, int ql, int qr, int x) {
	if (ql <= l && r <= qr) {
		t[i] += x;
		return;
	}
	if (qr < l || r < ql) return;
	int m = (l+r)/2;
	update(2*i, l, m, ql, qr, x);
	update(2*i+1, m+1, r, ql, qr, x);
}

int query(int i, int l, int r, int p) {
	if (l == r) return t[i];
	int m = (l+r)/2;
	if (p <= m) 
		return t[i] + query(2*i, l, m, p);
	else 
		return t[i] + query(2*i+1, m+1, r, p);
	
}

int main(){ ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin>>n;
	for(int i=1; i<=n; i++) a[i]=i;
	build(1, 1, n);
	for(int i=0; i<n; i++){
		int c; cin >> c;
		cout << query(1, 1, n, c);
		if(i!=n-1) cout << " ";
		update(1, 1, n, c, n, -1);
	}
	cout << endl;
}
