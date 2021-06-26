#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 2e5+10;

template<typename T> struct color {
	set<tuple<int, int, T>> se;

	vector<tuple<int, int, T>> update(int l, int r, T val) {
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
		vector<tuple<int, int, T>> ret;
		for (; it != se.end() and get<0>(*it) <= r; it = se.erase(it))
			ret.push_back(*it);
		se.emplace(l, r, val);
		return ret;
	}
	T query(int i) {
		auto it = se.upper_bound({i, INF, T()});
		if (it == se.begin() or get<1>(*--it) < i) return -1; // nao tem
		return get<2>(*it);
	}
};

namespace hld {
	vector<pair<int, int> > g[MAX];
	int pos[MAX], sz[MAX];
	int sobe[MAX], pai[MAX];
	int h[MAX], v[MAX], t;
	color<int> C;
	int f[MAX], ff[MAX];

	void build_hld(int k, int p = -1, int fi = 1) {
		v[pos[k] = t++] = sobe[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i.first != p) {
			auto [u, w] = i;
			sobe[u] = w; pai[u] = k;
			h[u] = (i == g[k][0] ? h[k] : u);
			build_hld(u, k, fi); sz[k] += sz[u];

			if (sz[u] > sz[g[k][0].first] or g[k][0].first == p)
				swap(i, g[k][0]);
		}
		if (p*fi == -1) build_hld(h[k] = k, -1, t = 0);
	}
	
	void build(int m, int root = 0) {
		t = 0;
		build_hld(root);
		ff[0] = m;
	}
	
	void update_path(int a, int b, int x) {
		if (a == b) return;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) {
			ff[f[x]]--, f[x] += pos[a]-pos[b], ff[f[x]]++;
			for (auto [l, r, c] : C.update(pos[b]+1, pos[a], x)) {
				ff[f[c]]--, f[c] -= r-l+1, ff[f[c]]++;
			}
			return;
		}
		ff[f[x]]--, f[x] += pos[a]-pos[h[a]]+1, ff[f[x]]++;
		for (auto [l, r, c] : C.update(pos[h[a]], pos[a], x)) {
			ff[f[c]]--, f[c] -= r-l+1, ff[f[c]]++;
		}
		update_path(pai[h[a]], b, x);
	}
	
	int update(int a, int x, int m) {
		update_path(a, 0, x);
		return ff[m];
	}
}

int main(){ _
	int n, C, q; cin >> n >> C >> q;

	for (int i=0; i<n-1; i++){
		int a, b; cin >> a >> b; a--, b--;
		hld::g[a].push_back({b, 0});
		hld::g[b].push_back({a, 0});
	}
	hld::build(C);

	while(q--){
		int u, c, m; cin >> u >> c >> m; u--;
		cout << hld::update(u, c, m) << endl;
	}

	
	exit(0);
}
