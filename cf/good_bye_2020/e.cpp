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

int main(){ _
		
	int t; cin >> t;
	while(t--){
		ll ans = 0;
		ll n; cin >> n;
		vector<ll> v(n);
		for(auto &i : v) cin >> i;

		vector<ll> ap(66);
		for(int i=0;i <n; i++) for(int msk = 0; msk<62; msk++){
			if(v[i] & 1LL<<msk) ap[msk]++;
		}
		
		for(int i=0;i <n; i++) {
			ll first = 0, second=0;
			for(int msk=0; msk<62; msk++){
				if(v[i]&(1LL<<msk)){
					first += (1LL<<msk)%MOD * ap[msk]%MOD ;
					first%=MOD;
					second += (1LL<<msk)%MOD*n%MOD;
					second%=MOD;
				}
				else{
					second += (1LL<<msk)%MOD*ap[msk]%MOD;
					second%=MOD;
				}
			}
			ans += first*second;
			ans%=MOD;
		}
		cout << ans << endl;
	}
	
	
	exit(0);
}
