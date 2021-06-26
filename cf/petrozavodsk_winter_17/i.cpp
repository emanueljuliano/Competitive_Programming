#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 4e5+10;
vector<int> suffix_array(string s) {
	s += "$";
	int n = s.size(), N = max(n, 260);
	vector<int> sa(n), ra(n);
	for(int i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];

	for(int k = 0; k < n; k ? k *= 2 : k++) {
		vector<int> nsa(sa), nra(n), cnt(N);

		for(int i = 0; i < n; i++) nsa[i] = (nsa[i]-k+n)%n, cnt[ra[i]]++;
		for(int i = 1; i < N; i++) cnt[i] += cnt[i-1];
		for(int i = n-1; i+1; i--) sa[--cnt[ra[nsa[i]]]] = nsa[i];

		for(int i = 1, r = 0; i < n; i++) nra[sa[i]] = r += ra[sa[i]] !=
			ra[sa[i-1]] or ra[(sa[i]+k)%n] != ra[(sa[i-1]+k)%n];
		ra = nra;
		if (ra[sa[n-1]] == n-1) break;
	}
	return vector<int>(sa.begin()+1, sa.end());
}

vector<int> kasai(string s, vector<int> sa) {
	int n = s.size(), k = 0;
	vector<int> ra(n), lcp(n);
	for (int i = 0; i < n; i++) ra[sa[i]] = i;

	for (int i = 0; i < n; i++, k -= !!k) {
		if (ra[i] == n-1) { k = 0; continue; }
		int j = sa[ra[i]+1];
		while (i+k < n and j+k < n and s[i+k] == s[j+k]) k++;
		lcp[ra[i]] = k;
	}
	return lcp;
}

namespace seg {
	ll seg[4*MAX];
	int n; vector<int> v;

	ll build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, vector<int> &v2) {
		n = n2, v = v2;
		build();
	}
	int get_right(int a, int b, int val, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a or seg[p] > val) return -1;
		if (r == l) return l;
		int m = (l+r)/2;
		int x = get_right(a, b, val, 2*p+1, m+1, r);
		if (x != -1) return x;
		return get_right(a, b, val, 2*p, l, m);
	}

};

int main(){ _
	int n, q; cin >> n >> q;
	string s; cin >> s;

	vector<int> sa = suffix_array(s);
	vector<int> ka = kasai(s, sa);
	vector<int> pos(n);
	for (int i=0; i<n; i++) pos[sa[i]] = i;
	seg::build(ka.size(), ka);
	
	while (q--) {
		ll k, m; cin >> k >> m;

		vector<pair<int, int>> v;
		for (int i=0; i<k; i++) {
			int l, r; cin >> l >> r; l--, r--;
			int tam = r-l;
			l = pos[l];
			int li = seg::get_right(0, l-1, tam) + 1;
			l = min(l, li);
			v.push_back({l, tam});
		}
		sort(v.begin(), v.end());
		
		stack<int> stk;
		vector<vector<int>> g(k+1);
		for (int i=0; i<k; i++) {
			auto [l, tam] = v[i];
			while (!stk.empty()) {
				auto [l2, t2] = v[stk.top()];
				if (l == l2 or seg::get_right(l2, l-1, t2) == -1) {
					g[stk.top()].push_back(i);
					break;
				}
				stk.pop();
			}
			if (!stk.size()) g[k].push_back(i);
			stk.push(i);
		}
		
/*		for (int i=0; i<k; i++) {
			cout << i << " " << s.substr(sa[v[i].first], v[i].second+1) << ": ";
			for (auto u : g[i]) cout << u << " ";
			cout << endl;
		}
*/
		function<ll(int)> dfs = [&] (int x) {
			ll ret = 1;
			for (auto u : g[x]) 
				ret = (ret * dfs(u))%m;
			ret = (ret+1)%m;
			return ret;
		};
		
		ll ans = (dfs(k)+2*m-1)%m;
		cout << ans << endl;
	}

	exit(0);
}
