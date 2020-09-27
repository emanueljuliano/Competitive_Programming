// Template padrão para questoes de recorrencia linear

typedef vector<ll> vi;
typedef vector<vi> vvl;

int MOD=1000000007;
int sz = 3;

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

