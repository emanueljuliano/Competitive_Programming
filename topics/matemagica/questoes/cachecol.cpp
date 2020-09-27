#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvl;

int MOD=1000000007;
int sz = 2;

vvl matmul(vvl m1, vvl m2){
	vvl ret;
	ret.resize(m1.size(), vi(m2.size(), 0));
	for(int i=0; i<sz; i++)
		for(int j=0; j<sz; j++)
			for(int k = 0; k<sz; k++){
				ret[i][j] += m1[i][k] * m2[k][j];
        		ret[i][j] %= MOD;
			}
	return ret;
}

vvl identity(ll k){
  vvl v(k, vector<ll>(k, 0));
  for (int i = 0; i < k; i++)
    v[i][i] = 1;
  return v;
}

vvl matpow(vvl m1, ll p){
  if (p == 0) return identity(m1.size());
	if(p==1) return m1;
	if(p%2==0) return matpow(matmul(m1, m1), p/2);
	else return matmul(m1, matpow(matmul(m1, m1), (p-1)/2));
}

int main(){ _
	ll n; cin >> n;
	vvl M(2, vi(2, 2));
	M[0][0] = 3;
	M = matpow(M, n-1);
	ll ans = (M[0][0] + M[0][1] + M[1][0] + M[1][1])%MOD*6%MOD;
	cout << ans << endl;
	exit(0);
}
