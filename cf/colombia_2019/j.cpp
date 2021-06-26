#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define f first
#define s second
const int MAX = 1e5+10;
int v[MAX];

namespace beats {
	struct node {
		int tam;
		ll sum, lazy;
		ll mi1, mi2, mi;
		ll ma1, ma2, ma;

		node(ll x = 0) {
			sum = mi1 = ma1 = x;
			mi2 = LINF, ma2 = -LINF;
			mi = ma = tam = 1;
			lazy = 0;
		}
		node(const node& l, const node& r) {
			sum = l.sum + r.sum, tam = l.tam + r.tam;
			lazy = 0;
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
			if (l.ma1 < r.ma1) {
				ma1 = r.ma1, ma = r.ma;
				ma2 = max(l.ma1, r.ma2);
			} else if (l.ma1 > r.ma1) {
				ma1 = l.ma1, ma = l.ma;
				ma2 = max(r.ma1, l.ma2);
			} else {
				ma1 = l.ma1, ma = l.ma+r.ma;
				ma2 = max(l.ma2, r.ma2);
			}
		}
		void setmax(ll x) {
			if (x<=mi1) return;
			sum += (x - mi1)*mi;
			if (ma1 == mi1) ma1 = x;
			if (ma2 == mi1) ma2 = x;
			mi1 = x;
		}
		void setsum(ll x) {
			mi1 += x, mi2 += x, ma1 += x, ma2 += x;
			sum += x*tam;
			lazy += x;
		}
	};
	
	node seg[4*MAX];
	int n, *v;

	node build(int p=1, int l = 0, int r=n-1) {
		if (l == r) return seg[p] = {v[l]};
		int m = (l+r)/2;
		return seg[p] = {build(2*p, l, m), build(2*p+1, m+1, r)};
	}
	void build(int n2, int *v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if (l == r) return;
		for (int k = 0; k<2; k++) {
			if(seg[p].lazy) seg[2*p+k].setsum(seg[p].lazy);
			seg[2*p+k].setmax(seg[p].mi1);
		}
		seg[p].lazy = 0;
	}
	pair<pair<ll, ll>, ll> query(int a, int b, int p=1, int l=0, int r=n-1) {
		if(b < l or r < a) return {{LINF, -LINF}, 0};
		if (a<=l and r<=b) return {{seg[p].mi1, seg[p].ma1}, seg[p].sum};
		prop(p, l, r);
		int m = (l+r)/2;
		auto L = query(a, b, 2*p, l, m), R = query(a, b, 2*p+1, m+1, r);
		return {{min(L.f.f, R.f.f), max(L.f.s, R.f.s)}, L.s+R.s};
	}
	node updatemax(int a, int b, ll x, int p=1, int l = 0, int r = n-1) {
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
	node updatesum(int a, int b, ll x, int p=1, int l = 0, int r = n-1) {
		if (b < l or r < a) return seg[p];
		if (a <= l and r <= b) {
			seg[p].setsum(x);
			return seg[p];
		}
		prop(p, l, r);
		int m = (l+r)/2;
		return seg[p] = {updatesum(a, b, x, 2*p, l, m),
						 updatesum(a, b, x, 2*p+1, m+1, r)};
	}

}

int main(){ _
	int n, q; cin >> n >> q;
	for(int i=0; i<n; i++) cin >> v[i];
	beats::build(n, v);
	
	while(q--) {
		int f, a, b; cin >> f >> a >> b; a--, b--;
		if(f==1) {
			if(a<=b){
				auto T =  beats::query(a, b);
				cout << T.s << endl;
			}
			else {
				auto T =  beats::query(0, b);
				auto T2 =  beats::query(a, n-1);
				cout << T.s+T2.s << endl;
			}
		}
		else {
			int x; cin >> x;
			if(a<=b) {
				beats::updatesum(a, b, -x);
				beats::updatemax(a, b, 0);
			}
			else{
				beats::updatesum(0, b, -x);
				beats::updatemax(0, b, 0);
				beats::updatesum(a, n-1, -x);
				beats::updatemax(a, n-1, 0);
			}
		}
	}
	
	
	exit(0);
}
