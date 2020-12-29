#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define s second
#define f first

typedef long long ll;
typedef pair<int, int> ii;
// LCA com binary lifting
//
// Assume que um vertice eh ancestral dele mesmo, ou seja,
// se a eh ancestral de b, lca(a, b) = a
// MAX2 = ceil(log(MAX))
//
// Complexidades:
// build - O(n log(n))
// lca - O(log(n))

const int MAX = 1e4+10;
const int MAX2 = 14;

vector<vector<ii > > g(MAX);
int n, p;
int pai[MAX2][MAX];
int in[MAX], out[MAX];
int dist[MAX];
int prof[MAX];

void dfs(int k) {
	in[k] = p++;
	for (int i = 0; i < (int) g[k].size(); i++){
		int u = g[k][i].f, d = g[k][i].s;
		if (in[u] == -1) {
			pai[0][u] = k;
			prof[u] = prof[k]+d;
			dist[u] = dist[k]+1;
			dfs(u);
		}
	}
	out[k] = p++;
}
void build(int raiz) {
	for (int i = 0; i <=n; i++) pai[0][i] = i, prof[i]=0, dist[i] =0, in[i]=-1;
	p = 0;
	dfs(raiz);
	// pd dos pais
	for (int k = 1; k < MAX2; k++) for (int i = 0; i < n; i++){
		pai[k][i] = pai[k - 1][pai[k - 1][i]];
	}
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
int D(int a, int b){
	if(anc(a, b)) return prof[b] - prof[a];
	if(anc(b, a)) return prof[a] - prof[b];
	int lc = lca(a, b);
	return D(a, lc) + D(b, lc);
}
int K(int a, int b, int k){
	if(anc(b, a)){
		for (int k2 = MAX2 - 1; k2 >= 0; k2--){
			if(k==1) break;
			if ((1<<k2)<k) a = pai[k2][a], k-=(1<<k2);
		}
		return a;
	}	
	int c = lca(a, b);
	int tam = dist[a] - dist[c] + dist[b] - dist[c] + 1;
	if(anc(a, b)) return K(b, a, tam-k+1);
	if(dist[a] - dist[c]+1 >= k) return K(a, c, k);
	return K(b, c, tam-k+1);
}

int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i=0;i <n; i++) g[i].clear();
		for(int i=0;i <n-1; i++){
			int a, b, c; cin >> a >> b >> c; a--, b--;
			g[a].pb({b, c});
			g[b].pb({a, c});
		}
		build(0);
		while(true){
			string s; cin >> s;
			if(s=="DONE") break;
			int a, b; cin >> a >> b; a--, b--;
			if(s=="DIST") cout << D(a, b) << endl;
			else{
				int k; cin >> k;
				cout << K(a, b, k)+1 << endl;
			}
		}
		if(t) cout << endl;
	}
	exit(0);
}
