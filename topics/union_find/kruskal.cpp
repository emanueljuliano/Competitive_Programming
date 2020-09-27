#include <bits/stdc++.h>

using namespace std;



void kruskal(G){
	for(int i=0; i<n; i++)
		id[i]=i;
	sort(edge, edge+m);
	for(int e=0; e<m; e++){
		if (find(edge[e].x)==find(edge[e].y) continue;
		union(edge[e].x, edge[e].y);
		mst[e] = true;
	}


}


