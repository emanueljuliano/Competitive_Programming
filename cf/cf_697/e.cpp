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

ll inv(ll a, ll b) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}

const int MOD = 1e9+7;
int main(){ _
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n>> k;
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		sort(v.begin(), v.end(), greater<>());
		int at = v[k-1];
		int cnt = 0;
		int ma = 0;
		for(auto u : v){
			if(u==at) cnt++;
			if(u>at) ma++;
		}
		

		ll ans = 1;
		ll a = cnt, b = k-ma;
		for(int i=a; i>a-b; i--) ans = (ans*i)%MOD;
		for(int i=1; i<=b; i++) ans = (ans*inv(i, MOD))%MOD;
		
		cout << ans << endl;

		// ans = k-ma chose u
	}
	
	
	
	exit(0);
}
