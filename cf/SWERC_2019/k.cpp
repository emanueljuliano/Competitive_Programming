#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

const int MAX = 1e5 + 10;
int n;
vector<vector<int>> g(MAX);
stack<int> s;
int vis[MAX], comp[MAX];
int id[MAX], p;
set<int> st;

int dfs(int k){
	int lo = id[k] = p++;
	s.push(k);
	vis[k] = 2;

	for(int i=0; i<g[k].size(); i++){
		if(!vis[g[k][i]])
			lo = min(lo, dfs(g[k][i]));
		else if(vis[g[k][i]]==2)
			lo = min(lo, id[g[k][i]]);
	}

	if(lo == id[k]) while(true){
		int u = s.top();
		s.pop(); vis[u] = 1;
		comp[u] = k;
		if(u==k) break;
	}
	return lo;
}

void tarjan(){
	memset(vis, 0, sizeof(vis));

	p = 0;
	for(int i=0; i<n; i++) if(!vis[i]) dfs(i);
}

vector<int> g2[MAX];
set<int> st2;

bool dfs2(int x){
	vis[x] = 1;
	for(int i=0;i <g2[x].size(); i++){
//		cout << x << " viz " << g2[x][i] << endl;  

		int w = g2[x][i];
		if(vis[w]==0){
			if(dfs2(w)) vis[x] = 2;			
		}
		if(st2.count(w) or vis[w]==2){
			vis[x] = 2;
		}
	}
	return (vis[x] == 2);
}

int main(){ _

	int m, t;
	cin >> n >> m >> t;
	for(int i=0;i<m; i++){
		int a, b; cin >> a >> b;
		if(b==t) st.insert(a);
		else g[a].pb(b);
	}
	
	tarjan();

	memset(vis, 0, sizeof(vis));
	
	// grafo das componentes
	for(int i=0; i<n; i++){
		if(st.count(i)){
			if(st2.count(comp[i])) vis[comp[i]] = 2;
			st2.insert(comp[i]);
		}
		
		//cout << i << " comp " << comp[i] << endl;
	
		for(int j=0; j<g[i].size(); j++){
			if(comp[i]==comp[g[i][j]]) continue;
			
			g2[comp[i]].pb(comp[g[i][j]]);
		//	cout << comp[i] << " " << comp[g[i][j]] << endl;
		}
	}


	for(int i=0; i<n; i++){
		if(!vis[comp[i]]) dfs2(comp[i]);
	}

	vector<int> ret;
	for(auto x : st){
	//	cout << x << " comp " << comp[x] << " vis " << vis[comp[x]] << endl;
		if(vis[comp[x]] == 1){
			ret.pb(x);
		}
	}

	sort(ret.begin(), ret.end());

	cout << ret.size() << endl;
	for(int i=0; i<ret.size(); i++){
		cout << ret[i] << endl;
	}

	exit(0);

}
