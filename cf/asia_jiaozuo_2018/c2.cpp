#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	int p = 0;
	while (t--) {
		vector<pair<int, int>> v;	
		int n, m; cin >> n >> m;
		
		for (int i=0; i<n; i++) {
			int x, y; cin >> x >> y;
			v.push_back({x, y});
		}
		while (m--) {
			char c; cin >> c;
			int a;
			if (c == '!') {
				map<pair<int, int>, int> cnt;
				for(int i=0;i <n; i++) cnt[v[i]]++;
				ll ans = 0;
				for(auto [e, b] : cnt) ans += (b*ll(b-1)/2);
				cout << ans << endl;
				p++;
			}
			if (c == '?') {
				cin >> a; a--;
				cout << v[a].first << " " << v[a].second << endl;
				p++;
			}
			if (c == 'L') {
				cin >> a;
				for (int i=0; i<n; i++) v[i].second = max(1, v[i].second-a);
			}
			if (c == 'R') {
				cin >> a;
				for (int i=0; i<n; i++) v[i].second = min(n, v[i].second+a);
			}
			if (c == 'U') {
				cin >> a;
				for (int i=0; i<n; i++) v[i].first = max(1, v[i].first-a);
			}
			if (c == 'D') {
				cin >> a;
				for (int i=0; i<n; i++) v[i].first = min(n, v[i].first+a);
			}
			if(p>600) exit(0);
		}
	}
	
	exit(0);
}
