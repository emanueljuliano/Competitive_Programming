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


int main(){ _
	int t; cin >> t;
	while(t--){
		int m, d, w; cin >> m >> d >> w;
		
		// (y-x)(d-1) ≡ 0 mod(w)
		// (y-x)(d-1) = k*w
		// (y-x) divides w/gcd(w, d-1)
		// y = x + c(w/gcd(w, d-1)) for all c | 1 <= c <= (min(d, m)-1)(gcd(d-1, w))/w;

		int g = w/gcd(d-1, w);
		int n = min(d, m);
		int c = (n-1) / g;
		int a1 = n - c*g;
		int an = n - g;
		cout << (ll)(a1+an)*c/2 << endl;
	}

	exit(0);
}
