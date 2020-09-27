#include <bits/stdc++.h>

using namespace std;

/*
Versão range-update/point-query:
query: valor na posição p
update: soma x nos elementos de ql a qr
Interpretação da seg:
O valor na posição i do vetor corresponde a soma
dos valores dos nós no caminho da raiz até a folha i
Isso permite "somar x" a todos os elementos de um nó
em O(1).
*/

const int N = 112345;

int t[4*N];
int a[N];

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

namespace segshow {
	int n, seg[2*MAX];

	void build(int n, int* v) {
		for (int i = 0; i < n; i++) seg[i+n] = v[i];
	}
	int query(int p) {
		int ans = seg[p+=n];
		while (p /= 2) ans += seg[p];
	}
	void update(int a, int b, int x) {
		for (a += n, b += n; a <= b; ++a/=2, --b/=2) {
			if (a%2==1) seg[p] += x;
			if (b%2==0) seg[p] += x;
		}
	}
}

int main(){
	cout << "seg tree query em ponto e update em intervalo" << endl;
	
}
