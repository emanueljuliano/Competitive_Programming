#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x.size())
#define pb push_back
#define s second
#define f first
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define sq(x) ((x)*(x))
#define pi M_PI

typedef long long ll;
typedef pair<int, int> ii;
typedef double ld;

const int INF = 0x3f3f3f3f;
const ld eps = 1e-9;

int main(){ _
	ld a;
	while(cin >> a){
		ld aux = sq(cos(pi/6) - cos(pi/3)) + sq(sin(pi/3) - sin(pi/6));
//		cout << aux*sq(a) << " " << sq(a)/sq(4*cos(pi/12)) << endl;
		ld x = aux*sq(a) + (pi-3.0)*sq(a)/3.0;
		ld y = pi*sq(a)/2 - sq(a) - x;
		y*=2;
		ld z = a*a - x - y;
		cout << setprecision(3) << fixed;
		cout << x << " " << y << " " << z << endl;
	}


	exit(0);
}
