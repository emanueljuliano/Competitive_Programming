#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	#warning FILE IN 
    freopen("mosalah.in", "r", stdin);	
	int t; cin >> t;
	while (t--) {
		int n, m, x, y; cin >> n >> m >> x >> y;
		int ans = (x+y)*n - m;
		if (y == 0 and ans>0) cout << -1 << endl;
		else if (ans < 0) cout << 0 << endl;
		else cout << ans << endl;
	}
	
	exit(0);
}
