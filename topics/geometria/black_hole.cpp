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

const int INF = 0x3f3f3f3f;
const ld eps = 1e-6;

int main(){ _
	int t; cin >> t;
	int aux = t;
	while(t--){
		ld x1, x1l, y1, y1l, x2, x2l, y2, y2l;
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		cin >> x1l >> y1l;
		cin >> x2l >> y2l;

		ld a = (2.0*x1l - 2.0*x1);
		ld b = (2.0*y1l - 2.0*y1);
		ld c = (sq(x1l) - sq(x1) + sq(y1l) - sq(y1));
		
		ld d = (2.0*x2l - 2.0*x2);
		ld e = (2.0*y2l - 2.0*y2);
		ld f = (sq(x2l) - sq(x2) + sq(y2l) - sq(y2));
		
		ld x = (c*e - f*b)/(e*a - d*b);
		ld y = (f - d*x)/e;
		cout << setprecision(2) << fixed;
		cout << "Caso #" <<aux-t << ": "<<  x+eps << " " << y+eps << endl;
	}


	exit(0);
}
