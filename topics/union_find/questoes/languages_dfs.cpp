#include <bits/stdc++.h>

using namespace std;

#define pb push_back

vector <vector <int > > g(210);
int visto[210];

void dfs(int x){
	for(int i=0; i<g[x].size(); i++){
		int viz = g[x][i];
		if(visto[viz] == -1){
			visto[viz] = visto[x];
			dfs(viz);
		}
	}
}

int main(){ 
	memset(visto, -1, sizeof(visto));
	int n, m, k, a, comp = 0, zeros=0;
	cin >> n >> m;
	int pers = m;
	for(int i=0; i<n; i++){
		cin >> k;
		if(k==0) zeros++;
		for(int j=0; j<k; j++){
			cin >> a;
			a--;
			g[pers].pb(a);
			g[a].pb(pers);
		}
		pers++;
	}

	for(int i=m; i<pers; i++){
		if(visto[i] == -1){
			visto[i] = comp;
			dfs(i);
			comp++;
		}
	}
	if(zeros!= n)
		cout << comp -1 << endl;
	else
		cout << comp << endl;
	exit(0);
}
