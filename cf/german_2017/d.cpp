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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 202;

vector<vector<int>> g(MAX);
int vis[MAX];
bool dfs(int a, int b){
	if(a==b) return true;
	bool ret = false;
	for(auto u : g[a]){
		if(!vis[u]) ret |= dfs(u, b);
	}
	return ret;
}

bool worse(int a, int b){
	memset(vis, 0, sizeof vis);
	return dfs(a, b);
}

int main(){ _
	int n, m; cin >> n >> m;	
	
	int ptr = 0;
	map<string, int> mp;
	for(int i=0;i <n; i++){
		string a, b; cin >> a;
		for(int j=0; j<4; j++) cin >> b;

		if(!mp.count(a)) mp[a] = ptr++;
		if(!mp.count(b)) mp[b] = ptr++;
		g[mp[a]].pb(mp[b]);
	}
	for(int i=0;i <m; i++){
		string a, b; cin >> a;
		for(int j=0; j<4; j++) cin >> b;
		
		if(!mp.count(a) or !mp.count(b)) cout << "Pants on Fire" << endl;
		else if(worse(mp[a], mp[b])) cout << "Fact" << endl;
		else if(worse(mp[b], mp[a])) cout << "Alternative Fact" << endl;
		else cout << "Pants on Fire" << endl;
	}


	
	
	exit(0);
}
