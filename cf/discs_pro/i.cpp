#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MOD = 1e9+7;

ll z[2][2];
void mmul(ll x[][2], ll y[][2]) {
	ll a = 2;
	ll b = 2;
	ll c = 2;
	z[0][0] = (x[0][0]*y[0][0] + x[0][1]*y[1][0])%MOD;
	z[0][1] = (x[0][0]*y[0][1] + x[0][1]*y[1][1])%MOD;
	z[1][0] = (x[1][0]*y[0][0] + x[1][1]*y[1][0])%MOD;
	z[1][1] = (x[1][0]*y[0][1] + x[1][1]*y[1][1])%MOD;
	for(int i=0;i <2; i++) for(int j=0;j <2; j++) x[i][j] = z[i][j];
}

ll z2[2][2];
void mfexp(ll x[][2], ll y) {
	ll z2[2][2] = {{1, 0}, {0, 1}};

	while (y) {
		if (y & 1) mmul(z2,x);
		y >>= 1;
		mmul(x,x);
	}
	for(int i=0;i <2; i++) for(int j=0; j<2; j++) x[i][j] = z2[i][j];
}


int main(){ _
	int t; cin >> t;
	ll a, n;
	while(t--){
		cin >> a >> n; a%=MOD, a+=MOD, a%=MOD;
		n= abs(n);
		
		if(n==0){cout << 2 << endl; continue;}
		
		ll m[2][2] = {{a, MOD-1}, {1, 0}};
		mfexp(m, n-1);
		cout << (a*m[0][0] + m[0][1]*2)%MOD << endl;
	}
	exit(0);
}

