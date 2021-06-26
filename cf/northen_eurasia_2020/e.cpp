#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll inv(ll a, ll b) {
	return a > 1 ? b - inv(b%a, a)*b/a : 1;
}

int main(){ _
	int n; cin >> n;
	
	for (int i=0; i<n; i++) {
		ll B, D; cin >> B >> D;
		ll c = B*B, a = D, b = B;
		// c = a*x + b*y
		ll g = gcd(gcd(c, a), b);
		c /= g, a /= g, b /= g;
		ll y = (c%a)*inv(b, a)%a;
		//cout << " c = " << c << " a = " << a << " b = " << b << " y = " << y << endl;
		ll ans = (c-1)/b/a;
		if (y!=0 and (y+ans*a)*b <= c-1) ans++;
		if (y*b >= c) ans = 0;
		cout << ans << endl;
	}
	
	exit(0);
}
