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
const ld eps = 1e-9;

int main(){ _
	ld n;
	while(cin >> n){
	ld h, c, l; cin >> h >> c >> l;
	ld x = n*sqrt(sq(h) + sq(c));

	cout << setprecision(4) << fixed;
	cout << x*l/10000.0 << endl;
	}
	exit(0);
}
