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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MOD = 1e9+7;
const int MAX = 2e5+10;

ll fat[MAX], ifat[MAX];

ll comb(ll a, ll b) {
	if (b > a) return 0;
	return fat[a] * ifat[b] % MOD * ifat[a-b] % MOD;
}

ll meb[MAX];

void crivo(int lim) {
	for (int i = 2; i <= lim; i++) meb[i] = 2;
	meb[1] = 1;
	for (int i = 2; i <= lim; i++) if (meb[i] == 2)
		for (int j = i; j <= lim; j += i) if (meb[j]) {
			if (meb[j] == 2) meb[j] = 1;
			meb[j] *= j/i%i ? -1 : 0;
		}
}

int main(){ _
	fat[0] = 1;
	for (int i = 1; i < MAX; i++) fat[i] = fat[i-1]*i%MOD;
	ifat[MAX-1] = 758835755;
	for (int i = MAX-2; i >= 0; i--) ifat[i] = ifat[i+1]*(i+1)%MOD;
	crivo(MAX-2);

	int q; cin >> q;
	while(q--){
		ll n, f; cin >> n >> f;
		
		ll ans = comb(n-1, f-1);
		
		//cout << n << " " << f << " = " << ans << endl;
		for(ll i=2; i*i<=n; i++) if(n%i==0){
			ans = (ans + meb[i]*comb(n/i-1, f-1)%MOD + MOD)%MOD;
			//cout << n/i << " " << meb[n/i] << " " << endl;
			//cout << n/i << " " << f << " = " << ans << endl;
			if(i*i!=n) ans = (ans + meb[n/i]*comb(i-1, f-1)%MOD + MOD)%MOD;
			//cout << i << " " << meb[i] << " " << endl;
			//cout << i << " " << f << " = " << ans << endl;
		}
		if(f==1 and n!=1) ans = 0;	
		cout << (ans%MOD+MOD)%MOD << endl;
	}
	
	
	
	exit(0);
}
