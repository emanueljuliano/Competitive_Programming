#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int magic = 4e5;
ll x, y;
ll ch[45][45];

ll choose(int a, int b) {
	if (a == b or b == 0) return 1;
	if (a < b) return 0;
	if (ch[a][b] != -1) return ch[a][b];
	ll ret = ch[a][b] = choose(a-1, b-1) + choose(a-1, b);
	return ret;
}

ll f(ll k) {
	if (y == 0) return k == (1ll<<x)-1;
	if (x == 1) return k == 1ll << (x+y-1);
	int cnt = 1;
	ll ret = 0;
	for (int i=x+y-2; i>=0; i--) if (k & (1ll<<i)) {
		ret += choose(i, x-cnt);
		cnt++;
		if (cnt == x) {ret++; break;}
	}
	return ret;
}

ll dp[2][45][magic+10];

int main(){ _
	#warning FILE IN 
    freopen("zeros.in", "r", stdin);	
	
	int t; cin >> t;
	while (t--) {
		memset(ch, -1 , sizeof ch);
		ll m, k; cin >> x >> y >> m >> k;

		if (m > magic) {
			ll ans = 0;
			for (ll i = m-1; i<=max(2*m, (2ll<<(x+y))); i+=m) {
				if (i < (1ll<<(x+y-1))) continue;
				ll a=i, b=i-m+k;
				if (b < (1ll<<(x+y-1))) b = 0;
				if (a >= (1ll<<(x+y))) {
					a = (1ll<<(x+y)) - 1;
					if (a > b) 
						ans += max(0ll, f(a) - f(b));
					break;
				}
				else ans += max(0ll, f(a) - f(b));
			}

			cout << ans << endl;
		}
		else {
			memset(dp, 0, sizeof dp);
			x--;
			for (int i=k; i<=m-1; i++) dp[(x+y)&1][0][i] = 1;
			for (int i=x+y-1; i+1; i--) for(int j=0; j<=x; j++)
			for (int l = 0; l<m; l++) {
				dp[i&1][j][l] = dp[~i&1][j][l];
				int prev = ((l + (1ll<<i))%m + m) % m;
				if (j) dp[i&1][j][l] += dp[~i&1][j-1][prev];
			}

			cout << dp[0][x][(1ll << (x+y))%m] << endl;
		}
	}
	
	
	exit(0);
}
