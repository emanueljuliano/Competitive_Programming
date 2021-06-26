#include<bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;

const int MAX = 2e5+10;
vector<int> g[MAX];

vector<int> topo_sort(int n) {
	vector<int> ret(n,-1), vis(n,0);
	
	int pos = n-1, dag = 1;
	function<void(int)> dfs = [&] (int v) {
		vis[v] = 1;
		for (auto u : g[v]) {
			if (vis[u] == 1) dag = 0;
			else if (!vis[u]) dfs(u);
		}
		ret[pos--] = v, vis[v] = 2;
	};

	for (int i=0; i<n; i++) if (!vis[i]) dfs(i);

	if (!dag) ret.clear();	
	return ret;
}

int main(){ _
	int n, a, b; cin >> n >> a >> b;
	
	for(int i=0;i <n; i++){
		g[i].push_back(i+n);
	}
	for(int i=0;i <a; i++){
		int x, y; cin >> x >> y; x--, y--;
		g[n+x].push_back(y);
	}
	for(int i=0;i <b; i++){
		int x, y; cin >> x >> y; x--, y--;
		g[x].push_back(y+n);
		g[y].push_back(x+n);
	}
	
	vector<int> ans = topo_sort(2*n);
	if(!ans.size()) cout << "NO" << endl;
	else{
		vector<int> a2(2*n);
		for(int i=0;i <ans.size(); i++) a2[ans[i]] = i;
		cout << "YES" << endl;
		for(int i=0;i <n; i++)
			cout << a2[i] << " " << a2[i+n] << endl;
	}
	
}
