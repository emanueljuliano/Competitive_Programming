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
	int t; cin >> t;
	while(t--){
		int n, m, k; cin >> n >> m >> k;
		vector<ll> v, rev;
		for(int i=0;i <n; i++){
			ll at = 0;
			string s; cin >> s;
			for(int j=0;j <m; j++)
				if(s[j]=='1') at += (1LL<<j);
			v.pb(at);
			at = 0;
			reverse(s.begin(), s.end());
			for(int j=0;j <m; j++)
				if(s[j]=='1') at += (1LL<<j);
			rev.pb(at);
		}

		bool show = true;
		vector<vector<ii>> g(n);
		
		// aresta de cor 0 se i->j e aresta de cor 1 se i->!j
		auto bit_dist = [&](ll a, ll b){
			int ret = __builtin_popcountll(a & b);
			ll neg = (1LL<<m)-1;
			ret += __builtin_popcountll((neg^a) & (neg^b));
			return ret;
		};
		for(int i=0;i <n; i++) for(int j=i+1; j<n; j++){
			bool c1 = bit_dist(v[i], v[j]) < k; // i->!j
			bool c0 = bit_dist(v[i], rev[j]) < k; // i->j
			if(c1 and c0) show = false;
			else if(c1) g[i].pb({j, 1}), g[j].pb({i, 1});
			else if(c0) g[i].pb({j, 0}), g[j].pb({i, 0});
		}
		
		// divide as componentes e acha ciclo com numero impar de cores 1
		vector<int> comp, cor(n, -1);
		function<int (int, int)> dfs = [&](int x, int c){
			int ret = c;
			comp.pb(x), cor[x] = c;
			for(auto [u, ce] : g[x]){
				if(cor[u]==-1) ret += dfs(u, c^ce);
				else if(cor[u] != (c^ce)) show = false;
			}
			return ret;
		};
		
		vector<int> ans;
		for(int i=0;i <n; i++) if(cor[i]==-1){
			comp.clear();
			int c1 = dfs(i, 0);
			if(2*c1 <= comp.size()) for(auto u : comp) if(cor[u]==1) ans.pb(u); 
			if(2*c1 > comp.size()) for(auto u : comp) if(cor[u]==0) ans.pb(u); 
		}
		
		if(!show) {cout << -1 << endl; continue;}

		cout << ans.size() << endl;
		for(auto u : ans) cout << u+1 << " ";
		cout << endl;
	}
	
	exit(0);
}
