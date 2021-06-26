#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

struct kuhn {
	int n, m;
	vector<vector<int>> g;
	vector<int> vis, ma, mb;

	kuhn(int n_, int m_) : n(n_), m(m_), g(n),
		vis(n+m), ma(n, -1), mb(m, -1) {}

	void add(int a, int b) { g[a].push_back(b); }

	bool dfs(int i) {
		vis[i] = 1;
		for (int j : g[i]) if (!vis[n+j]) {
			vis[n+j] = 1;
			if (mb[j] == -1 or dfs(mb[j])) {
				ma[i] = j, mb[j] = i;
				return true;
			}
		}
		return false;
	}
	int matching() {
		int ret = 0, aum = 1;
		for (auto& i : g) shuffle(i.begin(), i.end(), rng);
		while (aum) {
			for (int j = 0; j < m; j++) vis[n+j] = 0;
			aum = 0;
			for (int i = 0; i < n; i++)
				if (ma[i] == -1 and dfs(i)) ret++, aum = 1;
		}
		return ret;
	}
};


int main(){ _
	int n, m, a, b;
	while (cin >> n >> m >> a >> b) {
		a--, b--;
		kuhn K(2*n, m);
		for (int i=0; i<m; i++) {
			int u, v; cin >> u >> v; u--, v--;
			
			// every vertex has indegree 1, except a
			if (v != a) K.add(v, i); 
			
			// every vertex has outegree 1, except b
			if (u != b) K.add(u+n, i);
		}
		//K.add(a, 2*n+m);
		//K.add(b, 2*n+m);

		int matching = K.matching();

		if (matching != 2*n-2) 
			cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			vector<int> ea, eb;
			for (int i=0; i<n; i++) {
				if (i != a) ea.push_back(K.ma[i]+1);
				if (i != b) eb.push_back(K.ma[i+n]+1);
			}
			
			for (auto u : ea) cout << u << " ";
			cout << endl;
			for (auto u : eb) cout << u << " ";
			cout << endl;
		}
	}
	
	
	
	exit(0);
}
