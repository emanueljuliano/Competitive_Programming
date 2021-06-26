#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
typedef pair<ll, ll> ii;

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, x; cin >> n >> x;
		vector<ii> v(n, {1, 1});
		ll ans = 0;
		for(auto &i : v) cin >> i.f, ans+=i.f;
		for(int i=0;i <v.size(); i++){
			if(v[i].f%x==0){
				v.pb({v[i].f/x, x*v[i].s});
				ans += v[i].s*v[i].f;
			}
			else break;
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
