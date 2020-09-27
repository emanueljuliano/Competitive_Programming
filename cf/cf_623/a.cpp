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
	int t;cin >> t;
	while(t--){
		int a, b, x, y; cin >> a >> b >> x >> y;
		int a1, a2, a3, a4;
		a1 = (a-1-x)*b;
		a2 = (x)*b;
		a3 = (b-1-y)*a;
		a4 = a*y;
		int ans = max(a1, max(a2, max(a3, a4)));
		cout << ans << endl;
	
	}
	
	
	
	exit(0);
}
