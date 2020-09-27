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
		ll x, y, k; cin >> x >> y >> k;
		x--;
		ll ans = k;
		ll prec = k*y+k-1;
		ans +=(prec+x-1)/x;
		cout << ans << endl;
	
	}
	
	
	
	exit(0);
}
