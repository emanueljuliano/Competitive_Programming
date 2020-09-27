#include <bits/stdc++.h>

using namespace std;

#define pb push_back

int id[200200], sz[200200];

int find(int p){
	if(p==id[p]) return p;
	return id[p] = find(id[p]);
}

void uni(int p, int q){
	p = find(p);
	q = find(q);
	if (p==q) return;
	if(sz[p] > sz[q]) swap(p, q);
	id[p] = q;
	sz[q] += sz[p];
	return;
}

int main(){ 
	vector <vector <int> > g(200200);
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++){id[i] = i; sz[i] = 1;}
	int a, b;
	for(int i=0; i<m; i++){
		cin >> a >> b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}

int	maxi = 0;
int	id_maxi = 0;
	for(int i=0; i<n; i++){
		if(g[i].size() > maxi){
			maxi = g[i].size();
			id_maxi = i;
		}		
	}
	for(int i=0; i<maxi; i++){
		uni(id_maxi, g[id_maxi][i]);
		cout << id_maxi+1 << " " << g[id_maxi][i]+1 << endl;
	}

	for(int i=0; i<n; i++){
		for(int j=0; j<g[i].size(); j++){
			if(find(g[i][j]) != find(i)){
				uni(g[i][j], i);
				cout << i+1 << " " << g[i][j]+1 << endl;
			}
		}
	}	

	exit(0);
}
