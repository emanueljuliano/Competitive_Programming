#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define s second
#define f first

typedef pair<int, int> ii;
typedef long long ll;

const int MAX = 1e5 + 10;
vector<vector<int>> g(MAX);
int dist[MAX];
set<ii> st;

int dfs(int k){
	dist[k] = 1;
	for(int i=0; i<g[k].size(); i++){
		if(dist[g[k][i]]==-1){
			dist[k]= max(dist[k], dfs(g[k][i])+1);
		}
	}
	st.insert({dist[k], k});
	return dist[k];
}

void del(int k){
	if(!st.count({dist[k], k})) return;
	st.erase({dist[k], k});
	dist[k] = -1;
	int d = -1;
	int at = -1;
	for(int i=0; i<g[k].size(); i++){
		int viz = g[k][i];
		if(dist[viz]>d){
			d = dist[viz];
			at = viz;
		}
	}
	if(d!=-1 and at!=-1){
		del(at);
	}
}

int main(){ 
	memset(dist, -1, sizeof(dist));
	int n, k; cin >> n >> k;
	for(int i=0; i<n-1; i++){
		int a; cin >> a; a--;
		g[a].pb(i+1);
		g[i+1].pb(a);
	}
	
	dfs(0);

	while(k-- and !st.empty()){
		ii x = *st.rbegin();
		del(x.s);
	}

	int ans = 0;
	for(int i=0; i<n; i++) if(dist[i]==-1) ans++;
	cout << ans << endl;

	exit(0);
}
