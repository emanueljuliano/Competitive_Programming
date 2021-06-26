#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		
		vector<int> Y, N;
		for (int i=1; i<=n; i++) {
			cout << 1 << endl;
			cout << i << endl;
			int support; cin >> support;
			if (support) Y.push_back(i);
			else N.push_back(i);
		}
		
		vector<int> love, hate, neutral;
		for (auto u : Y) {
			cout << N.size()+1 << endl;
			for (auto v : N) cout << v << " ";
			cout << u << endl;
			int sz; cin >> sz;
			if (sz == 0) neutral.push_back(u);
			else love.push_back(u);
		}
		for (auto u : N) {
			cout << 2 << endl;
			cout << love[0] << " " << u  << endl;
			int sz; cin >> sz;
			if (sz == 2) neutral.push_back(u);
			else hate.push_back(u);
		}

		cout << -1 << endl;
		vector<int> ans(n);
		for (auto u : love) ans[u-1] = 1;
		for (auto u : hate) ans[u-1] = 2;
		for (auto u : neutral) ans[u-1] = 3;

		for (auto u : ans) cout << u << " ";
		cout << endl;
	}
	
	
	
	exit(0);
}
