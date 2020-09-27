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

const int MOD = 1e9+7;
ll n, m;
ll pow(ll x, ll y, ll m) { // recursivo
	if (!y) return 1;
	ll ans = pow(x*x%m, y/2, m);
	return y%2 ? x*ans%m : ans;
}

ll inv(ll a, ll b){
	if(1 < a) return b - inv(b % a, a) * b/a;
	else return 1;
}
ll inv(ll x){
	return inv(x, MOD);
}

ll fat[(int)1e5+5];
ll choose(ll n, ll m){
//	cout << "CHOOSE" << endl;
//	cout << n << " " << m << endl;
//	cout << fat[n] << " " << inv(fat[m]) << " " << inv(fat[n-m]) << endl;
	return ((fat[n]%MOD*inv(fat[m])%MOD)%MOD*inv(fat[n-m])%MOD)%MOD;
}

int main(){ _
	int t; cin >> t;
	fat[0] = 1;
	for(ll i=1;i <(int)1e5+4; i++) fat[i] = (fat[i-1]*i)%MOD;
	while(t--){
		cin >> n >> m;
		ll y = choose(n-1, m-1);
	//	cout << y << " " << n <<" " << inv(n-m+1) << endl;
		ll x = y*n%MOD*inv(n-m+1)%MOD;
		cout << x << " " <<y << endl;
	}


	exit(0);
}
