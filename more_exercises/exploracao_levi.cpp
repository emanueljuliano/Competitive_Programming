#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

int main(){ _
	int n, p, q; cin >> n >> p >> q;
	double a = atan(p/(double(q)));
	
	vector<pair<int, int>> v(n);
	for(int i=0;i <n; i++) cin >> v[i].f >> v[i].s;
	sort(v.begin(), v.end());
	
	ord_set<pair<double, int>> st;
	ll ans = 0;
	for(int i=n-1; i+1; i--){
		double ny = sin(-a)*v[i].f + cos(-a)*v[i].s;
		if(st.size()) ans += st.size() - st.order_of_key({ny-0.00001, -INF});
		st.insert({ny, i});
	}

	cout << ans << endl;
	
	
	exit(0);
}
