#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
int n, dist[MAXV];
vector <pii> adj[MAXV];

void dijkstra(int v){
	for(int i=0; i<n; i++) // marca como nÃ£o visto
		dist[i]= -1; 
	
	set <pii> fila;
	fila.insert({0, v}); // par de distancia e vertice

	pii aux;
	while(!fila.empty()){ // enquanto ainda hÃ¡ nÃ³s para visitar
		aux = *fila.begin();
		fila.erase(fila.begin());
		
		int vertice = aux.second;
		int distV = aux.first;

		if(dist[vertice]!= -1)
			continue;

		dist[vertice] = distV;

		for(auto vizinho: adj[vertice]){
			if(dist[vizinho.first]!= -1) // se ja foi visiado, nÃ£o adicionar no set
				continue;
			fila.insert({distV+vizinho.second, vizinho.first}); // d[vizinho]=d[vertice] + peso da aresta
		}
	}
}


int main(){ _
	int n, m , k;
	cin >> n >> m >> k;
	int M[1010][1010];
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> M[i][j];
		}
	}


	exit(0);
}
