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
const int MAX = 1e5+10;

int n;
int id[MAX], dg[MAX], d[MAX];
int sz[MAX], visto[MAX];
vector<vector<int>> g(MAX);

int f(int p){
	if (id[p] == p) return p;
	return id[p] = f(id[p]);
}

void join(int p, int q){
	p = f(p);
	q = f(q);
	if (p==q) return;
	if(sz[p] > sz[q]) swap(p, q);
	id[p]=q;
	sz[q]+= sz[p];
	return;
}

void dfs1(int x){
	visto[x] = 1;
	vector<int> ze;
	for(int i=0; i<g[x].size(); i++){
		int w = g[x][i];
		if(dg[w]==1) ze.pb(w);
		if(!visto[w]) dfs1(w);
	}
	if(ze.size()>1)for(int i=0;i <ze.size()-1; i++) join(ze[i], ze[i+1]);
}


void bfs(int x){
	for(int i=0;i <=n; i++) d[i] = -1;

	queue<int> fila;
	fila.push(x);
	d[x] = 0;
	
	int atual = 0;
	while(!fila.empty()){
		int v = fila.front();
		fila.pop();
	//	cout << v << " " << d[v] << endl;
		for(int i=0; i<g[v].size(); i++){
			int u= g[v][i];
			if (d[u] == -1){
				d[u] = d[v]+1;
				fila.push(u);
			}
		}
	}
}

int dfs2(int x){
	int at = 1;
	visto[x] = 1;
	for(int i=0;i <g[x].size(); i++){
		int u = f(g[x][i]);
		if(!visto[u]){
			at+= dfs2(u);
		}
	}
	return at;
}

int main(){ _
	cin >> n;
	for(int i=0;i <=n; i++) id[i] = i, sz[i] = 1, dg[i]=0, visto[i]=0;

	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
		dg[a]++;
		dg[b]++;
	}
	int mini = 1;
	int r = 0;
	for(int i=0;i <n; i++){
		if(dg[i]==1) {bfs(i); r= i; break;}
	}	
	for(int i=0;i <n; i++){
		if(dg[i]==1){
			//cout << i << " " << d[i] << endl;
			if(d[i]%2) mini = 3;
		}
	}
	dfs1(r);
	int maxi = mini;
	for(int i=0;i <n; i++) visto[i] = 0;
	maxi = max(maxi, dfs2(f(r))-1);

	cout << mini << " " << maxi << endl;
	
	exit(0);
}

