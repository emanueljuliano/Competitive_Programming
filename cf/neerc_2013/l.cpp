#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	ll d; int n, a, b; cin >> n >> d >> a >> b;	
	
	ll prev = 0, cur = 0;
	ll x = 0, y = 0;

	for (int i=0; i<n; i++) {
		int at; cin >> at;
		if (i != 0)  {
			if (at > prev) {
				x += a;
				y = 0;
				ll buy_now = min(d/at, x);
				d -= buy_now*at;
				cur += buy_now;
			}
			if (at < prev) {
				y += b;
				x = 0;
				ll sell_now = min(y, cur);
				d += sell_now*at;
				cur -= sell_now;
			}
		}
		prev = at;
	}
	
	cout << d << " " << cur << endl;

	exit(0);
}
