#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int MAX = 1e3+10;
vector<vector<int>> g(MAX);

vector<pair<ld, ld>> pt;
const ld pi = acos(-1);

ld eps = 1e-5;
vector<int> tsub;
vector<int> vis(MAX, 0);
int dfs(int v, int pai){
	tsub[v] = 1;
	for(auto u : g[v]){
		if(u==pai) continue;
		tsub[v] += dfs(u, v);
	}
	return tsub[v];
}

void dfs(int v, ld lo, ld up, int pai){
	//cout << v << " " << tsub[v] << " " << lo << " " <<up << endl;
	vis[v] = 1;
	int tot =0;
	for(auto u : g[v]) if(u!=pai) tot += tsub[u];
	
	int at = 0;
	ld frac = (up-lo)/tot;
	
	for(auto u : g[v]){
		if(u==pai) continue;
		ld nlo = lo + at*frac;
		at += tsub[u];
		ld nup = lo + at*frac;

		pt[u] = {pt[v].f + cos(nlo), pt[v].s + sin(nlo)};
		dfs(u, nlo+eps, nup-eps, v);
	}
}

int main(){ _

	int n; cin >> n;
	vector<int> dg(n);
	pt.resize(n);
	tsub.resize(n);
	for(int i=0;i <n; i++) tsub[i] = 0;

	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].pb(b);
		g[b].pb(a);
		dg[a]++;
		dg[b]++;
	}
	int root = 0;
	pt[root] = {0.0, 0.0};
	dfs(root, -1);
	dfs(root, 0.0, pi/2, -1);

	cout << setprecision(9) << fixed;
	for(int i=0;i <n; i++){
		for(int j=i+1; j<n; j++)
			assert(hypot(pt[i].s - pt[j].s, pt[i].f - pt[j].f) > 1e-4);
	}
	for(int i=0;i <n; i++)
		cout <<  pt[i].f << " " << pt[i].s << endl;

	exit(0);
}
