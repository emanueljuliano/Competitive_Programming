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
	pair<vector<int>, vector<int>> cover() {
		int M = matching();
		for (int i = 0; i < n+m; i++) vis[i] = 0;
		for (int i = 0; i < n; i++) if (ma[i] == -1) assert(!dfs(i));
		vector<int> ca, cb;
		for (int i = 0; i < n; i++) if (!vis[i]) ca.push_back(i);
		for (int i = 0; i < m; i++) if (vis[n+i]) cb.push_back(i);
		//assert(ca.size() + cb.size() == M);
		return {ca, cb};
	}
};

int main(){ _

	int n, m; cin >> n >> m;
	kuhn g(n, m);
	for(int i=0;i <n; i++){
		int x; cin >> x;
		for(int j=0; j<x; j++) {
			int a; cin >> a; a--;
			g.add(i, a);
		}
	}
	int tot = 0;
	for(int i=0; i<n; i++){
		int a; cin >> a; tot += (a!=0);
	}
	int ans = g.matching();
	if(tot == ans) cout << "YES" << endl;
	else{
		cout << "NO" << endl;
		cout << ans << endl;
		for(int i=0;i <n; i++) if(g.ma[i]!=-1){
			cout << i+1 << " " << g.ma[i]+1 << endl;
		}
	}


	exit(0);
}
