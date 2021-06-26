#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e5+10;

namespace color {
	set<tuple<int, int, int>> se;

	vector<tuple<int, int, int>> update(int l, int r, int val) {
		auto it = se.upper_bound({r, INF, val});
		if (it != se.begin() and get<1>(*prev(it)) > r) {
			auto [L, R, V] = *--it;
			se.erase(it);
			se.emplace(L, r, V), se.emplace(r+1, R, V);
		}
		it = se.lower_bound({l, -INF, val});
		if (it != se.begin() and get<1>(*prev(it)) >= l) {
			auto [L, R, V] = *--it;
			se.erase(it);
			se.emplace(L, l-1, V), it = se.emplace(l, R, V).first;
		}
		vector<tuple<int, int, int>> ret;
		for (; it != se.end() and get<0>(*it) <= r; it = se.erase(it))
			ret.push_back(*it);
		se.emplace(l, r, val);
		return ret;
	}
	void build(int n) {
		update(0, n-1, 0);
	}
	int query(int i) {
		auto it = se.upper_bound({i, INF, int()});
		if (it == se.begin() or get<1>(*--it) < i) return -1; // nao tem
		return get<2>(*it);
	}
};

namespace hld {
	vector<int> g[MAX];
	int pos[MAX], sz[MAX];
	int peso[MAX], pai[MAX];
	int h[MAX], v[MAX], t;

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = peso[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i != p) {
			pai[i] = k;
			h[i] = (i == g[k][0] ? h[k] : i);
			build_hld(i, k, f); sz[k] += sz[i];

			if (sz[i] > sz[g[k][0]] or g[k][0] == p) swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		color::build(t);
	}
	ll query_path(int a) {
		return color::query(pos[a]);
	}
	void update_path(int a, int b, int x, vector<tuple<int, int, int>> &w) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) {
			for (auto u : color::update(pos[b], pos[a], x)) w.push_back(u);
			return;
		}
		for (auto u : color::update(pos[h[a]], pos[a], x)) w.push_back(u);
		update_path(pai[h[a]], b, x, w);
	}
	int lca(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);
		return h[a] == h[b] ? b : lca(pai[h[a]], b);
	}
}

int dist[MAX];
void dfs(int i, int p) {
	for (auto u : hld::g[i]) if (u != p) dist[u] = dist[i]+1, dfs(u, i);
}

bool ord(pair<int, int> a, pair<int, int> b) {
	int da = dist[a.first] + dist[a.second] - 2*dist[hld::lca(a.first, a.second)];
	int db = dist[b.first] + dist[b.second] - 2*dist[hld::lca(b.first, b.second)];
	return (da > db);
}

int main(){ _
	int n, q; cin >> n >> q;
	for (int i=0; i<n-1; i++) {
		int a, b; cin >> a >> b; a--, b--;
		hld::g[a].push_back(b);
		hld::g[b].push_back(a);
	}
	hld::build();
	dfs(0, 0);

	vector<pair<int, int>> query;
	for (int i=0; i<q; i++) {
		int a, b; cin >> a >> b; a--, b--;
		query.push_back({a, b});
	}

	sort(query.begin(), query.end(), ord);

	bool can = true;
	int color = 1;
	for (auto [a, b] : query) {
		//cout << "QUERY " << a << " " << b << endl;
		vector<tuple<int, int, int>> v;
		hld::update_path(a, b, color++, v);
		set<int> st;
		for (auto [l, r, c] : v) st.insert(c);
		if (st.size() > 1) can = false;
	}

	if (can) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	
	exit(0);
}
