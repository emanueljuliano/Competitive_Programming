#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n, m; cin >> n >> m;
	set<pair<int, int>> st;
	long double p = 1;
	for (int i=0;i <m; i++) st.insert({0, i});
	
	long double ans = 0;
	for (int i=0; i<n; i++) {
		int t; double pi; cin >> t >> pi;
		auto cur = *st.begin();
		st.erase(cur);
		st.insert({cur.first+t, cur.second});
		auto cur2 = *st.rbegin();
		ans += p*(1.0-pi)*cur2.first;
		p *= pi;
	}
	auto cur2 = *st.rbegin();
	ans += p*cur2.first;

	cout << setprecision(8) << fixed;
	cout << ans << endl;
	
	
	exit(0);
}
