#include <bits/stdc++.h>

using namespace std;

#define  _ ios_base::sync_with_stdio(0);cin.tie(0);
#define MAXV 1001000
#define ff first
#define ss second

typedef pair<int, int> pii;

int n, dist[MAXV];
vector <pii> adj[MAXV];

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

		for(auto viz: adj[vertice]){
			if(dist[viz.first]!= -1) // se ja foi visiado, não adicionar no set
				continue;
			fila.insert({distV+viz.ss, viz.ff}); // d[viz]=d[vertice] + peso da aresta
		}
	}
}



int main(){ _
	cout << "Dijikstra" << endl;
}

