#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ 
	freopen("xot.in", "r", stdin); _		
	int n; cin >> n;
	vector M(n, vector(n, int()));
	vector<vector<int>> g(n);

	for(int i=0;i <n; i++) for(int j=0; j<n; j++){ 
		cin >> M[i][j];
		if(M[i][j]) g[i].pb(j);
	}

	// complete bipartite
	vector<int> c(n);
	bool is_kb = true;
	int dg1=0, dg2=0, c1=0;
	for(int i=0;i <n; i++){
		if(!dg1){
			dg1 = g[i].size(), c1++;
			for(auto u : g[i]) c[u] = 1;
		}
		else if(c[g[i][0]] == 1){
			c1++;
			if(g[i].size() != dg1) is_kb = false;
			for(auto u : g[i]) if(c[u] != 1) is_kb = false;
		}
		else if(!dg2){
			dg2 = g[i].size();
			for(auto u : g[i]) {
				if(c[u]) is_kb = false;
				else c[u] = 2;
			}
		}
		else if(c[g[i][0]] == 2){
			if(g[i].size() != dg2) is_kb = false;
			for(auto u : g[i]) if(c[u] != 2) is_kb = false;
		}
		else is_kb = false;
	}
	if(is_kb){  // Use trees of diameter 2
		cout << c1 << endl;
		for(int i=0; i<n; i++) if(c[i]==2){
			for(int j=0; j<n; j++) if(i!=j) cout << i+1 << " " << j+1 << endl; 
		}
		exit(0);
	}

	// Use trees of diameter 3

	set<ii> used;
	auto add_edges = [&](int a, int b, int p){ // add edges ap and bp
		for(int i=0;i <n; i++) if(i!=a and i!=p) cout << i+1 << " " << p+1 << endl;
		cout << a+1 << " " << b+1 << endl;
		for(int i=0;i <n; i++) if(i!=b and i!=p) cout << i+1 << " " << p+1 << endl;
		cout << a+1 << " " << b+1 << endl;
		used.insert({min(a, p), max(a, p)});
		used.insert({min(b, p), max(b, p)});
	};

	vector<bool> vis(n);
	function<void(int, int)> dfs = [&](int v, int p){ 
		vis[v] = 1;
		vector<int> ng;
		for(auto u : g[v]) if(!vis[u]) dfs(u, v);
		for(auto u : g[v]) if(u!=p and !used.count({min(u, v), max(u, v)})) ng.pb(u);
		for(int i=0;i+1<ng.size(); i+=2) add_edges(ng[i], ng[i+1], v);
		if(ng.size()%2) add_edges(ng.back(), p, v);
	};

	// Verify if we can use these trees
	int eg = 0;
	for(int i=0; i<n ; i++) eg+=g[i].size();
	eg/=2;
	if(eg%2==0){
		cout << eg << endl;
		dfs(0, 0);
	}
	else{
		bool has_xor = false;
		for(int i=0; i<n; i++){
			if(n%2) break;  // n-1 is even, so every graph will have a odd number of edges
			if(eg==n*(n-1)/2){  // complete graph as corner case 
				cout << eg-(n-1)+1 << endl;
				for(int j=2;j <n; j++) cout << 1 << " " << j+1 << endl, M[0][j]^=1, M[j][0]^=1;
				cout << 2 << " " << 3 << endl, M[1][2]^=1, M[2][1]^=1;
				
				vector<vector<int>> g2(n);
				for(int j=0; j<n; j++) for(int k=0; k<n; k++) if(M[j][k]) g2[j].pb(k);
				g = g2, dfs(0, 0), has_xor = true;
				break;
			}
			
			vector<vector<int>> M2; M2 = M;
			for(int j=0; j<n; j++) if(j!=i) M2[i][j]^=1, M2[j][i]^=1;
			vector<vector<int>> g2(n);
			eg = 0;
			for(int j=0; j<n; j++) for(int k=0; k<n; k++) if(M2[j][k])
				eg++, g2[j].pb(k);
			eg/=2;

			vector<bool> vis2(n);
			int cnt = 0; 
			function<void(int)> dfs2 = [&](int v){
				for(auto u : g2[v]) if(!vis2[u]) vis2[u]=1, cnt++, dfs2(u);
			};
			vis2[i]=1, cnt=1, dfs2(i);
			if(cnt != n) continue;

			cout << eg+1 << endl;
			for(int j=0; j<n; j++) if(i!=j) cout << i+1 << " " << j+1 << endl;
			g = g2, dfs(0, 0), has_xor = true;
			break;
		}
		if(!has_xor) cout << -1 << endl;
	}
	

	exit(0);
}
