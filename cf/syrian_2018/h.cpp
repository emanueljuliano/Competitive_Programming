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

int main(){ _
	freopen("bugged.in", "r", stdin);	
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		vector<int> dg(n);
		ll ans = 0;
		for(int i=0;i <m; i++){
			int a, b; cin >> a >> b; a--, b--;
			ans += abs(v[a] - v[b]);
			dg[a]++, dg[b]--;
		}
		
		bool show = true;
		for(int i=0;i <n; i++) if(dg[i]) show = false;
		if(show) cout << ans << endl;
		else cout << -1 << endl;

	}
	
	
	exit(0);
}
