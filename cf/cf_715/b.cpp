#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e5+10;
ll f[MAX], pref[MAX];
vector<int> ans;

void solve(int n, ll k, int val, int at) {
//	cout << n << " " << k << " " << val << " " << at << endl;
	if (at > n) return;
	else if (k > f[n-val+1]) ans = {-1};
	else if (k <= f[n-val] or k == 1) {
		int cur = val;
		while (cur >= at) ans.push_back(cur), cur--;
		at = val;
		solve(n, k, val+1, at+1);
	}
	else solve(n, k-f[n-val], val+1, at);
}

int main(){ _
	pref[0] = 0;
	for (int i=1; i<MAX; i++) {
		f[i] = min(ll(2e18), pref[i-1] + 1);
		pref[i] = min(ll(2e18+10), pref[i-1] + f[i]);
	}

	int t; cin >> t;
	while (t--) {
		int n; ll k; cin >> n >> k;
		//cout << f[n] << endl;
		ans.clear();
		solve(n, k, 1, 1);
		for (auto u : ans) cout << u << " ";
		cout << endl;
	}
	
	exit(0);
}
