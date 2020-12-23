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

int main(){ 
	freopen("plants.in", "r", stdin); _		
	
	int n; cin >> n;
	vector<int> h(n), g(n);
	for(auto & i: h) cin >> i;
	for(auto & i: g) cin >> i;
	
	vector<ii> inter;
	for(int i=0;i <n-1; i++){
		ii ret = {0, INF};
		if(h[i]<=h[i+1]){
			// h[i]+g[i]*x > h[i+1]+g[i+1]*x
			// x>(h[i]-h[i+1])/(g[i+1]-g[i])
			if(g[i]<=g[i+1]) ret.s= INF;
			else ret.s = (h[i+1]-h[i])/(g[i]-g[i+1]);
		}
		else{
			// h[i]+g[i]*x <= h[i+1]+g[i+1]*x
			// (h[i]-h[i+1])/(g[i+1]-g[i]) <= x
			if(g[i]>=g[i+1]) ret.f= INF;
			else ret.f = (h[i]-h[i+1] + g[i+1]-g[i]-1)/(g[i+1]-g[i]);
		}
		inter.pb(ret);
	}

	ii ans = {0, INF};
	for(auto [l, r] : inter) ans.f=max(ans.f, l), ans.s=min(ans.s, r);

	if(ans.f!=INF and ans.f<=ans.s) cout << ans.f << endl;
	else cout << -1 << endl;

	
	exit(0);
}
