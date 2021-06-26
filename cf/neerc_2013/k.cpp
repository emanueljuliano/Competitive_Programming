#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;
	vector<int> v(n);
	for (auto &i : v) cin >> i;

	auto val = [&](int x, bool print=false) {
		int it = 0;
		vector<pair<int, int>> rec;
		int at = 0;

		while (it < n) {
			at++;
			if (at > x) break;

			int l1 = n-1-it;
			for (int i=it; i<n; i++) {
				if (v[i]<=i-it) {l1 = i-1-it; break;}
			}
			int l2 = 0, r = n-1;
			for (int i=it; i<=r; i++) {
				l2 = i-it;
				r = min(r, i+v[i]-1);
			}
			if (l1 > l2)
				rec.push_back({it, it+l1});
			else 
				rec.push_back({it+l2, it});
			it += max(l1, l2) + 1;
		}
		
		if (print) {
			for (auto [l, r] : rec) cout << l+1 << " " << r+1 << endl;
		}
		return (it >= n);
	};

	int l = 1, r = n;
	while (l < r) {
		int m = (l+r)/2;
		if (val(m)) r = m;
		else l = m+1;
	}
	
	cout << l << endl;
	val(l, 1);
	
	
	exit(0);
}
