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

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

struct kuhn {
	int n, m;
	vector<vector<int>> g;
	vector<int> vis, ma, mb;

	kuhn(int n_, int m_) : n(n_), m(m_), g(n),
		vis(n+m), ma(n, -1), mb(m, -1) {}

	void add(int a, int b) { g[a].pb(b); }

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
	
	int n = 18;
	set<ii> st;
	kuhn K((1<<n)+10, (1<<n)+10);
	for(int i=0;i<(1<<n); i++){
		if(__builtin_popcount(i)%2 == 0){
			for(int j=0; j<n; j++){
				int y = i^(1<<j);
				if(st.count({i, y}) or st.count({y, i})) continue;
				st.insert({i, y});
				K.add(i, y);
			//	cout << i << " " << y << endl;
			}
		}
	}
	assert(K.matching()==(1<<(n-1)));
	int m; cin >> n >> m; n--;
	cout << (m+n-1)/n << endl;
		
	
	exit(0);
}
