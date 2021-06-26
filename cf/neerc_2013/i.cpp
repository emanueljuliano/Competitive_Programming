#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n, a, b; cin >> n >> a >> b;
	
	vector<pair<int, int>> A, B, C;
	for (int i=0; i<n; i++) {
		int f, w; cin >> f >> w;
		if (f == 1) A.push_back({w, i});
		if (f == 2) B.push_back({w, i});
		if (f == 3) C.push_back({w, i});
	}
	
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end(), greater<>());

	while (A.size() > a) A.pop_back();
	while (B.size() > b) B.pop_back();
	set<tuple<int, int, int>> st;
	for (auto [w, i] : A) st.insert({w, 1, i});
	for (auto [w, i] : B) st.insert({w, 2, i});
	for (auto [w, i] : C) st.insert({w, 3, i});
	
	while (st.size() > a+b) {
		st.erase(*st.rbegin());
	}

	vector<int> res_a, res_b, res_c;
	ll ans = 0;
	for (auto [w, f, i] : st) {
		ans += w;
		if (f == 1) res_a.push_back(i);
		if (f == 2) res_b.push_back(i);
		if (f == 3) res_c.push_back(i);
	}

	cout << st.size() << " " << ans << endl;
	int it = 1, it_c=0;
	for (auto u : res_a) cout << u+1 << " " << it++ << endl;
	for (auto u : res_c) {
		if (it > a) break;
		it_c++;
		cout << u+1 << " " << it++ << endl;
	}
	it = a+1;
	for (auto u : res_b) cout << u+1 << " " << it++ << endl;
	for (int i=it_c; i<res_c.size(); i++) cout << res_c[i]+1 << " " << it++ << endl;
	
	exit(0);
}
