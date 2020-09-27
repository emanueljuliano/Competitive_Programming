#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

#define ff first
#define ss second
#define pb push_back


int dist[300];
vector <pii> g[300];
int n;

void dijkstra(int v){
	for(int i=0; i<=n; i++) dist[i]=-1;
	set <pii> fila;
	fila.insert({0, v});

	while(!fila.empty()){
		pii aux = *fila.begin();
		fila.erase(fila.begin());
		int w = aux.ss;
		int distV = aux.ff;

		if(dist[w] != -1) continue;
		dist[w] = distV;

		for(auto viz : g[w]){
			if (dist[viz.ff] != -1) continue;
			fila.insert({distV + viz.ss, viz.ff});
		}
	}
}

int main(){ 
	while(true){ 

	int m, c, k;
	cin >> n>> m >> c >> k;
	if(n==0) break;

	map <int, int> ma;
	for(int i=0; i<m; i++){
		int a, b, p;
		cin >> a >> b >> p;
		g[a].pb({b, p});
		g[b].pb({a, p});
		if(b<c and b == a+1)
			ma[b] = p;
		if(a<c and a == b+1)
			ma[a] = p;
	}
	
	for(int i=0; i<c-1; i++){
		g[i].resize(0);
		g[i].pb({i+1, ma[i+1]});
	}
	
	dijkstra(k);
	cout << dist[c-1] << endl;

	for(int i=0; i<=n; i++)
		g[i].resize(0);
	}
	exit(0);
}
