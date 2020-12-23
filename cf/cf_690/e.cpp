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

const int MOD = 1e9+7;
const int MAX = 2e5+10;

ll fat[MAX], ifat[MAX];

ll comb(ll a, ll b) {
	if (b > a) return 0;
	return fat[a] * ifat[b] % MOD * ifat[a-b] % MOD;
}

ll choose(ll a, ll b){
	if(a<b or a<0 or b<0) return 0;
	if(a==b or b==0) return 1;
	ll ret = fat[a]*ifat[b]%MOD*ifat[a-b]%MOD;
	return ret%MOD;
}

int main(){ _
	fat[0] = 1;
	for(ll i=1; i<MAX; i++) fat[i] = i*fat[i-1]%MOD;
	ifat[MAX-1] = 758835755;
	for (int i = MAX-2; i >= 0; i--) ifat[i] = ifat[i+1]*(i+1)%MOD;
	int t; cin >> t;
	while(t--){
		ll ans = 0;
		int m, k;
		int n; cin >> n >> m >> k;
		vector<int> v(n);
		vector<ll> f(2*n+10);
		for(auto &i:v) cin >> i, f[i]++;
	
		vector<ll> pref;
		pref.pb(0);
		for(auto u : f) pref.pb(pref.back()+u);
		
		for(int i=1;i <=n; i++){
		//	cout << pref[i+k+1] << " " << pref[i] << endl;
		//	for(int j=1;j <=m; j++) 
		//		ans = (ans + choose(f[i], j)*choose(pref[i+k+1] - pref[i+1], m-j)%MOD)%MOD;
			ans = (ans+ choose(pref[i+k+1] - pref[i], m)%MOD)%MOD;
			ans = (ans - choose(pref[i+k+1] - pref[i+1], m) + 2*MOD)%MOD; 
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
