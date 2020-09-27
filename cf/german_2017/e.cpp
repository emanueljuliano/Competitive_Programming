#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;


const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool show;
int sz;

typedef vector<vector<ld> > mat;

mat idty() {
	mat id(sz, vector<ld>(sz,0));
	for(int i=0; i<sz; i++) id[i][i] = 1;
	return id;
}

mat z;
void mmul(mat &x, mat &y) {
	for(int i=0; i<sz; i++) for(int j=0; j<sz; j++) z[i][j] = 0;

	for(int i=0; i < sz; i++) 
		for(int j=0; j < sz; j++) 
			for(int k=0; k < sz; k++)
				z[i][j] += x[i][k]*y[k][j];
			
		
	
	for(int i=0;i <sz; i++) for(int j=0;j <sz; j++) x[i][j] = z[i][j];
}

mat z2(sz,vector<ld>(sz));
void mfexp(mat &x, ll y) {
	z2 = idty();

	while (y) {
		if (y & 1) mmul(z2,x);
		y >>= 1;
		mmul(x,x);
	}

	for(int i=0;i <sz; i++) for(int j=0;j <sz; j++) x[i][j] = z2[i][j];
}

int main(){ _
	int n, m; cin >> n >> m;
	sz = n;
	z = mat(sz, vector<ld>(sz,0));
	vector M(n, vector<ld> (n));
	for(int i=0;i <m; i++){
		int a, b; ld c; cin >> a >> b >> c; a--, b--;
		M[a][b] = c;
	}

	show = true;
	mfexp(M, 800);
//		cout << "DIAG: ";
	for(int i=0;i <n; i++){
//		cout << M[i][i] << " ";
		if(M[i][i] >= 1.1) show = false;
	}
//		cout << endl;

	if(show) cout << "admissible" << endl;
	else cout << "inadmissible" << endl;
	exit(0);
}
