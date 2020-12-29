#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;

vector<vector<ii>> g(1010);
int dist[1010];

void djikstra(int x){
	memset(dist, -1, sizeof(dist));
	set<ii> st;
	st.insert({0, x});
	while(!st.empty()){
		ii aux = *st.begin();
		st.erase(aux);
		x = aux.s; int d = aux.f;
		
		if(dist[x]!=-1) continue;
		dist[x] = d;
		for(int i=0;i<g[x].size(); i++){
			ii v = g[x][i];
			if(dist[v.f]!=-1) continue;
			st.insert({dist[x]+v.s, v.f});
		}
	}
}


int main(){ _
	int n, m; cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	int x; cin >> x; x--;
	djikstra(x);
	int mini = 1000;
	int maxi = 0;
	for(int i=0; i<n; i++){
		if(i==x) continue;
		mini = min(mini, dist[i]);
		maxi = max(maxi, dist[i]);
	}
	cout << maxi-mini << endl;


	exit(0);
}
