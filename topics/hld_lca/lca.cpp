#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

// LCA com binary lifting
//
// Assume que um vertice eh ancestral dele mesmo, ou seja,
// se a eh ancestral de b, lca(a, b) = a
// MAX2 = ceil(log(MAX))
//
// Complexidades:
// build - O(n log(n))
// lca - O(log(n))

const int MAX = 1e5+10;
const int MAX2 = 20;

vector<vector<int> > g(MAX);
int n, p;
int pai[MAX2][MAX];
int in[MAX], out[MAX];

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

int main(){ _
	int t; cin>> t;
	int cs = 0;
	while(t--){
		cs++;
		cout << "Case " << cs << ":" << endl;
		cin >> n;
		for(int i=0;i <n; i++){
			int m; cin >> m;
			for(int j=0;j <m; j++){
				int a; cin >> a; a--;
				g[a].pb(i);
				g[i].pb(a);
			}
		}
		build(0);
		int q; cin >> q;
		while(q--){
			int a, b; cin >> a >> b; a--, b--;
			cout << lca(a, b)+1 << endl;
		}
	}

	exit(0);
}
