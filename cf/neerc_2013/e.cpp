#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 5e5 + 10;

namespace seg1 {
	int seg[2 * MAX];
	int n;
	void build() {
		for (int i = n - 1; i; i--) seg[i] = seg[2*i] + seg[2*i+1];
	}
	int query(int a, int b) {
		int ret = 0;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret += seg[a];
			if (b % 2 == 0) ret += seg[b];
		}
		return ret;
	}
	void update(int p, int x) {
		seg[p += n] += x;
		while (p /= 2) seg[p] = seg[2*p] + seg[2*p+1];
	}
}

namespace seg2 {
	pair<int, int> seg[2 * MAX];
	int n;
	void build() {
		for (int i = n - 1; i; i--) seg[i] = min(seg[2*i], seg[2*i+1]);
	}
	pair<int, int> query(int a, int b) {
		pair<int, int> ret = {INF, INF};
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret = min(ret, seg[a]);
			if (b % 2 == 0) ret = min(ret, seg[b]);
		}
		return ret;
	}
	void update(int p, int x) {
		seg[p+n] = {x, p};
		p+=n;
		while (p /= 2) seg[p] = min(seg[2*p], seg[2*p+1]);
	}
}



int main(){ _
	int n, q; cin >> n >> q;
	int pt = 0;
	map<int, int> mp;
	vector<int> v(n);
	for (auto &i : v) cin >> i;
	vector<int> w = v;
	sort(w.begin(), w.end());
	for (auto &u : w) if (!mp.count(u)) mp[u] = pt++;
	for (auto &u : v) u = mp[u];

	vector<int> inv(n);
	ll tot = 0;
	seg1::n = n, seg2::n = n;
	for (int i=n-1; i+1; i--) {
		tot += inv[i] = seg1::query(0, v[i]-1);
		seg1::update(v[i], 1);
		seg2::seg[i+n] = {v[i], i};
	}
	
	seg2::build();
	cout << tot << endl;
	while (q--) {
		int p; cin >> p; p--;
		while (true) {
			auto [mini, mpos] = seg2::query(p, n-1);
			if (mini > v[p]) break;
			tot -= inv[mpos];
			seg2::update(mpos, INF);
		}
		cout << tot << endl;
	}

	exit(0);
}
