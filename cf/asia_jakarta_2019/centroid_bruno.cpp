// Centroid decomposition
//
// Computa pai[i] = pai de i na arv. da centroid
// Descomentar o codigo comentado para computar
// dist[i][x] = distancia na arv. original entre o i e
// o x-esimo ancestral na arv. da centroid
//
// O(n log(n))

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
const int MAX = 4e3+10;

int n;
vector<int> g[MAX];
int subsize[MAX];
int rem[MAX];
int pai[MAX];

void dfs(int k, int last) {
	subsize[k] = 1;
	for (int i : g[k])
		if (i != last and !rem[i]) {
			dfs(i, k);
			subsize[k] += subsize[i];
		}
}

int centroid(int k, int last, int size) {
	for (int i : g[k]) {
		if (rem[i] or i == last) continue;
		if (subsize[i] > size / 2)
			return centroid(i, k, size);
	}
	// k eh o centroid
	return k;
}

//vector<int> dist[MAX];
//void dfs_dist(int k, int last, int d=0) {
//    dist[k].push_back(d);
//    for (int j : g[k]) if (j != last and !rem[j])
//        dfs_dist(j, k, d+1);
//}

void decomp(int k, int last = -1) {
	dfs(k, k);

	// acha e tira o centroid
	int c = centroid(k, k, subsize[k]);
	rem[c] = 1;
	pai[c] = last;
	//dfs_dist(c, c);

	// decompoe as sub-arvores
	for (int i : g[c]) if (!rem[i]) decomp(i, c);
}

void build() {
	memset(rem, 0, sizeof rem);
	decomp(0);
	//for (int i = 0; i < n; i++) reverse(dist[i].begin(), dist[i].end());
}

int main(){
	cin >> n;
	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].pb(b), g[b].pb(a);
	}
	build();
	for(int  i=0;i <n; i++) cout << i+1 << " " << pai[i]+1 << endl;
}
