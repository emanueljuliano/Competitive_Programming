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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1e3+10;

vector<int> pai(MAX, -1);
vector<vector<int>> g(MAX), g2(MAX), ent(MAX);
vector<ii> ans;
int n;
vector<int> vis(MAX, 0);
vector<vector<int>> filhos(MAX);


vector<int> dfs(int x){
	for(int i=0;i<g[x].size();i++){
		int u = g[x][i];
		if(vis[u]) continue;
		vis[u] = 1;
		vector<int> v = dfs(u);
		filhos[x].pb(u);
		if(!v.empty()) for(auto k : v) filhos[x].pb(k);
	}
	return filhos[x];
}

bool conex(){
	if(g2.back().size() != n) return false;
	vis[g2.back()[0]]=1;
	dfs(g2.back()[0]);
	for(int i=0; i<n; i++) if(!vis[i]) return false;
	return true;
}

bool verify(){
	for(int i=0;i <ans.size(); i++){
		int a = ans[i].f, b = ans[i].s;
		g[a].pb(b); g[b].pb(a);
	}
	bool show = true;
	show &= conex();
	for(int i=0;i <n; i++){
		sort(ent[i].begin(), ent[i].end());
		sort(filhos[i].begin(), filhos[i].end());
		
		if(ent[i].size() != filhos[i].size()) {
			show = false;
			break;
		}
		for(int j=0;j <filhos[i].size(); j++){
			show &= (filhos[i][j]==ent[i][j]);
		}
	}
	return show;	
}

bool ord(vector<int> &v, vector<int> &w){
	return v.size()<w.size();
}

int main(){ _
	cin >> n;
	for(int i=0;i <n; i++){
		vector<int> v;
		int k; cin >> k;
		v.pb(i);
		for(int j=0;j <k; j++){
			int a; cin >> a; a--;
			v.pb(a);
			ent[i].pb(a);
		}
		g2.pb(v);
	}
	sort(g2.begin(), g2.end(), ord);
	for(int i=0;i <g2.size(); i++){
		if(g2[i].size()==1) continue;
		for(int j=1; j<g2[i].size(); j++){
			int u = g2[i][j];
			if(pai[u]!=-1) continue;
			pai[u] = i;
			ans.pb({g2[i][0], u});
		}
	}
	if(verify()){
		cout << "YES" << endl;
		for(int i=0;i <ans.size(); i++)
			cout << ans[i].f+1 << " " << ans[i].s+1 << endl;
	}
	else cout << "NO" << endl;

	exit(0);
}
