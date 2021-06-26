#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

int main(){ _
	#warning FILE IN 
    freopen("business.in", "r", stdin);	
	
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		
		vector<pair<int, int>> cos;
		vector<tuple<int, int, int>> shop, ev;
		
		for (int i=0; i<n; i++) {
			int x, q, r; cin >> x >> q >> r;
			shop.push_back({x, q, r});
			ev.push_back({x, -1, i});
			ev.push_back({x+r, 1, i});
		}
		for (int i=0; i<m; i++) {
			int y, d; cin >> y >> d;
			cos.push_back({y, d});
			ev.push_back({y, 0, i});
		}

		sort(ev.begin(), ev.end());
		ord_set<pair<int, int>> st;
		vector<int> ans(m);
		for (auto [x, flag, i] : ev) {
			if (flag == -1) {
				st.insert({get<1>(shop[i])-x, i});
			}
			if (flag == 1) {
				st.erase({get<1>(shop[i])-get<0>(shop[i]), i});
			}
			if (flag == 0) {
				int d = get<1>(cos[i]);
				ans[i] += st.size() - st.order_of_key({d-x, -INF});
			}
		}
	
		for (auto u : ans) cout << u << " ";
		cout << endl;
	}
	
	
	exit(0);
}
