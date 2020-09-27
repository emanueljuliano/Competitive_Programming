#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back

typedef long long ll;

vector<int> g[50500];
int gin[50500];
int vis[50500];
int ans = 0;

void dfs(int a){
	ans++;
	for(int i=0; i<g[a].size(); i++){
		int b = g[a][i];
		
		if(gin[b]>0) gin[b]--;
		if(!vis[b]) continue;
		
		if(gin[b]==0) dfs(b);
	}
}

int main(){ _
	int n, m;
	while(cin >> n >> m){
		for(int i=0;i<=n; i++){
			ans = 0;
			gin[i] = 0;
			vis[i]=0;
			g[i].resize(0);
		}
		
		for(int i=0; i<m; i++){
			int a, b;
			cin >> a >> b;
			gin[b]++;
			g[a].pb(b);
		}
		
		for(int i=0; i<n; i++){
			int a;
			cin >> a;
			vis[a]=1;
			if(gin[a]==0){
				dfs(a);
			}
			cout << ans << endl;
		}
	}

	exit(0);
}
