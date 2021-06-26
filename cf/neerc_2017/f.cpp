#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef tuple<int, int, int, int> T;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while (t--) {
		int a, b, n; cin >> a >> b >> n;
		int sa = a < 0, sb = b < 0;
		a = abs(a), b = abs(b);

		int x = 0, y = 0, pos = 0;
		if (b - y > a-x) pos = 1;
		vector<T> ans;
		while (x < a or y < b or (x == a and y == b)) {
		//	cout << x << " " << y << endl;
			if (abs(a-x) >= n-1 and abs(b-y) >= n-1) {
				ans.emplace_back(x, y, x+n-1, y+n-1);
				if (a-x >= b-y) x = x+n, y = y+n-1, pos = 0;
				else x = x+n-1, y = y+n, pos = 1;
			}
			else if (pos == 0) {
				ans.emplace_back(x, b-n+1, x+n-1, b);
				x = x+n, y = b, pos = 0;
			}
			else if (pos == 1) {
				ans.emplace_back(a, y+n-1, a-n+1, y);
				x = a, y = y+n, pos = 1;
			}
		}
		if (sa) for (auto &[x1, y1, x2, y2] : ans) x1 = -x1, x2 = -x2;
		if (sb) for (auto &[x1, y1, x2, y2] : ans) y1 = -y1, y2 = -y2;
		cout << ans.size() << endl;
		for (auto [x1, y1, x2, y2] : ans) 
			cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
	}
	
	
	
	exit(0);
}
