#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 5e3+100;

int id[MAX], cor[MAX], c2[MAX], vis[MAX], pd[MAX][MAX];
vector<int> pais;
vector<vector<int>> g(MAX);
vector<ii> v(MAX); 
bool aux = false;

void dfs(int x){
	for(int i=0;i <g[x].size(); i++){
		int u = g[x][i];
		if(vis[u]!=-1){
			if(cor[u]==cor[x]) aux = true;
			continue;
		}
		cor[u] = !cor[x];
		vis[u] = vis[x];
		dfs(u);
	}
}

int find(int p){
	if(p==id[p]) return p;
	return id[p] = find(id[p]);
}

void une(int p, int q){
	p = find(p); q = find(q);
	id[p] = q; return;
}

void build(){
	for(int i=0;i <MAX-10; i++){
		id[i] = i, c2[i]=-1, cor[i]=-1, vis[i]=-1, v[i]={0, 0};
		for(int j=0;j <MAX-10; j++) pd[i][j] = -1;
	}
}


bool show = false;
bool rec(int n, int a, int b){
	if(a==0 and b==0) return show = true;
	if(n<0 or a<0 or b<0) return false;
	int &ret = pd[a][b];
	if(ret != -1) return ret;

	rec(n-1, a-v[n].f, b-v[n].s);
	if(show){c2[find(pais[n])] = 0; return ret = show;}
	rec(n-1, a-v[n].s, b-v[n].f);
	if(show){c2[find(pais[n])] = 1; return ret = show;}
	return ret = false;
}
int main(){ _
	int n, m; cin >> n >> m;
	int n1, n2, n3; cin >> n1 >> n2 >> n3;
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b; a--; b--;
		g[a].pb(b); g[b].pb(a);
	}
	build();
	int cmp = 0;
	for(int i=0;i <n;i++){
		if(vis[i]==-1){
			vis[i] = cmp++; pais.pb(i); cor[i] = 0; dfs(i);
		}
	}
	for(int i=0;i <n; i++) une(i, pais[vis[i]]);
	for(int i=0;i <n; i++) if(cor[i]) v[vis[i]].s++; else v[vis[i]].f++;

	bool ans = rec(cmp-1, n1+n3, n2);
	if(!ans or aux) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		for(int i=0;i <n; i++){
			if(c2[find(i)] == cor[i]){
				if(n1>0) {n1--; cout << 1;}
				else cout << 3;
			}
			else{
				cout << 2;
			}
		}
		cout << endl;
	}
	exit(0);
}

