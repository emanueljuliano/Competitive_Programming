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

typedef vector<vector<ll> > mat;
const int MOD = 1e9+7;
int sz = 2;
mat idty(int a) {
	mat id(a, vector<ll>(a,0));
	for(int i=0; i < a; i++) {	
		for(int j=0; j < a; j++) 
			if(i == j) id[i][j] = 1;
	}
	return id;
}

mat z(2, vector<ll>(2,0));
void mmul(mat& x, mat& y) {
	z[0][0]=0, z[0][1]=0, z[1][0]=0, z[1][1]=0;

	for(int i=0; i < sz; i++) {
		for(int j=0; j < sz; j++) {
			for(int k=0; k < sz; k++) {
				z[i][j] += x[i][k]*y[k][j];
			}	
			z[i][j] %= MOD;	
		}	
	}
	for(int i=0;i<sz; i++) for(int j=0; j<sz; j++) x[i][j] = z[i][j];
}

void mfexp(mat &x, ll y) { // iterative
	mat z2 = idty(sz);
	while (y) {
		if (y & 1) mmul(z2,x);
		y >>= 1;
		mmul(x,x);
	}
	for(int i=0; i<sz; i++) for(int j=0;j <sz; j++) x[i][j] = z2[i][j];
}


int main(){ _
	int t; cin >> t;
	mat m(2, vector<ll>(2,0));
	while(t--){
		ll a, n; cin >> a >> n; a%=MOD, a+=MOD, a%=MOD;
		n= abs(n);
		// s[i] = s[i-1]*a + s[i-2]
		if(n==0){cout << 2 << endl; continue;}
		m[0][0] = a, m[0][1] = MOD-1, m[1][0]=1, m[1][1] = 0;
		mfexp(m, n-1);
		cout << (a*m[0][0]%MOD + m[0][1]*2)%MOD << endl;
	}



	exit(0);
}

