#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 40;
ll W[MAX];
int MOD;
int n;

namespace cover{
	vector<int> g[MAX];
	bitset<MAX> bs[MAX];

	void add(int i, int j){

	}
	ll rec(bitset<MAX> m){
		if(m==0) return 1;
		ll ans = 1;
		for(int x = 0; x<n; x++) if(m[x]){
			bitset<MAX> comp;
			function<void(int)> dfs = [&](int i){
				comp[i] = 1, m[i] = 0;
				for(int j : g[i]) if(m[j]) dfs(j);
			};
			dfs(x);

			int ma, deg = -1;
			for(int i=0;i <n; i++) if(comp[i]){
				int d = (bs[i]&comp).count();
				if(d>deg) deg = d, ma = i;
			}
			if(deg==0){
				ans = (ans*(W[ma]+1))%MOD;
				continue;
			}
			comp[ma] = 0;
			ll a1 = W[ma]*rec(comp)%MOD;
			ll a2 = rec(comp & ~bs[ma]);
			for(int i=0;i <n; i++) if(bs[ma][i] & comp[i]) a2 = a2*W[i]%MOD;
			ans = (ans*(a2+a1))%MOD;
		}
		//cout << ent << " " << ans << endl;
		return ans;
	}
	int solve(){
		bitset<MAX> m;
		for(int i=0;i <n; i++){
			m[i] = 1;
			for(int j=0; j<n; j++)
				if(bs[i][j]) g[i].push_back(j);
		}
		return rec(m);
	}
}

int main(){ _
	int t; cin >> t;
	int cs = 0;
	while(t--){
		cs++;
		cout << "Case #" << cs << ": ";
		int m; cin >> n >> m >> MOD;
		for(int i=0;i <n; i++){
			cover::g[i].clear();
			cover::bs[i] = 0;
		}
		for(int i=0;i <n; i++) cin >> W[i];
		for(int i=0;i <m; i++){
			int a, b; cin >> a >> b; a--, b--;
			cover::bs[a][b] = 1, cover::bs[b][a] = 1;
		}
		int ans = cover::solve();
		cout << ans << endl;
	}
	
	
	exit(0);
}
