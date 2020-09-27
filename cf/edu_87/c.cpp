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
typedef double ld;

const ld pi = acos(-1.0);

int main(){ _
	int t; cin >> t;
	while(t--){
		ld r;
		ld n; cin >> n;
		n*=2;
		ld x1 = int(n/4.0);
		ld x2 = x1+1.0;
		r = 1.0/(2*sin(pi/n));
		
		ld l1 = sqrt(r*r + r*r - 2*r*r*cos(2*pi*x1/n));
		ld l2 = sqrt(r*r + r*r - 2*r*r*cos(2*pi*x2/n));
		ld ans = sqrt(2.0)/2.0*(l1+l2);
		
		cout << setprecision(6) << fixed;
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
