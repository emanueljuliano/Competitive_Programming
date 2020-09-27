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

const int MAX = 30;
int id[MAX], sz[MAX];
int find(int p){
	if(id[p]==p) return p;
	return id[p] = find(id[p]);
}

void une(int p, int q){
	p = find(p), q = find(q);
	if(p==q) return;

	if(sz[p]>sz[q]) swap(p, q);
	sz[q] += sz[p];
	id[p] = q;
}

void build(int n){
	for(int i=0;i <n; i++) id[i]=i, sz[i]=1;
}

int main(){ _
	int n; cin >> n;
	map<char, int> mp;
	int ptr = 0;
	vector<string> va, vb;
	for(int i=0;i <n; i++){
		string s; cin >> s;
		
		build(s.size());
		for(int j=0; j<s.size(); j++){
			if(!mp.count(s[j])) mp[s[j]] = ptr++;
			if(j != mp[s[j]]){
				une(j, mp[s[j]]);
			}
		}

		int trans = 0;
		vector<int> vis(s.size());
		for(int j=0;j <s.size(); j++){
			int p = find(j);
			if(!vis[p] and sz[p]>1) trans += sz[p]-1, vis[p]=1;
		}

		if(trans%2==0) va.pb(s);
		else vb.pb(s);
		
	}

	kuhn K(va.size(), vb.size());

	for(int i=0;i <va.size(); i++){
		for(int j=0; j<vb.size(); j++){
			int dif = 0;
			for(int k=0; k<va[i].size(); k++){
				if(va[i][k] != vb[j][k]) dif++;
			}
			if(dif==2) K.add(i, j);
		}
	}

	int ans = n - K.matching();
	cout << ans << endl;


	exit(0);
}
