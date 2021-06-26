#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		ld n, p1, p2, v1, v2; cin >> n >> p1 >> v1 >> p2 >> v2;
		ld ans = 1e15;
		if(p2<p1) swap(p1, p2), swap(v1, v2);

		// Sozinho
		ans = min(ans, 2*min(n-p1, p1)/v1 + max(n-p1, p1)/v1);
		ans = min(ans, 2*min(n-p2, p2)/v2 + max(n-p2, p2)/v2);

		// Ignora -> <-
		ans = min(ans, max(p2/v2, (n-p1)/v1));

		// Colide
		// -> <-
		ld x = ((n-p2)*v1 - p1*v2 + 2*(p2-p1)*v1)/(2*(v2+v1));
		if(x>=0 and x<=p2-p1) ans = min(ans, (p1+2*x)/v1);

		// -> ->
		ans = min(ans, max((p2-p1+p2)/v1, (n-p2)/v2));
		x = (2*(n-p2)*v1 + p2*v1 - p1*v1 - p1*v2)/(2*v2 + v1);
		if(x>=0 and x<=p2-p1) ans = min(ans, (2*x + p1)/v1);

		// <- <-
		ans = min(ans, max(p1/v1, ((p2-p1)+(n-p1))/v2));
		x = (2*(p2-p1)*v1 + (n-p2)*v1 - 2*p1*v2)/(v2 + 2*v1);
		if(x>=0 and x<=p2-p1) ans = min(ans, (2*p1 + x)/v1);

		// <- ->
		ld d, tm, nt, np1, np2;
		
		// p1 chegou antes
		if(p1/v1 <= (n-p2)/v2){
			nt = p1/v1;
			np1 = 0, np2=p2+nt*v2;
			d = n + (n-np2);
			tm = d/(v1+v2);
			ans = min(ans, nt + tm);
			ans = min(ans, nt + max(p2/v1, (n-np2)/v2));
		}
		else{
			// p2 chegou antes
			nt = (n-p2)/v2;
			np1 = p1-v1*nt, np2=n;
			d = np1 + n;
			tm = d/(v1+v2);
			ans = min(ans, nt + tm);
			ans = min(ans, nt + max(np1/v1, (n-p1)/v2));
		}

		cout << setprecision(9) << fixed;
		cout << ans << endl;

	}
	
	
	
	exit(0);
}
