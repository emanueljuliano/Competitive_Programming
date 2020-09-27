#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 2e5 + 10;

int visto[MAX];
int dist[MAX];
vector<vector<int>> g(MAX);
vector<vector<int>> adj(MAX);

void bfs(int x){
	memset(visto, -1, sizeof(visto));
	memset(dist, 0, sizeof(dist));

	queue<int> fila;
	fila.push(x);
	visto[x] = 1;
	
	int atual = 0;
	while(!fila.empty()){
		int v = fila.front();
		fila.pop();
		for(int i=0; i<adj[v].size(); i++){
			int u= adj[v][i];
			if (visto[u] == -1){
				visto[u] = visto[v];
				dist[u] = dist[v]+1;
				fila.push(u);
			}
		}
	}
}


int main(){ _
	int n, m;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		adj[b].pb(a);
	}
	
	int k; cin >> k;
	vector<int> v;
	for(int i=0; i<k; i++){
		int a; cin >> a;
		v.pb(a);
	}
	
	bfs(v.back());
	
	int mini = 0, maxi=0;
	for(int i=0; i<k-1; i++){
		int at = INF;
		int num = 0;
		for(int j=0; j<g[v[i]].size(); j++){
			int viz = g[v[i]][j];
			at = min(dist[viz], at);
		}
//		cout << "COME " << v[i] << endl;
		for(int j=0; j<g[v[i]].size(); j++){
			int viz = g[v[i]][j];
			if(dist[viz]==at){
				num++;
			//	cout << viz << " " << at << endl;
			}
		}

		if(dist[v[i+1]] > at){
			mini++;
			maxi++;
		}
		else{
			if(num>1) maxi++;
		}
	}
	cout << mini << " " << maxi << endl;

	exit(0);
}
