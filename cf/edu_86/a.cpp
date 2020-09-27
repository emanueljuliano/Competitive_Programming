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
		ll a, b;
		cin >> a >> b;
		ll x, y; 
		cin >> x >> y;
		ll ans = 0;
		ans += abs(a-b)*x;
		ll aux = min(a, b);
		ans += min(aux*y, 2*aux*x);
		cout <<ans << endl;
	}
	
	
	
	exit(0);
}
