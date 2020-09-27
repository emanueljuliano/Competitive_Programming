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

const int MOD = 998244353;

ll fpow(ll a, ll b){
	if(b==0) return 1;
	if(b%2) return a*fpow(a, b-1)%MOD;
	return fpow(a*a%MOD, b/2)%MOD;
}

ll inv(int x){
	return fpow(x, MOD-2);
}

int main(){ _
	int n, m; cin >> n >> m;
	vector<int> v(n);
	vector<ll> sum;
	for(auto &i: v) cin >> i;
	sort(v.begin(), v.end());
	sum.pb(0);
	for(auto u : v) sum.pb((u+sum.back())%MOD);
	
	while(m--){
		int a, b; cin >> a >> b;
		int lo = lower_bound(v.begin(), v.end(), b) - v.begin();
		int big = n-lo;
		if(a>big){
			cout << 0 << endl;
			continue;
		}		
		ll ans = (1-a*inv(big+1)%MOD)*sum[lo]%MOD + (1-a*inv(big)%MOD)*(sum.back()-sum[lo])%MOD;
		cout << (ans%MOD+MOD)%MOD << endl;
	}

	exit(0);
}
