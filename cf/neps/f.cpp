#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define NIL -1 

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e5+10;
int V;
vector<vector<int>> adj(MAX);
int ans = 0;
set<ii> bri;
void bridgeUtil(int u, bool visited[], int disc[],  
                                  int low[], int parent[]) 
{ 
    // A static variable is used for simplicity, we can  
    // avoid use of static variable by passing a pointer. 
    static int time = 0; 
  
    // Mark the current node as visited 
    visited[u] = true; 
  
    // Initialize discovery time and low value 
    disc[u] = low[u] = ++time; 
  
    // Go through all vertices aadjacent to this 
    for (auto v: adj[u]) 
    { 
        // If v is not visited yet, then recur for it 
        if (!visited[v]) 
        { 
            parent[v] = u; 
            bridgeUtil(v, visited, disc, low, parent); 
  
            // Check if the subtree rooted with v has a  
            // connection to one of the ancestors of u 
            low[u]  = min(low[u], low[v]); 
  
            // If the lowest vertex reachable from subtree  
            // under v is  below u in DFS tree, then u-v  
            // is a bridge 
            if (low[v] > disc[u]) 
              //ans++; //cout << u <<" " << v << endl; 
			  bri.insert({u, v});
        } 
  
        // Update low value of u for parent function calls. 
        else if (v != parent[u]) 
            low[u]  = min(low[u], disc[v]); 
    } 
} 
  
// DFS based function to find all bridges. It uses recursive  
// function bridgeUtil() 
void bridge() 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    int *disc = new int[V]; 
    int *low = new int[V]; 
    int *parent = new int[V]; 
  
    // Initialize parent and visited arrays 
    for (int i = 0; i < V; i++) 
    { 
        parent[i] = NIL; 
        visited[i] = false; 
    } 
  
    // Call the recursive helper function to find Bridges 
    // in DFS tree rooted with vertex 'i' 
    for (int i = 0; i < V; i++) 
        if (visited[i] == false) 
            bridgeUtil(i, visited, disc, low, parent); 
} 

vector<int> g[MAX];
int n, vis[MAX];
int d[2][MAX];

int id[MAX];
int sz[MAX];

int find(int p){
	if (id[p] == p) return p;
	return id[p] = find(id[p]);
}

void join(int p, int q){
	p = find(p);
	q = find(q);
	if (p==q) return;
	if(sz[p] > sz[q]) swap(p, q);
	id[p]=q;
	sz[q]+= sz[p];
	return;
}

// retorna ultimo vertice visitado
int bfs(int k, int x) {
        queue<int> q; q.push(k);
	memset(vis, 0, sizeof(vis));
	vis[k] = 1;
	d[x][k] = 0;
	int last = k;
	
	while (q.size()) {
		int u = q.front(); q.pop();
		last = u;

		for (int i : g[u]) if (!vis[i]) {
			vis[i] = 1;
			q.push(i);
			d[x][i] = d[x][u] + 1;
		}
	}
	return last;
}

int diam(){
	int a = bfs(find(0), 0);
	int b = bfs(a, 1);
	bfs(b, 0);
	int c, mi = 0;
	for (int i = 0; i < n; i++)
		mi = max(mi, d[1][i]), c = i;
	for (int i = 0; i < n; i++)
		mi = max(mi, d[0][i]), c = i;
	return mi;
}


int main(){ _
	int m; cin >> n >> m;
	V = n;
	for(int i=0;i <=n; i++) id[i] = i, sz[i] = 1;
	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	bridge();
	
	for(int i=0;i <n; i++){
		for(int j=0;j <adj[i].size(); j++){
			if(!bri.count({i, adj[i][j]}) and !bri.count({adj[i][j], i})){
				join(i, adj[i][j]);
			}
		}
	}
	for(auto p : bri){
		g[find(p.f)].pb(find(p.s));
		g[find(p.s)].pb(find(p.f));
	}
	int ret = diam();

	cout << ret << endl;
	
	
	exit(0);
}
