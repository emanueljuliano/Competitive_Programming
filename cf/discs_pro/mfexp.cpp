const int MOD = 1e9+7;
const int sz = 2;

typedef vector<vector<ll> > mat;

mat idty() {
	mat id(sz, vector<ll>(sz,0));
	for(int i=0; i<sz; i++) id[i][i] = 1;
	return id;
}

mat z(sz, vector<ll>(sz,0));
void mmul(mat &x, mat &y) {
	for(int i=0; i<sz; i++) for(int j=0; j<sz; j++) z[i][j] = 0;

	for(int i=0; i < sz; i++) {
		for(int j=0; j < sz; j++) {
			for(int k=0; k < sz; k++)
				z[i][j] += x[i][k]*y[k][j];	
			z[i][j] %= MOD;	
		}	
	}
	for(int i=0;i <sz; i++) for(int j=0;j <sz; j++) x[i][j] = z[i][j];
}

mat z2(sz,vector<ll>(sz));
void mfexp(mat &x, ll y) {
	z2 = idty();

	while (y) {
		if (y & 1) mmul(z2,x);
		y >>= 1;
		mmul(x,x);
	}

	for(int i=0;i <sz; i++) for(int j=0;j <sz; j++) x[i][j] = z2[i][j];
}
