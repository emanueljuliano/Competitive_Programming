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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e5+10;
int d[MAX], p[MAX], pp[MAX], id[MAX];

void set_root(int i) { p[i] = pp[i] = i, d[i] = 0; }

void add_leaf(int i, int u) {
	p[i] = u, d[i] = d[u]+1;
	pp[i] = 2*d[pp[u]] == d[pp[pp[u]]]+d[u] ? pp[pp[u]] : u;
}

vector<int> g[MAX];

void build(int i, int pai=-1) {
	if (pai == -1) set_root(i);
	for (int j : g[i]) if (j != pai) {
		add_leaf(j, i);
		build(j, i);
	}
}

vector<vector<ii>> query(MAX);
int pt = 0;
void add(int v, int l, int r){
	while(id[v] <= r){
		if(!v) break;
		else if(id[pp[v]] <=r) v = pp[v];
		else if(id[p[v]] <= r) v = p[v];
		else break;
	}
	query[v].pb({l, pt++});
}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

ord_set<ii> st;
vector<int> ans(MAX);
void dfs2(int v){
	for(auto a : query[v]) st.insert(a);
	ans[v] = st.order_of_key({id[v], pt});
	for(auto w : g[v]) if(w != p[v]) dfs2(w);
	for(auto a : query[v]) st.erase(a);
}

int main(){ _
	int n, m; cin >> n >> m;
	for(int i=0;i <n; i++){
		int a, b; cin >> a >> b; b--;
		if(i) g[i].pb(b), g[b].pb(i);
		id[i] = a;
	}
	build(0);
	for(int i=0;i <m; i++){
		int o, l, r; cin >> o >> l >> r; o--;
		add(o, l, r);
	}
	dfs2(0);
	ans.resize(n);
	for(auto u : ans) cout << u << " ";
	cout << endl;
	
	exit(0);
}
