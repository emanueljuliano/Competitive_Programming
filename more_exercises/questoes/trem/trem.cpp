#include <bits/stdc++.h>

using namespace std;

#define ss second
#define ff first
#define pb push_back
typedef pair <int, int> pii;

const int MAX = 100100;
vector<int> g[MAX];
int dist[MAX], visto[MAX], n, maxi=0, ans=0;

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

int dfs2(int v){
//	cout << v << " " << dist[v] << endl;
	int a =0;
	int flag = 0;
	for(int i=0; i<g[v].size(); i++){
		int viz = g[v][i];
		if(visto[viz]==-1){
			visto[viz] =1;
			flag |= dfs2(viz);
		}
	}
	if(flag){
//		cout <<"f " << v <<" " << dist[v] << " " << maxi << endl;
		if (maxi%2==0){
			if(dist[v] == maxi/2)
				ans = max(ans, v);
		}
		else{
			if(dist[v] == maxi/2 or dist[v]==(maxi/2 + 1)){
				ans = max(ans, v);
//				cout <<" foi " << endl;
			}
		}
	}		

	
	if(dist[v]==maxi or flag) return 1;
	return 0;
}

int center(){
	for(int i=0; i<=n; i++) dist[i]=-1;
	dist[0] = 0;
	dfs(0, 0);
	maxi = 0;
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
	for(int i=0; i<=n; i++) 
		maxi =max(dist[i], maxi);

	ans = 0;
	memset(visto, -1, sizeof(visto));
	dfs2(vert);
//	cout << ans1 << endl;
	return ans;
}

int main(){
	int m;
	cin >> n >> m;
	for(int i=0; i<n-1; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	int ans1 = center()+1;
	for(int i=0; i<=n; i++)
		g[i].resize(0);

	n = m;
	for(int i=0; i<n-1; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	int ans2 = center()+1;
	cout << ans1 << " " << ans2 << endl;
}
