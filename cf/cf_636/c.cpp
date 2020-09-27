#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	ll t; cin >> t;
	while(t--){
		vector<ll> v;
		ll n; cin >> n;
		for(ll i=0;i <n; i++){
			ll a; cin >> a;
			v.pb(a);
		}
		ll at = v[0];
		ll ans = 0;
		for(ll i=1;i <n;i ++){
			if(v[i]>0 and at>0){
				at = max(at, v[i]);
			}
			else if(v[i]<0 and at<0)  at = max(at, v[i]);
			else{
				ans += at;
				at = v[i];
			}
		}
		ans += at;
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
