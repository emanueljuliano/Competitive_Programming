#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e5+10;

namespace seg {
	pair<int, int> seg[4*MAX];
	int lazy[4*MAX];
	int n, *v;
	pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
		return {a.first + b.first, a.second + b.second};
	}
	pair<int, int> build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = {0, 1};
		int m = (l+r)/2;
		return seg[p] = merge(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void prop(int p, int l, int r) {
		if (lazy[p] % 2) swap(seg[p].first, seg[p].second);
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	pair<int, int> query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {0, 0};
		int m = (l+r)/2;
		return merge(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	pair<int, int> update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = merge(update(a, b, x, 2*p, l, m),
							  update(a, b, x, 2*p+1, m+1, r));
	}
};


int main(){ _
	#warning FILE IN 
    freopen("reflection.in", "r", stdin);	
	int t; cin >> t;
	while (t--) {
		int q; cin >> q;
		seg::n = MAX-1;
		seg::build();
		while (q--) {
			int x; cin >> x;
			auto [zero, one] = seg::query(0, x-1);
			cout << one-zero << endl;
			seg::update(x, MAX-1, 1);
		}
	}
	
	
	exit(0);
}
