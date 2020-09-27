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
	int n, m; cin >> m >> n;
	while(n--){
		ll x, k; cin >> x >> k;
		vector<ll> v(m, 0);
		int it = 0;
		while(x!=0){
			v[it]=(x%2);
			x/=2;
			it++;
		}
		ll shift = k%m;
		ll ans = 0;
		for(ll i=0;i <v.size(); i++){
			ans+= v[i]<<((i+shift)%m);
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
