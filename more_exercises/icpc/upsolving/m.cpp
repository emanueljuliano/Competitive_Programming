#include <bits/stdc++.h>
//
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

template <typename T = int> struct ms_tree {
	vector<tuple<T, T, int>> v;
	int n;
	vector<vector<tuple<T, int, int>>> t; // {y, idx, left}
	vector<T> vy;

	ms_tree(vector<pair<T, T>>& vv) : n(vv.size()), t(4*n), vy(n) {
		for (int i = 0; i < n; i++) v.push_back({vv[i].first, vv[i].second, i});
		sort(v.begin(), v.end());
		build(1, 0, n-1);
		for (int i = 0; i < n; i++) vy[i] = get<0>(t[1][i+1]);
	}
	ms_tree(vector<T>& vv, bool inv = false) { // inv: inverte indice e valor
		vector<pair<T, T>> v2;
		for (int i = 0; i < vv.size(); i++)
			inv ? v2.push_back({vv[i], i}) : v2.push_back({i, vv[i]});
		*this = ms_tree(v2);
	}
	void build(int p, int l, int r) {
		t[p].push_back({get<0>(v[l]), get<0>(v[r]), 0}); // {min_x, max_x, 0}
		if (l == r) return t[p].push_back({get<1>(v[l]), get<2>(v[l]), 0});
		int m = (l+r)/2;
		build(2*p, l, m), build(2*p+1, m+1, r);

		int L = 0, R = 0;
		while (t[p].size() <= r-l+1) {
			int left = get<2>(t[p].back());
			if (L > m-l or (R+m+1 <= r and t[2*p+1][1+R] < t[2*p][1+L])) {
				t[p].push_back(t[2*p+1][1 + R++]);
				get<2>(t[p].back()) = left;
				continue;
			}
			t[p].push_back(t[2*p][1 + L++]);
			get<2>(t[p].back()) = left+1;
		}
	}

	int get_l(T y) { return lower_bound(vy.begin(), vy.end(), y) - vy.begin(); }
	int get_r(T y) { return upper_bound(vy.begin(), vy.end(), y) - vy.begin(); }

	int count(T x1, T x2, T y1, T y2) {
		function<int(int, int, int)> dfs = [&](int p, int l, int r) {
			if (l == r or x2 < get<0>(t[p][0]) or get<1>(t[p][0]) < x1) return 0;
			if (x1 <= get<0>(t[p][0]) and get<1>(t[p][0]) <= x2) return r-l;
			int nl = get<2>(t[p][l]), nr = get<2>(t[p][r]);
			return dfs(2*p, nl, nr) + dfs(2*p+1, l-nl, r-nr);
		};
		return dfs(1, get_l(y1), get_r(y2));
	}
	vector<int> report(T x1, T x2, T y1, T y2) {
		vector<int> ret;
		function<void(int, int, int)> dfs = [&](int p, int l, int r) {
			if (l == r or x2 < get<0>(t[p][0]) or get<1>(t[p][0]) < x1) return;
			if (x1 <= get<0>(t[p][0]) and get<1>(t[p][0]) <= x2) {
				for (int i = l; i < r; i++) ret.push_back(get<1>(t[p][i+1]));
				return;
			}
			int nl = get<2>(t[p][l]), nr = get<2>(t[p][r]);
			dfs(2*p, nl, nr), dfs(2*p+1, l-nl, r-nr);
		};
		dfs(1, get_l(y1), get_r(y2));
		return ret;
	}
	int kth(T y1, T y2, int k) {
		function<int(int, int, int)> dfs = [&](int p, int l, int r) {
			if (k >= r-l) {
				k -= r-l;
				return -1;
			}
			if (r-l == 1) return get<1>(t[p][l+1]);
			int nl = get<2>(t[p][l]), nr = get<2>(t[p][r]);
			int left = dfs(2*p, nl, nr);
			if (left != -1) return left;
			return dfs(2*p+1, l-nl, r-nr);
		};
		return dfs(1, get_l(y1), get_r(y2));
	}
};

const int MOD = 1e9+7;
const int base = 5782344;
ll pow(ll x, ll y, ll m) { // iterativo
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % m;
		y >>= 1;
		x = (x * x) % m;
	}
	return ret;
}

int main(){ _
	int n, q; cin >> n >> q;
	vector<ii> v(n);
	for(auto &i : v) cin >> i.f >> i.s, i.s*=2;
	for(auto &i : v) {
		ii ni = i;
		ni.f = i.f-i.s;
		ni.s = i.f+i.s;
		i = ni;
	}
	ms_tree<ll> T(v);
	
	ll p =0;
	for(ll i=0; i<q; i++){
		ii a; cin >> a.f >> a.s;
		a.f = -1-(p+a.f)%MOD;
		a.s = (p+a.s)%MOD;
		a.s*=2;
		ii na = a;
		na.f = a.f-a.s;
		na.s = a.f+a.s;
		a = na;
		vector<int> w = T.report(a.f, LINF, a.s, LINF);
		sort(w.begin(), w.end());
		p = 0;
		for(int j=0; j<w.size(); j++) p = (p+(w[j]+1)*pow(base, j, MOD))%MOD;
		cout << p << endl;
	}

	
	
	exit(0);
}
