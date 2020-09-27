#include <bits/stdc++.h>

using namespace std;

#define pb push_back

vector <vector <int > > g(120);
int id[120], sz[120];

int find(int p){
	if(id[p] == p) return p;
	return id[p] = find(id[p]);
}

void uni(int p, int q){
	p = find(p);
	q = find(q);

	if(p==q) return;
	if(sz[p] > sz[q]) swap(p, q);

	id[p] = id[q];
	sz[q] += sz[p];
}

int main(){ 
	int n, m, k, a, zeros=0;
	cin >> n >> m;
	for(int i=0; i<n; i++){ id[i] = i; sz[i]=1;}
	
	for(int i=0; i<n; i++){
		cin >> k;
		if(k==0) zeros++;
		for(int j=0; j<k; j++){
			cin >> a;
			a--;
			g[a].pb(i);
		}
	}
	
	for(int i=0; i<m; i++){
		for(int j=1; j<g[i].size(); j++){
			uni(g[i][0], g[i][j]);
		}
	}
	
	set <int> comp;
	for(int i=0; i<n; i++)
		comp.insert(find(i));

	if(zeros == n) cout << n << endl;
	else cout << comp.size() -1 << endl;

	exit(0);
}
