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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 27*27*27*27+10;

int k;
vector<int> pot = {1, 27, 27*27, 27*27*27};

bool is_sub(string a, string b){ // a é sub de b
	for(int j=0; j<k; j++){
		if(a[j] != b[j] and a[j]!='_') return false;
	}
	return true;

}


vector<int> g[MAX];

vector<int> topo_sort(int n) {
	vector<int> ret(n,-1), vis(n,0);
	
	int pos = n-1, dag = 1;
	function<void(int)> dfs = [&] (int v) {
		vis[v] = 1;
		for(auto u : g[v]) {
			if(vis[u] == 1) dag = 0;
			else if(!vis[u]) dfs(u);
		}
		ret[pos--] = v, vis[v] = 2;
	};

	for(int i=0; i<n; i++) if(!vis[i]) dfs(i);

	if(!dag) ret.clear();	
	return ret;
}

int main(){
	int n, m; cin >> n >> m >> k;	
	
	vector<int> t(m), rev(n);
	vector<string> p(n), s(m);
	map<string, int> mp;
	int pt = 0;

	for(auto &i : p) cin >> i;
	for(int j=0; j<m; j++){
		cin >> s[j];
		cin >> t[j]; t[j]--;
		string st = p[t[j]];
		if(!mp.count(st)) rev[pt]=t[j], mp[st] = pt++;
		if(!is_sub(p[t[j]], s[j])) return cout << "NO" << endl, 0;;
	}
	
	for(int it=0;it <m; it++){
		for(int i=0;i <(1<<k); i++){
			string at = s[it];
			string from = p[t[it]];
			for(int j=0; j<k; j++) if(i & (1<<j)) at[j]='_';

			if(mp.count(at) and at!=from) g[mp[from]].pb(mp[at]);
		}
	}
	
//	for(int i=0;i <pt; i++){
//		cout << p[rev[i]] << ": ";
//		for(auto u : g[i]) cout << p[rev[u]] << ", ";
//		cout << endl;
//	}

	vector<int> ret = topo_sort(pt);
	if(mp.size() and !ret.size()) return cout << "NO" << endl, 0;
	vector<int> ans;
	for(auto u : ret) ans.pb(rev[u]);
	
	for(int i=0;i <n; i++) if(!mp.count(p[i])) ans.pb(i);
	cout << "YES" << endl;
	for(auto u : ans) cout << u+1 << " ";
	cout << endl;
	


	exit(0);
}
