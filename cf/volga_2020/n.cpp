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

const int MAX = 2e5+10;

int in[MAX];
int low[MAX];
int parent[MAX];
vector<ii> g[MAX];

bool is_art[MAX];

void dfs_art(int v, int p, int &d){
	parent[v] = p;
	low[v] = in[v] = d++;
	is_art[v] = false;
	for (auto [j, u] : g[v]){
		if (j == p) continue;
		if (in[j] == -1){
			dfs_art(j, v, d);

			if (low[j] >= in[v]) is_art[v] = true;
			//if (low[j] >  in[v]) this edge is a bridge

			low[v] = min(low[v], low[j]);
		}
		else low[v] = min(low[v], in[j]);
	}
	if (p == -1){
		is_art[v] = false;
		int k = 0;
		for (auto [j, u] : g[v])
			k += (parent[j] == v);
		if (k > 1) is_art[v] = true;
	}
}

vector<int> comp[MAX];
int cmp = 0;
int vis[MAX];

void dfs(int x){
	comp[cmp].pb(x), vis[x] = 1;
	for(auto [u, i] : g[x]) if(!vis[u]) dfs(u);
}

int back[MAX];
int main(){ _
		
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i=0;i <2*n; i++) g[i].clear(), comp[i].clear(), in[i]=-1, vis[i]=0;

		map<int, int> mp;
		int ptr = 0;
		for(int i=0;i <n; i++){
			int a, b; cin >> a >> b;
			if(!mp.count(a)) mp[a] = ptr++;
			if(!mp.count(b)) mp[b] = ptr++;
			back[mp[a]] = a, back[mp[b]] = b;
			g[mp[a]].pb({mp[b], i});
			g[mp[b]].pb({mp[a], i});
		}
		
		vector<int> ordem;
		cmp = 0;
		for(int i=0;i <ptr; i++){
			if(!vis[i]) vis[i]=1, dfs(i), cmp++, ordem.pb(i);
		}

		cout << cmp-1 << endl;
		for(int i=1; i<cmp; i++){
			int d = 0;
			dfs_art(ordem[i], -1, d);
			for(auto u : comp[i]) if(!is_art[u]){
				cout << g[u][0].s+1 << " " << back[u] << " " << back[0] << endl;
				break;
			}
		}
	}	
	exit(0);
}
