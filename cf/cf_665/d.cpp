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

const int MAX = 1e5+10;
vector<vector<int>> g(MAX);
vector<ll> sub(MAX);

void dfs(int x, int pai){
	sub[x] = 1;
	for(auto u : g[x]){
		if(u==pai) continue;
		dfs(u, x);
		sub[x] += sub[u];
	}
}

const int MOD = 1e9+7;
int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;

		for(int i=0;i <n; i++) sub[i]=0, g[i].clear();
		
		vector<ii> e;
		for(int i=0;i <n-1; i++){
			int a, b; cin >> a >> b; a--, b--;
			g[a].pb(b);
			g[b].pb(a);
			e.pb({a, b});
		}
		
		int m; cin >> m;
		vector<ll> f(m); for(auto &u: f) cin >> u;	
		sort(f.begin(), f.end(), greater<>());

		for(int i=0;i <n; i++) if(g[i].size()==1) {dfs(i, i); break;}

		vector<ll> val;
		for(int i=0;i <n; i++){
			if(sub[i]==n) continue;
			val.pb((n-sub[i])*sub[i]);
		}

		sort(val.begin(), val.end(), greater<>());
		while(f.size() < n-1) f.pb(1);

		if(f.size()>n-1){
			reverse(f.begin(), f.end());
			ll nf = 1;
			while(f.size()>n-2) nf = (nf*f.back())%MOD, f.pop_back();
			f.pb(nf);
			reverse(f.begin(), f.end());
		}

		ll ans = 0;
		for(int i=0;i <n-1; i++){
			ans = ans + (f[i]*val[i])%MOD;
			ans%=MOD;
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
