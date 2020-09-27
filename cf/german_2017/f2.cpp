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
	int dfs2(int i){
		if(vis[i]) return 0;
		vis[i] = 1;
		int ret = 0;
		for (int j : g[i]) if (!vis[n+j]) {
			vis[n+j] = 1;
			if (mb[j] == -1) ret++;
			else ret+= dfs2(mb[j]);
		}
		return ret;
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

	int m, n, k; cin >> m >> n >> k;
	kuhn K(m, n);
	
	for(int i=0;i <k; i++){
		int a, b; cin >> a >> b; a--, b--;
		K.add(a, b);
	}
	int ans = K.matching();
	int l = 0;
//	cout << "MATCHING" << endl;
	for(int i=0;i <m; i++){
//		if(K.ma[i] != -1) cout << i+1 << " " << K.ma[i]+1 << endl;
		int at = 0;
		for(auto u : K.g[i])
			if(K.mb[u]==-1) at++;
		l = max(at, l);
	}
	if(l==1){
//		cout << "DFS" << endl;
		for(int i=0; i<m; i++) if(K.ma[i]!=-1){
			for(int i=0; i<n+m; i++) K.vis[i] = 0;
			l = max(l, K.dfs2(i));
			if(l>=2) break;
//			cout << i+1 << " " << l << endl;
		}
	}
//	cout << ans << endl;
	cout << ans + min(l, 2) << endl;

	exit(0);
}
