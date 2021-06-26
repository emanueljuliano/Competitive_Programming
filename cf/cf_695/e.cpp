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

const int MAX = 2e5+10;
vector<int> v;
vector<vector<int>> g, g2;
int ans;
int subsize[MAX];

void dfs(int k, int p=-1) {
	subsize[k] = 1;
	for (int i : g[k]) if (i != p) {
		dfs(i, k);
		subsize[k] += subsize[i];
	}
}

int centroid(int k, int p=-1, int size=-1) {
	if (size == -1) size = subsize[k];
	for (int i : g[k]) if (i != p) if (subsize[i] > size/2)
		return centroid(i, k, size);
	return k;
}

set<int> s1, s2;
map<int, int> mp;
void dfs2(int x, int p){
	if(mp[v[x]]) s2.insert(v[x]);
	mp[v[x]]++, s1.insert(v[x]);
	for(auto u : g[x]) if(u!=p) dfs2(u, x);
	mp[v[x]]--;
}

void solve(int x){
	dfs(x);
	x = centroid(x);
	dfs(x);
	cout << "root " << x+1 << endl;

	int nxt = -1;
	for(auto u : g[x]){
		s1.clear(), s2.clear(), mp.clear();
		mp[v[x]]++;
		dfs2(u, x);
		for(auto k : s1) cout<< k << " ";
		cout << endl;
		for(auto k : s2) cout<< k << " ";
		cout << endl;
		if(s2.size()){
			ans -= subsize[x] - subsize[u];
			if(nxt!=-1) {ans=0; return;}
			else nxt = u;
		}
	}
	
	for(auto u : g[x]){
		vector<int> ng;
		for(auto w : g[u]) if(w!=x) ng.pb(w);
		g[u] = ng;
		if(nxt==-1) solve(u);
	}
	if(nxt!=-1) solve(nxt);
}

int main(){ _
	int n; cin >> n;
	ans = n;
	v.resize(n);
	for(auto &i : v) cin >> i;
	g.resize(n);
	for(int i=0; i<n-1; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].pb(b), g[b].pb(a);
	}
	solve(0);
	cout<< max(ans, 0) << endl;
	
	exit(0);
}
