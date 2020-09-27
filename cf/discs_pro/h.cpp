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

const ll MOD = 1e9 + 7;
const int MAX = 6e6+10;

ll fat[MAX];
void fator(ll lim){
	fat[0] = 1;
	for(ll i=1;i <lim; i++){
		fat[i] = (i*fat[i-1]%MOD)%MOD;
	}
}

ll inv(ll a, ll b){
  if(1 < a) return b - inv(b % a, a) * b/a;
    else return 1;
}

ll comp(ll n, ll x){
	return (fat[n] * inv(fat[x], MOD) %MOD * inv(fat[n-x], MOD) %MOD)%MOD;
}

int main(){ _
	fator(MAX);
	int n; cin >> n;
	ll pos = n*(n-1)/2;
	ll ans = 0;
	for(ll i=1;i <pos; i++){
		ans = ans + i * comp(pos, i)%MOD;
		ans %= MOD;
	}
	cout << ans << endl;
	
	
	
	exit(0);
}
