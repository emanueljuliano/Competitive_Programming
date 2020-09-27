#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vvl;

const int MOD = 1000000;

vvl mult(vvl M1, vvl M2){
	vvl ret(2, vector<ll> (2, 0));
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			for(int k=0; k<2; k++){
				ret[i][j] +=  M1[i][k]*M2[k][j];
				ret[i][j] %= MOD;
			}
		}
	}
	return ret;
}

vvl I(2, vector<ll> (2, 0));

vvl fexp(vvl M, ll n){
	if(n==0)
		return I;
	if(n%2==0) return fexp(mult(M, M), n/2);
	else return mult(M, fexp(M, n-1));
}

int main(){

    I[0][0] = 1, I[1][1] = 1;
	ll n, k, l;
	
	while(cin >> n >> k >> l){
		n /= 5;
		vector<vector<ll>> M(2, vector<ll> (2, 0));
		M[1][0] = 1;
		M[0][0] = k;
		M[0][1] = l;

		vector<vector<ll>> M2 = fexp(M, n-1);
		ll ans = M2[0][1] + k*M2[0][0];
		cout << ans%MOD << endl;
	}
	

	exit(0);
}
