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

const int MAX = 2*2e5+10;

int n;
vector<int> g[MAX];
vector<ii> g2[MAX];
stack<int> s;
int vis[MAX], comp[MAX];
int id[MAX], p;

int dfs(int k) {
	int lo = id[k] = p++;
	s.push(k);
	vis[k] = 2; // ta na pilha

	for (int i = 0; i < g[k].size(); i++) {
		if (!vis[g[k][i]])
			lo = min(lo, dfs(g[k][i]));
		else if (vis[g[k][i]] == 2)
			lo = min(lo, id[g[k][i]]);
	}

	if (lo == id[k]) while (1) {
		int u = s.top();
		s.pop(); vis[u] = 1;
		comp[u] = k;
		if (u == k) break;
	}

	return lo;
}

void tarjan() {
	for(int i=0;i <2*n; i++) vis[i] = 0;

	p = 0;
	for (int i = 0; i < 2*n; i++) if (!vis[i]) dfs(i);
}

int nao(int x){ return (x + n) % (2*n); }

// x -> y  =  !x ou y
void add(int x, int y){
	g[x].pb(y);
	// contraposicao
	g[nao(y)].pb(nao(x));
}

bool doisSAT(){
	tarjan();
	for (int i = 0; i < n; i++)
		if (comp[i] == comp[nao(i)]) return 0;
	return 1;
}

int c1, c2, cmp=0 color[MAX];
void dfs2(int x, int c){
	if(c==0) c1++;
	else c2++;

}

int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i=0;i <2*n; i++) g[i].clear();
		vector<int> v, w;
		vector<vector<int>> c(n);

		for(int i=0;i <n; i++){
			int a; cin >> a; a--;
			c[a].pb(i); v.pb(a);
		}
		for(int i=0;i <n; i++){
			int a; cin >> a; a--;
			c[a].pb(i); w.pb(a);
		}

		bool show = true;
		for(int i=0;i <n; i++) if(c[i].size()<2) show = false;
		if(!show){cout << -1 << endl; continue;}

		for(int i=0;i <2*n; i++) vis[i] = 0;
		for(int i=0;i <n; i++){
			int a = v[i], b = w[i];
			for(int j=0;j <2; j++){ if(!vis[a]){
				int x = c[a][0], y = c[a][1];
				if((x<n and y<n) or (x>=n and y>=n)) 
					add(nao(x), nao(y)), add(x, y), g2[x].pb({y, 1}), g2[y].pb({x, 1});
				if((x<n and y>=n) or (x>=n and y<n)) 
					add(nao(x), y), add(x, nao(y)), , g2[x].pb({y, 0}), g2[y].pb({x, 0});

				vis[a] = 1;
			} a = b;}
		}
		show = doisSAT();
		if(!show) {cout << -1 << endl; continue;}
		
		for(int i=0;i <2*n; i++) vis[i] = 0, color[i] = 0;
		for(int i=0;i <n; i++){
			c1=0, c2=0;
			if(!vis(i)) dfs2(i, 0);

		}
	}



	exit(0);
}
