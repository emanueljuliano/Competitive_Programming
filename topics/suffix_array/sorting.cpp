#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

template<typename T> struct rmq {
	vector<T> v;
	int n; static const int b = 30;
	vector<int> mask, t;

	int op(int x, int y) { return v[x] < v[y] ? x : y; }
	int msb(int x) { return __builtin_clz(1)-__builtin_clz(x); }
	int small(int r, int sz = b) { return r-msb(mask[r]&((1<<sz)-1)); }
	rmq(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
		for (int i = 0, at = 0; i < n; mask[i++] = at |= 1) {
			at = (at<<1)&((1<<b)-1);
			while (at and op(i, i-msb(at&-at)) == i) at ^= at&-at;
		}
		for (int i = 0; i < n/b; i++) t[i] = small(b*i+b-1);
		for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
			t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
	}
	T query(int l, int r) {
		if (r-l+1 <= b) return v[small(r, r-l+1)];
		int ans = op(small(l+b-1), small(r));
		int x = l/b+1, y = r/b-1;
		if (x <= y) {
			int j = msb(y-x+1);
			ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
		}
		return v[ans];
	}
};

void radix(vector<int> &p, vector<int> &c){
	int n = p.size();
	vector<int> cnt(n);
	for(auto x : c) cnt[x]++;
	vector<int> pos(n);
	pos[0] = 0;
	for(int i=1; i<n; i++) pos[i] = pos[i-1] + cnt[i-1];
	vector<int> p_new(n);
	for(auto x : p) p_new[pos[c[x]]++] = x;
	p = p_new;
}

int main(){ _
	string s; cin >> s;
	s.pb(1);
	int n = s.size();

	vector<int> p(n), c(n); // p=prefix, c=equivalence
	{
		// k = 0
		vector<pair<char, int>> a(n);
		for(int i=0; i<n; i++) a[i] = {s[i], i};
		sort(a.begin(), a.end());
		for(int i=0;i <n; i++) p[i] = a[i].s;
		c[p[0]] = 0;
		for(int i=1; i<n; i++){
			if(a[i].f != a[i-1].f) c[p[i]] = c[p[i-1]]+1;
			else c[p[i]] = c[p[i-1]];
		}
	}
	int k = 0;
	while(1<<k < n){
		for(int i=0;i <n; i++) p[i] = (p[i] - (1<<k) + n)%n;
		radix(p, c);
		vector<int> c_new(n);
		c_new[p[0]] = 0;
		ii bef = {c[p[0]], c[(p[0] + (1<<k))%n]};
		for(int i=1; i<n; i++){
			ii at = {c[p[i]], c[(p[i] + (1<<k))%n]};
			if(at != bef) c_new[p[i]] = c_new[p[i-1]]+1;
			else c_new[p[i]] = c_new[p[i-1]];
			bef = at;
		}
		c = c_new;
		k++;
	}

	k = 0;
	vector<int> lcp(n);
	for(int i=0;i <n-1; i++){
		int pi = c[i];
		int j = p[pi-1];
		while(s[i+k]==s[j+k]) k++;

		lcp[pi] = k;
		k = max(k-1, 0);
	}

	int q; cin >> q;
	vector<pair<ii, ii>> v;
	rmq <int> R(lcp);
	while(q--){
		int a, b; cin >> a >> b; a--, b--;
		int d = b-a+1;
		int l = 0, r = c[a];
//		cout << "query" << endl;
//		cout << l << " " << r << endl;
		while(l<r){
			int m = (l+r)/2;
			int x = R.query(m+1, r);
//			cout << m << " mx " << x << endl;
			if(x < d) l = m+1;
			else r = m;
		}

		v.pb({{l, d}, {a, b}});
	}
	sort(v.begin(), v.end());
//	cout << "ANS" << endl;
	for(auto P : v) cout << P.s.f+1 << " " << P.s.s+1 << endl;

	exit(0);
}
