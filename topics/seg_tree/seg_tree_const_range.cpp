#include <bits/stdc++.h>

using namespace std;

/*
Versão mais simples:
query (range): soma dos elementos de ql a qr
update (const): atualiza valor na posição p para x
*/

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
		t[i] = t[2*i] + t[2*i+1];
	}
}

int query(int i, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return t[i];
	if (qr < l || r < ql) return 0;
	int m = (l+r)/2;
	return query(2*i, l, m, ql, qr)
		 + query(2*i+1, m+1, r, ql, qr);
}

void update(int i, int l, int r, int p, int x) {
	if (l == r) {
		t[i] = x;
	} else {
		int m = (l+r)/2;
		if (p <= m) update(2*i, l, m, p, x);
		else update(2*i+1, m+1, r, p, x);
		t[i] = t[2*i] + t[2*i+1];
	}
}

int main(){
	cout << "seg tree query em intervalo e update em ponto" << endl;
	
}
