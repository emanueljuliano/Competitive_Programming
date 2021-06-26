#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n, q; cin >> n >> q;
	vector<int> v(n);
	for (auto &i : v) cin >> i;
	while(q--) {
		int l, r; cin >> l >> r; l--, r--;
		vector<int> w;
		for (int i=l; i<=r; i++) w.push_back(v[i]);
		sort(w.begin(), w.end());
		vector<int> pref;
		pref.push_back(w[0]);
		for (int i=1; i<w.size(); i++) pref.push_back(pref.back() | w[i]);
		vector<int> suf;
		suf.push_back(w.back());
		for (int i=int(w.size())-2; i>=0; i--) suf.push_back(suf.back() & w[i]);
		reverse(suf.begin(), suf.end());

		bool ans = false;
		for (int i=1; i<r-l+1; i++) if (pref[i-1] == suf[i]) ans = true;
		if (ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	exit(0);
}
