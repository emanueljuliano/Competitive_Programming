#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

vector<int> kosaraju(vector<vector<int>>& g) {
    // 1. For each vertex u of the graph, mark u as unvisited. Let l be empty.
    auto size = g.size();
    vector<bool> vis(size);           // all false by default
    vector<int> l(size);              // all zero by default
    auto x = size;                         // index for filling l in reverse order
    vector<vector<int>> t(size); // transpose graph
 
    // Recursive subroutine 'visit':
    function<void(int)> visit;
    visit = [&](int u) {
        if (!vis[u]) {
            vis[u] = true;
            for (auto v : g[u]) {
                visit(v);
                t[v].push_back(u); // construct transpose
            }
            l[--x] = u;
        }
    };
 
    // 2. For each vertex u of the graph do visit(u)
    for (int i = 0; i < g.size(); ++i) {
        visit(i);
    }
    vector<int> c(size); // used for component assignment
 
    // Recursive subroutine 'assign':
    function<void(int, int)> assign;
    assign = [&](int u, int root) {
        if (vis[u]) { // repurpose vis to mean 'unassigned'
            vis[u] = false;
            c[u] = root;
            for (auto v : t[u]) {
                assign(v, root);
            }
        }
    };
 
    // 3: For each element u of l in order, do assign(u, u)
    for (auto u : l) {
        assign(u, u);
    }
 
    return c;
}

int main(){ _

	int n, m;
	
	while(true){
		cin >> n >> m;
		if(n==0 and m==0) break;
		vector<vector<int> > adj(2200);
		for(int i=0; i<m; i++){
			int a, b, c;
			cin >> a >> b >> c;
			a--;
			b--;
			if(c==1)
				adj[a].push_back(b);
			else{
				adj[a].push_back(b);
				adj[b].push_back(a);
			}
		}
		vector<int> ans = kosaraju(adj);
		bool flag = false;
		for(int i=0; i<n; i++){
			flag |= ans[i];
		}
		if(flag) cout << 0 << endl;
		else cout << 1 << endl;
	}
	exit(0);
}
