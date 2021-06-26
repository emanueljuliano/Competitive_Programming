#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 5e5+10;
map<pair<int, int>, pair<int, int>> mp;
int dg[MAX];
vector<int> g[MAX];

pair<int, int> dfs(int i, int p){
	pair<int, int> ret = {i, i};
	for(auto u : g[i]) if(u!=p){
		pair<int, int> at = dfs(u, i);
		//cout << "dfs " << i+1 << " " << u+1 << " " << at.first+1 << " " << at.second+1 << endl;
		mp[{i, u}] = at;
		ret.first = min(ret.first, at.first);
		ret.second = max(ret.second, at.second);
	}
	return ret;
}

void dfs3(int i, int p){
	for(auto u : g[i]){
		pair<int, int> at = {i, i};
		for(auto v : g[i]) if(v != u){
			at.first = min(at.first, mp[{i, v}].first);
			at.second = max(at.second, mp[{i, v}].second);
		}
		mp[{u, i}] = at;
		//cout << u+1 << " " << i+1 << " " << at.first+1 << " " << at.second+1 << endl;
	}
	for(auto u : g[i]) if(u != p) dfs3(u, i);
}

int par[MAX], vis[MAX];
bool can = true;
void dfs2(int i, int p){
	//cout << i+1 << " " << p+1 << " " << par[i] << endl;
	vis[i] = 1, vis[p] = 1;
	if(par[i] == -1) par[i] = p;
	else if(par[i] == p) return;
	else {can = false; return;}
	for(auto u : g[i]) if (u!=p) dfs2(u, i);
}

int main(){ _
	int n; cin >> n;
	if(n==1) return cout << 1 << endl, 0;
	
	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].push_back(b), g[b].push_back(a);
		dg[a]++, dg[b]++;
	}
	
	for(int i=0;i <n; i++) if(dg[i] > 3) return cout << -1 << endl, 0;
	dfs(0, 0);
	dfs3(0, 0);

	memset(par, -1, sizeof par);
	for(int i=0;i <n; i++){
		if(dg[i]==1) continue;
		else if(dg[i]==2){
			//cout << "DOIS " << endl;
			vector<int> mini, maxi;
			for(auto u : g[i]) {
				mini.push_back(mp[{i, u}].first);
				maxi.push_back(mp[{i, u}].second);
			}
			if(mini[0]>=i and maxi[1]<=i) {}
			else if(mini[1]>=i and maxi[0]<=i) {}
			else if(mini[1]>=i and mini[0]>=i) {vis[i]=1;}
			else if(maxi[1]<=i and maxi[0]<=i) {vis[i]=1;}
			else if(mini[0]>=i or maxi[0]<=i) dfs2(g[i][0], i);
			else if(mini[1]>=i or maxi[1]<=i) dfs2(g[i][1], i);
			else can = false;
		}
		else{
			//cout << "TRES " << endl;
			vector<int> mini, maxi;
			for(auto u : g[i]) {
				mini.push_back(mp[{i, u}].first);
				maxi.push_back(mp[{i, u}].second);
			}	
			int mn=-1, mx=-1;
			for(int j=0;j <3; j++) if(mn==-1 and mini[j]>=i) mn = j;
			for(int j=0;j <3; j++) if(j!=mn and mx==-1 and maxi[j]<=i) mx = j;
			if(mn==-1 or mx==-1) can = false;
			else{
				int other;
				for(int j=0; j<3; j++) if(j!=mn and j!=mx) other = j;
				if(maxi[other]<=i) dfs2(g[i][mn], i);
				else if(mini[other]>=i) dfs2(g[i][mx], i);
				else dfs2(g[i][mn], i), dfs2(g[i][mx], i);
			}
		}
	}
	
	if(!can){
		cout << -1 << endl;
		return 0;
	}
	vector<int> ans;
	for(int i=0;i <n; i++) if(!vis[i]){
		if(dg[i]==1 and (i==0 or i==n-1)) ans.push_back(i);
		else if(dg[i]==2) ans.push_back(i);
	}
	if(ans.empty()){
		cout << -1 << endl;
	}
	else{
		for(auto u : ans) cout << u+1 << " ";
		cout << endl;
	}
	exit(0);
}
