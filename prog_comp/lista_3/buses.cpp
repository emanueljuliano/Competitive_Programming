#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vector<ll>> matrix;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e6;

matrix mul(matrix a, matrix b){
	matrix ret{{0, 0}, {0, 0}};
	for(int i=0; i<2; i++) for(int j=0; j<2; j++)
		for(int k=0; k<2; k++) ret[i][j] = (ret[i][j] + a[i][k]*b[k][j]%MOD)%MOD;
	return ret;
}

matrix id(){
	matrix ret{{1, 0}, {0, 1}};
	return ret;
}

matrix pow(matrix a, ll k){
	if(!k) return id();
	if(k%2) return mul(a, pow(a, k-1));
	return pow(mul(a, a), k/2);
}

int main(){ _
	
	ll n, k, l;
	while(cin >> n >> k >> l){
		k%=MOD, l%=MOD, n/=5;
		matrix m{{k, l}, {1, 0}};

		m = pow(m, n);
		ll ans = m[0][0];
		ll aux = MOD;
		while(aux!=1){
			ll dig = ans%aux;
			aux/=10;
			cout << dig/aux;
		}
		cout << endl;
	}
	exit(0);
}
