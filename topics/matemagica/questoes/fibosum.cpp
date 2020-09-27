#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvl;
typedef vector<vector<ll > > matrix;

ll MOD=1000000007;
vvl mult(vvl M1, vvl M2){
	vvl M3(3, vector<ll> (3, 0));
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			ll soma = 0;
			for(int k = 0; k<3; k++){
				M3[i][j] += M1[i][k]*M2[k][j];
        	M3[i][j] %= MOD;
			}
		}
	}
	return M3;
}

vvl identity(ll k){
  matrix v(k, vector<ll>(k, 0));
  for (int i = 0; i < k; i++)
    v[i][i] = 1;
  return v;
}

vvl fexp(vvl M, ll k){
  if (k == 0) return identity(M.size());
	if(k==1) return M;
	if(k%2==0) return fexp(mult(M, M), k/2);
	else return mult(M, fexp(mult(M, M), (k-1)/2));
}

ll maxi(ll a, ll b){
	if(a>b) return a;
	return b;
}
int main(){ _
	
	matrix M(3, vi(3, 1));
	M[2][2] = 0;	
	M[2][0] = 0;	
	M[1][0] = 0;	
	M[0][2] = 0;	
	int t; cin >> t;
	while(t--){
		ll n, m; cin >> n >> m;
		matrix a1 = fexp(M, maxi(0, n-1));
		matrix a2 = fexp(M, m);
		cout << (a2[0][1] - a1[0][1] + MOD)%MOD << endl;
	}

	exit(0);
}
