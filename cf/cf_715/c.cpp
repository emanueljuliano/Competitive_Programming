#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAGIC = 2e3+10;
const int MAX = 2e5+10;
vector<pair<int, int>> g[MAX];
int M[MAGIC][MAGIC];

#define f first
#define s second

namespace hld {
	vector<pair<int, int> > g[MAX];
	int pos[MAX], sz[MAX];
	int sobe[MAX], pai[MAX];
	int h[MAX], v[MAX], t;
	int men[MAX], seg[2*MAX];

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = sobe[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i.first != p) {
			sobe[i.first] = i.second; pai[i.first] = k;
			h[i.first] = (i == g[k][0] ? h[k] : i.first);
			men[i.first] = (i == g[k][0] ? min(men[k], i.second) : i.second);
			build_hld(i.first, k, f); sz[k] += sz[i.first];

			if (sz[i.first] > sz[g[k][0].first] or g[k][0].first == p)
				swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		for (int i = 0; i < t; i++) seg[i+t] = v[i];
		for (int i = t-1; i; i--) seg[i] = min(seg[2*i], seg[2*i+1]);
	}
	int query_path(int a, int b) {
		if (a == b) return INF;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] != h[b]) return min(men[a], query_path(pai[h[a]], b));
		int ans = INF, x = pos[b]+1+t, y = pos[a]+t;
		for (; x <= y; ++x/=2, --y/=2) ans = min({ans, seg[x], seg[y]});
		return ans;
	}
};

int id[MAX];
int f(int a) {
	if (a == id[a]) return a;
	return id[a] = f(id[a]);
}

void une(int a, int b) {
	a = f(a), b = f(b);
	id[a] = b;
}

void dsu_build() {
	for (int i=0;i <MAX; i++) id[i] = i;
}

int main(){ _
	dsu_build();
	int n, m; cin >> n >> m;
	int x = 0;
	ll ans = 0;
	if (n < MAGIC) {
		for (int i=0; i<m; i++) {
			int a, b, c; cin >> a >> b >> c; a--, b--;
			M[a][b] = M[b][a] = c;
			x ^= c;
		}
		
		vector<tuple<int, int, int>> eg;
		for (int i=0;i <n; i++) for (int j=i+1; j<n; j++) {
			if (M[i][j]) eg.push_back({M[i][j], i, j});
			else eg.push_back({0, i, j});
		}
		
		sort(eg.begin(), eg.end());
		vector<tuple<int, int, int>> res;
		int tot = n*(n-1)/2 - m;
		for (auto [c, a, b] : eg) {
			if (f(a) != f(b)){
				hld::g[a].push_back({b, c});
				hld::g[b].push_back({a, c});
				ans += c; une(a, b);
				if (c == 0) tot--;
			}
			else res.push_back({c, a, b});
		}
		hld::build();	
		sort(res.begin(), res.end());
		
		for (auto [c, a, b] : res) {
			if (!hld::query_path(a, b)) {
				if (c < x) ans += c;
				else ans += x;
				break;
			}
		}
		cout << ans << endl;
	}
	else {
		vector<tuple<int, int, int>> eg;
		for (int i=0;i <m; i++) {
			int a, b, c; cin >> a >> b >> c; a--, b--;
			g[a].push_back({b, c});
			g[b].push_back({a, c});
			eg.push_back({c, a, b});
		}

		vector<int> v(n);
		iota(v.begin(), v.end(), 0);
		sort(v.begin(), v.end(), [&](int a, int b){
			return g[a].size() < g[b].size();});

		for (auto u : v) {
			if (g[u].size() < sqrt(n)) une(u, v[0]);
			else {
				sort(g[u].begin(), g[u].end());
				int it = 0;
				for (int i=0; i<n; i++) {
					if (it<g[u].size() and i == g[u][it].first) it++;
					else une(u, i);
				}
			}
		}
		sort(eg.begin(), eg.end());
		for (auto [c, a, b] : eg) {
			if (f(a) != f(b)) une(a, b), ans += c;		
		}
		
		cout << ans << endl;
	}

	
	
	exit(0);
}
