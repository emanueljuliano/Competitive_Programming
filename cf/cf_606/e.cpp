#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
vector <int> g[200200];
int visto[200200];
int n, m;

// visto(ini) = 1
void dfs(int x, int a, int b){
	for (int i=0; i<g[x].size(); i++){
		int v = g[x][i];
		if(visto[v]==-1 and v!= a and v!=b and x!=a and x!=b){
			visto[v] = visto[x];
			dfs(v, a, b);
		}
	}
}

int main(){ _
	int t, a, b;
	cin >> t;
	for(int k=0; k<t; k++){
	cin >> n >> m >> a >> b;
	for (int i=0; i<n; i++) g[i].clear();
	for(int i=0; i<n; i++) visto[i] = -1;
	for(int i=0; i<m; i++){
		int c, d;
		cin >> c >> d;
		c--;
		d--;
		g[c].push_back(d);
		g[d].push_back(c);
	}
	int n_comp = 0;
	for(int i=0; i<n; i++){
		if(visto[i] == -1){
			n_comp ++;
			visto[i] = n_comp;
			dfs(i, -1, -1);
		}
	}
	int compa=0, compb=0, compab=0;
	for(int i=0; i<n; i++) visto[i] = -1;
	for(int i=0; i<n; i++){
		if(visto[i] == -1 and i!=a){
			compa ++;
			visto[i] = compa;
			dfs(i, a, -1);
		}
	}
	for(int i=0; i<n; i++) visto[i] = -1;
	for(int i=0; i<n; i++){
		if(visto[i] == -1 and i!=b){
			compb ++;
			visto[i] = compb;
			dfs(i, -1, b);
		}
	}
	for(int i=0; i<n; i++) visto[i] = -1;
	for(int i=0; i<n; i++){
		if(visto[i] == -1 and i!=a and i!=b){
			compab ++;
			visto[i] = compab;
			dfs(i, a, b);
		}
	}
	
	
	cout <<"l " <<  n_comp << " " << compa << " " << compb << " " << compab << endl;

	}
} 
