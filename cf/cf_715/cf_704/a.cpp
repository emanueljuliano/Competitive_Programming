#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while (t--) {
		ll p, a, b, c; cin >> p >> a >> b >> c;
		ll ans = LINF;
		ans = min(ans, (p+a-1)/a*a);
		ans = min(ans, (p+b-1)/b*b);
		ans = min(ans, (p+c-1)/c*c);
		cout << ans-p << endl;
	}
	
	
	
	exit(0);
}
