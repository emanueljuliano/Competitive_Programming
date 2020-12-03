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

const int MAX = 5e5+10;
int d[MAX], p[MAX], pp[MAX], depth[MAX];

void set_root(int i) { p[i] = pp[i] = i, d[i] = 0, depth[i]=0; }

void add_leaf(int i, int u) {
	p[i] = u, d[i] = d[u]+1, depth[i]=depth[u]+1;
	pp[i] = 2*d[pp[u]] == d[pp[pp[u]]]+d[u] ? pp[pp[u]] : u;
}

int kth(int i, int k) {
	int dd = max(0, d[i]-k);
	while (d[i] > dd) i = d[pp[i]] >= dd ? pp[i] : p[i];
	return i;
}

int lca(int a, int b) {
	if (d[a] < d[b]) swap(a, b);
	while (d[a] > d[b]) a = d[pp[a]] >= d[b] ? pp[a] : p[a];
	while (a != b) {
		if (pp[a] != pp[b]) a = pp[a], b = pp[b];
		else a = p[a], b = p[b];
	}
	return a;
}

int dist(int a, int b) { return d[a]+d[b]-2*d[lca(a,b)]; }

vector<int> g[MAX];

void build(int i, int pai=-1) {
	if (pai == -1) set_root(i);
	for (int j : g[i]) if (j != pai) {
		add_leaf(j, i);
		build(j, i);
	}
}
int tam[MAX];
int main(){ _
	int n; cin >> n;
	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].pb(b), g[b].pb(a);
	}
	build(0);
	int t; cin >> t;
	while(t--){
		int k; cin >> k;
		vector<int> c(k), v(k);
		for(auto &i:v) cin >> i, i--;
		for(auto &i:c) cin >> i;
		
		vector<int> dp(k+1);
		for(int i=1; i<=k; i++){
			dp[i] = INF;
			for(int j=1; j<=i; j++) dp[i] = min(dp[i], c[j-1]+dp[i-j]);
		}
		set<ii> st;
		for(auto u : v) if(u) st.insert({depth[u], u}), tam[u]++;
		ll ans = 0;
		while(st.size()){
			auto [d1, u] = *st.rbegin(); st.erase({d1, u});
			
			int lc = 0;
			for(auto [d2, w] : st){
				int aux = lca(u, w);
				if(depth[aux] > depth[lc]) lc = aux;
			}
			ans += (depth[u] - depth[lc])*dp[tam[u]];
			if(lc) st.insert({depth[lc], lc}), tam[lc] += tam[u];
			tam[u] = 0;
		}
		cout << ans << endl;
	}
	
	
	exit(0);
}
