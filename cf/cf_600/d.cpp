#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ss second
#define ff first

typedef pair<int, int> pii;
typedef long long ll;

#define MAXN 200050

vector <int> adj[MAXN];
int visto[MAXN];
int n, m;

void dfs(int x){
	for (int i=0; i<adj[x].size(); i++){
		int v = adj[x][i];
		if(visto[v]==-1){
			visto[v] = visto[x];
			dfs(v);
		}
	}
}


int main(){ _

	int n, m;
	cin >> n >> m;

	for(int i=0; i<n; i++) visto[i] = -1;
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int vazio[MAXN];
	memset(vazio, 0, sizeof(vazio));
	int n_comp = 1;
	for(int i=0; i<n; i++){
		if(visto[i] == -1){
			n_comp ++;
			visto[i] = n_comp;
			if(int(adj[i].size())==0)
				vazio[i]++;
			dfs(i);
		}
	}
	int cores[MAXN];
	memset(cores, 0, sizeof(cores));
	set <int> frente;
	for(int i=0; i<n; i++){
		if(!frente.count(visto[i])){
			frente.insert(visto[i]);
			cores[i] = visto[i];
		}
	}
	set <int> tras;
	for(int i=n-1; i>=0; i--){
		if(!tras.count(visto[i])){
			tras.insert(visto[i]);
			cores[i] = visto[i];
		}
	}
	
		
	int at = 0;
	set <int> cor;
	for(int i=0; i<n; i++){
		if(cores[i]!=0){
			if(!cor.count(cores[i])){
				if(cor.empty() and !vazio[i])
					cor.insert(cores[i]);
				else if(!cor.empty()){
					if (!vazio[i]) 
						cor.insert(cores[i]);
					at++;
				}
			}
			else{
				cor.erase(cores[i]);
			}
		}
	}
	
	cout << at << endl;

	exit(0);
}
