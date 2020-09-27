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
const int MOD = 998244353;

ll fpow(ll x, ll y) { // iterativo
	ll ret = 1;
	if(y<0) return 0;
	while (y) {
		if (y & 1) ret = (ret * x) % MOD;
		y >>= 1;
		x = (x * x) % MOD;
	}
	return ret;
}

int main(){ _
	int n; cin >> n;
	for(ll x=n-1; x>0; x--){
		ll ans = 2*9*fpow(10, x-1)%MOD; 
		ans = ans + (x-1)*9*9*fpow(10, x-2)%MOD;
		ans%=MOD;
		ans *= 10;
		ans%=MOD;
		cout << ans << " ";
	}
	cout << 10 << endl;	
	
	exit(0);
}
