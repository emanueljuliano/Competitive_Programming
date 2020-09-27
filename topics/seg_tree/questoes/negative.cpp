#include <bits/stdc++.h>

using namespace std;

/*
Versão mais simples:
query (range): soma dos elementos de ql a qr
update (const): atualiza valor na posição p para x
*/


#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define inf 0x3f3f3f3f

const int N = 112345;
int t[4*N];
int a[N];

void build(int i, int l, int r) {
	if (l == r) {
		t[i] = a[l];
	} else {
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		t[i] = min(t[2*i], t[2*i+1]);
	}
}

int query(int i, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return t[i];
	if (qr < l || r < ql) return inf;
	int m = (l+r)/2;
	return min(query(2*i, l, m, ql, qr)
		 , query(2*i+1, m+1, r, ql, qr));
}

int main(){ _
	int tc;
	cin >> tc;
	for(int ii=1; ii<=tc; ii++){
		cout << "Scenario #" << ii << ":"<<endl;
		int n, q;
		cin >> n >> q;
		for(int i=1; i<n+1; i++){
			cin >> a[i];
		}
		build(1, 1, n);
		for(int i=0; i<q; i++){
			int x, y;
			cin >> x >> y;
			if(x>y) swap(x, y);
			cout << query(1, 1, n, x, y) << endl;
		}
	}
}
