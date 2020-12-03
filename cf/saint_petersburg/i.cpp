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


int main(){ _
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);
	vector<int> v0(n), vv0(n);
	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b; a--, b--;
		if(!a) v0[b]=1;
		if(!b) v0[a]=1;
		g[a].pb(b), g[b].pb(a);
	}

	for(int i=0;i <n; i++){
		for(auto w : g[i]) if(v0[w]) vv0[i]++;
	}
	vv0[0] = 1;
	ll ans = 0;
	for(auto v : g[0]){
		for(auto w : g[v]) ans += vv0[w]-1;
	}

	cout << ans << endl;
	
	
	exit(0);
}
