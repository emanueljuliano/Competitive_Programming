#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e3+10;

int in[MAX];
int low[MAX];
int parent[MAX];
vector<int> g[MAX];
set<pair<int, int>> bridge;

int is_art[MAX];

void dfs_art(int v, int p, int &d){
	parent[v] = p;
	low[v] = in[v] = d++;
	is_art[v] = false;
	for (int j : g[v]){
		if (j == p) continue;
		if (in[j] == -1){
			dfs_art(j, v, d);

			if (low[j] >= in[v]) is_art[v]++;
			if (low[j] >  in[v]) bridge.insert({min(v, j), max(v, j)});

			low[v] = min(low[v], low[j]);
		}
		else low[v] = min(low[v], in[j]);
	}
	if (p == -1){
		is_art[v] = false;
		int k = 0;
		for (int j : g[v])
			k += (parent[j] == v);
		if (k > 1) is_art[v] = k-1;
	}
}


int d = 0;
int vis[MAX];
set<int> block;
set<int> art;

void dfs(int v){
	block.insert(v);
	for(auto u : g[v]){
		if(!is_art[u]){
			if(!block.count(u) and vis[u]<=0) dfs(u);
		}
		else{
			art.insert(u);
		}
	}
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		for(int i=0;i <n; i++) {
			g[i].clear(), in[i]=-1, vis[i] = 0, is_art[i]=0, low[i]=0, parent[i]=0;
		}
		bridge.clear();
		art.clear();
		block.clear();

		for(int i=0;i <m; i++){
			int a, b; cin >> a >> b; a--, b--;
			g[a].push_back(b), g[b].push_back(a);
		}
		d = 0;
		dfs_art(0, -1, d);
		
		int a2 = bridge.size();
		int a1 = 0;
		for(int i=0;i <n; i++) if(is_art[i]) a1++;
		
		vector<int> ans;
		vector<int> nxt;
		for(int i=0;i<n; i++) if(!is_art[i]) {nxt.push_back(i);}
		while(nxt.size()){
			int s = nxt.back(); nxt.pop_back();
			if(vis[s]) continue;

			dfs(s);
			if(!art.size()){
				int at = 0;
				for(auto v : block) for(auto u : g[v]) if(block.count(u)) at++;
				if(at>0) ans.push_back(at/2);
				break;
			}
			
			else if(art.size() == 1){

				int a = *art.begin();
				block.insert(a);
				int at = 0;
				for(auto v : block) for(auto u : g[v]) if(block.count(u)) at++;

				if(at>0) ans.push_back(at/2);
				for(auto v : block) vis[v] = 1;
				vis[a] = 0;
				is_art[a]--;
				if(!is_art[a]) nxt.push_back(a);
			}
			
			else{
				for(auto v : block) vis[v] = -1;
			}

			block.clear();
			art.clear();
		} 

		int p = 0, q = 0;
		for(auto u : ans) q = max(q, u), p++;

		int gc = gcd(p, q);
		if(gc!=0) p/=gc, q/=gc;
		cout << a1 << " " << a2 << " " << p << " " << q << endl;
		
	}
	
	
	
	exit(0);
}
