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

// LCA com binary lifting
//
// Assume que um vertice eh ancestral dele mesmo, ou seja,
// se a eh ancestral de b, lca(a, b) = a
// MAX2 = ceil(log(MAX))
//
// Complexidades:
// build - O(n log(n))
// lca - O(log(n))

const int MAX = 2e5+10;
const int MAX2 = 18;


vector<vector<int> > g(MAX);
int n, p;
int pai[MAX2][MAX];
int in[MAX], out[MAX], dist[MAX];
void dfs2(int k) {
	for (int i = 0; i < (int) g[k].size(); i++)
		if (dist[g[k][i]] == -1) {
			dist[g[k][i]] = dist[k]+1;
			dfs2(g[k][i]);
		}
}


void dfs(int k) {
	in[k] = p++;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (in[g[k][i]] == -1) {
			pai[0][g[k][i]] = k;
			dfs(g[k][i]);
		}
	out[k] = p++;
}

void build(int raiz) {
	for (int i = 0; i < n; i++) pai[0][i] = i;
	p = 0, memset(in, -1, sizeof in);
	dfs(raiz);

	// pd dos pais
	for (int k = 1; k < MAX2; k++) for (int i = 0; i < n; i++)
		pai[k][i] = pai[k - 1][pai[k - 1][i]];
}

bool anc(int a, int b) { // se a eh ancestral de b
	return in[a] <= in[b] and out[a] >= out[b];
}

int lca(int a, int b) {
	if (anc(a, b)) return a;
	if (anc(b, a)) return b;

	// sobe a
	for (int k = MAX2 - 1; k >= 0; k--)
		if (!anc(pai[k][a], b)) a = pai[k][a];

	return pai[0][a];
}

bool show(int a, int b){
	if(anc(a, b)) return true;
//	cout << a << " " << b << " " << lca(a, b) << endl;
	if(lca(a, b) == pai[0][a]) return true;
	return false;
}

int main(){ _
	int k; cin >> n >> k;
	for(int i=0; i<n-1; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}		
	build(0);
	memset(dist, -1, sizeof(dist));
	dist[0] = 0;
	dfs2(0);

	for(int i=0; i<k; i++){
		int sz; cin >> sz;
		bool ans = true;
		vector<int> w;
		int esc=-1;
		for(int i=0; i<sz; i++){
			int a; cin >> a; a--;w.pb(a);
			if(esc==-1) esc = a;
			if(dist[a]>dist[esc]) esc = a;
		}
		for(int i=0; i<sz; i++){
			if(!show(w[i], esc)) ans = false;
		}
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	exit(0);
}
