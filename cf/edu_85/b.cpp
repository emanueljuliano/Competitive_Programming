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


int main(){ _
	int t; cin >> t;
	while(t--){
		ll n; cin >> n;
		ll x; cin >> x;
		vector<ll> v;
		for(int i=0;i <n; i++){
			ll a; cin >> a;
			v.pb(a);
		}
		sort(v.begin(), v.end(), greater<>());
		int ans = 0;
		ll soma = 0;
		for(ll i=0;i <n; i++){
			soma += v[i];
			if(soma >= x*(i+1)) ans++;
			else break;
		}
		cout << ans << endl;
	
	}
	
	
	
	exit(0);
}
