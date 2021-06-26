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

const int MAX = 5e3+10;
ll dp[MAX][MAX];
const int MOD = 1e9+7;

int n;
ll	solve(int p, int k){
	if(p<1 or p>n) return 0;
	if(k<0) return 0;	
	ll &ret = dp[p][k];
	if(ret != -1) return ret;
	if(k==0) return ret = 1;

	ret = (solve(p+1, k-1) + solve(p-1, k-1))%MOD; 
	return ret;
}

int main(){ _
	memset(dp, -1, sizeof dp);	
	
	int k, q; cin >> n >> k >> q;
	vector<ll> v(n);
	for(auto &i : v) cin >> i;

	for(int i=1; i<=n; i++) solve(i, k);
	vector<ll> w(n);
	for(int i=0;i <n; i++) for(int j=0; j<=k; j++) w[i]=(w[i]+solve(i+1, j)*solve(i+1, k-j))%MOD;
	//for(auto u : w) cout << u << " ";
	//cout << endl;
	ll ans = 0;
	for(int i=0;i <n; i++) ans = (ans+w[i]*v[i]%MOD)%MOD;

	while(q--){
		int i, x; cin >> i >> x; i--;
		ans = (ans-w[i]*v[i]%MOD+MOD)%MOD;
		v[i] = x;
		ans = (ans+w[i]*v[i]%MOD)%MOD;
		cout << ans << endl;
	}
	
	
	exit(0);
}
