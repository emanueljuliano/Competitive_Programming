#include <bits/stdc++.h>

using namespace std;

#define  _ ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXV 1001000
#define pb push_back
#define ff first
#define ss second

typedef pair<int, int> pii;

int n, dist[MAXV], visto[MAXV];
vector <pii> ga[MAXV];
vector <pii> g[MAXV];

void dijkstra(int v){
	for(int i=0; i<n; i++) // marca como não visto
		dist[i]= -1; 
	
	set <pii> fila;
	fila.insert({0, v}); // par de distancia e vertice

	pii aux;
	while(!fila.empty()){ // enquanto ainda há nós para visitar
		aux = *fila.begin();
		fila.erase(fila.begin());
		
		int vertice = aux.second;
		int distV = aux.first;

		if(dist[vertice]!= -1)
			continue;

		dist[vertice] = distV;

		for(auto vizinho: g[vertice]){
			if(dist[vizinho.first]!= -1) // se ja foi visiado, não adicionar no set
				continue;
			fila.insert({distV+vizinho.second, vizinho.first}); // d[vizinho]=d[vertice] + peso da aresta
		}
	}
}

int main(){ _
	int m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b, x;
		cin >> a >> b >> x;
		a--; b--;
		ga[a].pb({b, x});
		ga[b].pb({a, x});
	}
	for(int i=0; i<n; i++){
		for(auto viz : ga[i]){
			for(auto viz2 : ga[viz.ff])
				g[i].pb({viz2.ff, viz2.ss+viz.ss});
		}
	}
	dijkstra(0);
//	for(int i=0; i<n-1; i++) cout << dist[i] << " ";
	cout << dist[n-1] << endl;	
}

