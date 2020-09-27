#include <bits/stdc++.h>

using namespace std;

#define ss second
#define ff first
#define pb push_back
typedef pair <int, int> pii;

const int inf = 0x3f3f3f3f;
const int MAX = 200100;
vector<int> g[MAX];
int dist[MAX], visto[MAX], n, ans=0;

void dfs(int v, int x){
	for(int i=0; i<g[v].size(); i++){
		int viz = g[v][i];
		if (dist[viz]==-1){
			dist[viz] = x+1;
			dfs(viz, x+1);
		}
	}
	return;
}

bool dfs2(int v, int w){
	if(v==w){visto[v] = 0; return true;}
	visto[v] = 1;
	bool flag = false;
	for(int i=0; i<g[v].size(); i++){
		int viz = g[v][i];
		if(visto[viz]==-1 and dfs2(viz, w)){
			visto[v] = 0;
			flag= true;
		}
	}

	return flag;
}

int dfs3(int v, int x){
	for(int i=0; i<g[v].size(); i++){
		int w = g[v][i];
		if(visto[w]==-1){
			visto[w] = x+1;
			dfs3(w, x+1);
		}
	}
}

void solve(){
	for(int i=0; i<=n; i++) dist[i]=-1,visto[i]=-1;
	dist[0] = 0;
	dfs(0, 0);
	int maxi = 0;
	int vert = 0;
	for(int i=0; i<=n; i++) 
		if(dist[i]>=maxi){
			maxi = dist[i];
			vert = i;
		}
	//cout << maxi << endl;
	for(int i=0; i<=n; i++) dist[i]=-1, visto[i]=-1;
	dist[vert] = 0;
//	cout << vert << endl;
	dfs(vert, 0);
	maxi = 0;
	int vert2 = 0;
	for(int i=0; i<=n; i++){
		if(dist[i]>=maxi){
			maxi = dist[i];
			vert2 = i;
		}
	}
	int ans = maxi;
	for(int i=0; i<=n; i++) dist[i]=-1, visto[i]=-1;
	dfs2(vert, vert2);

	for(int i=0; i<=n; i++)if(visto[i]==1) visto[i]=-1;
	for(int i=0; i<n; i++) if(visto[i]==0)dfs3(i, 0);

	maxi = 0;
	int vert3=0;
	for(int i=0; i<=n; i++){
		if(visto[i]>=maxi and i!=vert and i!=vert2){
			maxi = visto[i];
			vert3 = i;
		}
	}
	ans += maxi;
	cout << ans << endl;
	cout << vert+1 << " " << vert2+1 << " " << vert3+1 << endl;
}

int main(){
	int m;
	cin >> n;
	for(int i=0; i<n-1; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	solve();
}
