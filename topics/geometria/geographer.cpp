#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x.size())
#define pb push_back
#define s second
#define f first
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define sq(x) ((x)*(x))

typedef long long ll;
typedef pair<int, int> ii;
typedef double ld;

const ld pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const ld eps = 1e-9;

int main(){ _
	ld r, la, lo;
	while(cin >> r >> la >> lo){
		ld x, y, z;
		y = r*sin(la/180.0*pi);
		r *= cos(la/180.0*pi);
		x = r*sin(lo/180.0*pi);
		z = -r*cos(lo/180.0*pi);
	
		cout << setprecision(2) << fixed;
		cout << x+eps << " " << y+eps << " " << z+eps << endl;
	}


	exit(0);
}
