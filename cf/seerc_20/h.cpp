#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e5+10;

struct Seq {
	pair<int, int> seg[2 * MAX];
	int n = 0;
	int b2;	
	Seq() {n = 0;}

	pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
		pair<int, int> c;
		if (a.first == -1 or a.first == b.first)
			c.first = b.first;
		else if (b.first == -1) c.first = a.first;
		else c.first = -2;
		c.second = a.second + b.second;
		return c;
	}

	void build(int n2, int *v, int b) {
		n = n2, b2 = b;
		for (int i=n; i<2*n; i++) {
			if (__builtin_popcount(v[i-n]) == b) seg[i] = {v[i-n], 1};
			else seg[i] = {-1, 0};
		}
		for (int i = n - 1; i; i--) {
			seg[i] = merge(seg[2*i], seg[2*i+1]);
		}
	}

	pair<int, int> query(int a, int b) {
		pair<int, int> ret = {-1, 0};
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret = merge(ret, seg[a]);
			if (b % 2 == 0) ret = merge(ret, seg[b]);
		}
		return ret;
	}
};

struct Sor {
	int seg[2 * MAX];
	int n = 0;
	int b2;	
	Sor() {n = 0;}

	void build(int n2, int *v, int b) {
		n = n2, b2 = b;
		for (int i=n; i<2*n; i++) {
			if (__builtin_popcount(v[i-n]) == b) seg[i] = v[i-n];
			else seg[i] = 0;
		}
		for (int i = n - 1; i; i--) seg[i] = seg[2*i] | seg[2*i+1];
	}

	int query(int a, int b) {
		int ret = 0;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret |= seg[a];
			if (b % 2 == 0) ret |= seg[b];
		}
		return ret;
	}
};

struct Sand {
	int seg[2 * MAX];
	int n = 0;
	int b2 = 0;	
	Sand() {n = 0;}

	void build(int n2, int *v, int b) {
		n = n2;
		b2 = b;
		for (int i=n; i<2*n; i++) {
			if (__builtin_popcount(v[i-n]) == b) seg[i] = v[i-n];
			else seg[i] = ~0;
		}
		for (int i = n - 1; i; i--) seg[i] = seg[2*i] & seg[2*i+1];
	}

	int query(int a, int b) {
		int ret = ~0;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret = ret & seg[a];
			if (b % 2 == 0) ret = ret & seg[b];
		}
		return ret;
	}
};

int v[MAX];

int main(){ _
	int n, q; cin >> n >> q;
	for (int i=0; i<n; i++) cin >> v[i];
	
	vector<Sand> sand(31); 
	vector<Sor> sor(31); 
	vector<Seq> seq(31); 
	for (int i=0; i<31; i++) {
		sand[i].build(n, v, i);
		sor[i].build(n, v, i);
		seq[i].build(n, v, i);
	}
	
	while (q--) {
		int l, r; cin >> l >> r; l--, r--;
		vector<int> prefor;
		prefor.push_back(sor[0].query(l, r));
		for (int i=1; i<31; i++) {
			prefor.push_back(prefor[i-1] | sor[i].query(l, r));
		}

		vector<int> sufand;
		sufand.push_back(sand[30].query(l, r));
		for (int i=29; i+1; i--) {
			sufand.push_back(sufand.back() & sand[i].query(l, r));
		}
		reverse(sufand.begin(), sufand.end());

		bool ans = false;
		int at = 0;
		for (int i=0; i<31; i++) {
			auto [eq, cnt] = seq[i].query(l, r);
			if (cnt > 1 and eq != -2 and sufand[i] == prefor[i]) ans = true;
			if (at > 0 and at < r-l+1 and sufand[i] == prefor[i-1]) ans = true;
			
			at += cnt;
		}

		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;

	}


	exit(0);
}
