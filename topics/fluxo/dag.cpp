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
};

int main(){ _
	int n, m; cin >> n >> m;
	
	kuhn K(n, n);
	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b; a--, b--;
		K.add(a, b);
	}
	int x = K.matching();
	cout << n -x << endl;

	vector<int> path(n);
	vector<int> ini(n, 1);
	for(int i=0;i <n; i++) path[i] = i;
	for(int i=0;i <n; i++) if(K.ma[i]!=-1){
		path[i] = K.ma[i];
		ini[K.ma[i]]= 0;
	}

	for(int i=0;i <n; i++){
		if(ini[i]){
			int a = i;
			cout << a+1 << " ";
			while(a != path[a]){
				a= path[a];
				cout << a+1 << " ";
			}
			cout << endl;
		}
	}




	exit(0);
}
