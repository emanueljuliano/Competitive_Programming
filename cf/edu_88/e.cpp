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

ll fpow(ll a, ll b){
	if(b==0) return 1;
	if(b==1) return a;
	if(b%2) return (a*fpow(a*a%MOD, b/2)%MOD)%MOD;
	return (fpow((a*a)%MOD, b/2)%MOD);
}

ll inv(ll x){ return fpow(x, MOD-2);}
ll fat[(int)5e5+10];
ll esc(ll a, ll b){
	if(b>a) return 0;
//	cout << fat[a] << " " << inv(fat[b]) << endl;
	return (fat[a]*inv(fat[b])%MOD*inv(fat[a-b])%MOD)%MOD;
}

void fatorial(){
	fat[0] = 1;
	fat[1] = 1;
	for(int i=1; i<(int)5e5+10; i++){
		fat[i] = (i*fat[i-1])%MOD;
	}
}

int main(){ _
	fatorial();
	ll n, k; cin >> n >> k;	
	ll ans = 0;
	for(int i=1; i<=n; i++){
		ll nmul = n/i -1;
		ans = ans + esc(nmul, k-1);
		ans %= MOD;
	}
	cout << ans << endl;
	
	
	exit(0);
}
