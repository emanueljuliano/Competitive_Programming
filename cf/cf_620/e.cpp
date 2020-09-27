#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
const int MAX = 1e5 + 10;
const int MAX2 = 17;

vector<vector<int>> g(MAX);
int n, p;
int pai[MAX2][MAX];
int in[MAX], out[MAX];
int sz[MAX];

void dfs(int k, int pr){
	in[k] = p++;
	sz[k] = pr;
	for(int i=0; i<(int)g[k].size(); i++){
		if(in[g[k][i]] ==-1){
			pai[0][g[k][i]] = k;
			dfs(g[k][i], pr+1);
		}
	}
	out[k] = p++;
}

void build(int raiz){
	for(int i=0; i<n; i++) pai[0][i] = i;
	p = 0, memset(in, -1, sizeof(in));
	dfs(raiz, 0);
	// pd dos pais
	for(int k=1; k<MAX2; k++) for(int i=0; i<n; i++)
		pai[k][i] = pai[k-1][pai[k-1][i]];
}

bool anc(int a, int b){
	return in[a] <= in[b] and out[a] >= out[b];
}

int lca(int a, int b){
	if(anc(a, b)) return a;
	if(anc(b, a)) return b;

	for(int k=MAX2-1; k>=0; k--){
		if(!anc(pai[k][a], b)) a = pai[k][a];
	}
	return pai[0][a];
}

int dist(int a, int b){
	//cout << "vert " << a <<"  " << b <<" "  << lca(a, b) << endl;
	//cout << "dist " << sz[a] << " " << sz[b] << " " << sz[lca(a, b)] << endl;
	return sz[a] + sz[b] - 2*sz[lca(a, b)];
}

int main(){ _
	cin >> n;
	for(int i=0; i<n-1; i++){
		int x, y; cin >> x >> y;
		x--; y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	build(0);
	int m; cin >> m;
	for(int i=0; i<m; i++){
		int x, y, a, b, k; cin >> x >> y >> a >> b >> k;
		x--, y--, a--, b--;
		int d1 = dist(a, b);
		int d2 = dist(a, x) +1 + dist(y, b);
		int d3 = dist(a, y) +1 + dist(x, b);
//		cout << x << " " << y << " " << a << " " << b << " " << k << endl;
//		cout << d1 << " " << d2 << "  " << d3;
		if(d1<=k and (k-d1)%2==0) cout << "YES" << endl;
		else if(d2<=k and (k-d2)%2==0) cout << "YES" << endl;
		else if(d3<=k and (k-d3)%2==0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	exit(0);
}
