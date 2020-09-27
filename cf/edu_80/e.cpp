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
int a[N], maxi[N];

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

int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i<=n; i++)
		a[i] = i, maxi[i]=i;
	build(1, 1, n);
	set <int> se;
	for(int i=0; i<m; i++){
		int x; cin>> x;
		se.insert(x);
		int up = query(1, 1, n, x);
		update(1, 1, n, 1, up-1, 1);
		maxi[x] = max(x, up);
		update(1, 1, n, x, x, 1-up);
	}
	for(int i=1; i<=n; i++){
		if(se.count(i))
			cout << 1 << " ";
		else
			cout << i << " ";
		int up = query(1, 1, n, i);
		cout << max(maxi[i], up) << endl;
	}
}

	
