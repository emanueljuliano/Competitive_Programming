#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

#define f first
#define s second

const int MAX = 2e5+10;

namespace beats {
	struct node {
		int tam;
		int mi1, mi2, mi; // mi = #mi1
		vector<int> f;

		node(int x = 0) {
			f = vector<int>(30);
			for (int i=0;i <30; i++) if ((1<<i) & x) f[i]++;
			mi1 = x;
			mi2 = 2*INF;
			mi = tam = 1;
		}
		node(const node& l, const node& r) {
			if (!f.size()) f = vector<int>(30);
			tam = l.tam + r.tam;
			if (l.mi1 > r.mi1) {
				mi1 = r.mi1, mi = r.mi;
				mi2 = min(l.mi1, r.mi2);
			} else if (l.mi1 < r.mi1) {
				mi1 = l.mi1, mi = l.mi;
				mi2 = min(r.mi1, l.mi2);
			} else {
				mi1 = l.mi1, mi = l.mi+r.mi;
				mi2 = min(l.mi2, r.mi2);
			}
			for (int i=0; i<30; i++) f[i] = l.f[i] + r.f[i];
		}
		void setmax(int x) {
			if (x <= mi1) return;
			int dif = x^mi1;
			for (int i=0;i <30; i++) if (dif & (1<<i)) 
				f[i] += mi * (1 - 2 * !(x & (1<<i)));
			mi1 = x;
		}
	};

	node seg[4*MAX];
	int n, *v;

	node build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = {v[l]};
		int m = (l+r)/2;
		return seg[p] = {build(2*p, l, m), build(2*p+1, m+1, r)};
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if (l == r) return;
		for (int k = 0; k < 2; k++) {
			seg[2*p+k].setmax(seg[p].mi1);
		}
	}
	vector<int> merge(vector<int> &L, vector<int> &R) {
		for (int i=0; i<30; i++) L[i] += R[i];
		return L;
	}
	vector<int> query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return vector<int>(30);
		if (a <= l and r <= b) return seg[p].f;
		prop(p, l, r);
		int m = (l+r)/2;
		auto L = query(a, b, 2*p, l, m), R = query(a, b, 2*p+1, m+1, r);
		return merge(L, R);
	}
	node updatemax(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a or seg[p].mi1 >= x) return seg[p];
		if (a <= l and r <= b and seg[p].mi2 > x) {
			seg[p].setmax(x);
			return seg[p];
		}
		prop(p, l, r);
		int m = (l+r)/2;
		return seg[p] = {updatemax(a, b, x, 2*p, l, m),
						updatemax(a, b, x, 2*p+1, m+1, r)};
	}
};

int v[MAX];

int main(){ _
	int n, q; cin >> n >> q;
	for (int i=0; i<n; i++) cin >> v[i];
	beats::build(n, v);	
	
	while (q--) {
		int op, l, r, x; cin >> op >> l >> r >> x;
		l--, r--;

		if (op == 1) {
			beats::updatemax(l, r, x);
		}
		else {
			vector<int> f = beats::query(l, r);
			int xo = 0;
			for (int i=0; i<30; i++) if (x & (1<<i)) f[i]++;
			for (int i=0; i<30; i++) if (f[i]%2) xo^=(1<<i);
			int msb = __builtin_clz(1) - __builtin_clz(xo);
			
			if (xo==0) cout << 0 << endl;
			else cout << f[msb] << endl;
		}
	}
	
	exit(0);
}
