#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	ld h1, t1; cin >> h1 >> t1;
	ld h2, t2; cin >> h2 >> t2;
	
	if (t1 < t2) swap(t1, t2), swap(h1, h2);

	ld l = 0, r = 1e9;
	for (int i=0; i<200; i++) {
		ld g = (l+r)/2;
		ld q1 = t1 - sqrt(2*h1/g);
		ld q2 = t2 - sqrt(2*h2/g);
		if (q1 > q2) r = g;
		else l = g;
	}
	ld g = (l+r)/2;
	ld d = t1 - sqrt(2*h1/g);
	cout << setprecision(9) << fixed;
	cout << d << endl;
	
	
	exit(0);
}
