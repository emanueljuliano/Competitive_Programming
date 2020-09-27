#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ss second
#define ff first

typedef pair <int, int> pii;
int n, dist[10100];
vector <vector <pair <int, int> > > g(10100);
set <pii> ent;

void dijkstra(int v){
	for(int i=0; i<=n; i++) dist[i] = -1;

	set <pii> fila;
	fila.insert({0, v});

	pii aux;
	while(!fila.empty()){
		aux = *fila.begin();
		fila.erase(fila.begin());

		int ver = aux.ss;
		int distV = aux.ff;

		if(dist[ver] !=-1) continue;

		dist[ver] = distV;

		for(auto viz : g[ver]){
			if(dist[viz.ff] != -1) continue;
			fila.insert({distV + viz.ss, viz.ff});
		}
	}
}

int main(){ 
	int c, s, a, b;
	cin >> c >> s >> a >> b;
	n = c;
	a--; b--;
	for(int i=0; i<s; i++){
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].pb({y, 0});
		ent.insert({x, y});
	}
	for(auto pp : ent){
		int x, y;
		x = pp.ff; y = pp.ss;
		if(!ent.count({y, x}))
			g[y].pb({x, 1});
	}
	
	int qa, qb;

	dijkstra(a);
	qa = dist[b];
	
	dijkstra(b);
	qb = dist[a];

//	cout << qa << " " << qb << endl;
	if (qa==-1 or qb==-1)
		cout << "Bibibibika" << endl;
	else if(qa==qb)
		cout << "Bibibibika" << endl;
	else if(qa < qb)
		cout << "Bibi: " << qa << endl;
	else if(qb < qa)
		cout << "Bibika: " << qb << endl;

	exit(0);
}
