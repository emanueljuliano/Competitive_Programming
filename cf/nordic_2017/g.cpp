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
	ord_set<pair<ii, int>> st;
	int n, m; cin >> n >> m;
	vector<ii> v(n+10);
	for(int i=1;i <=n; i++){
		v[i] = {0, 0};
		st.insert({v[i], i});
	}

	for(int i=0;i <m; i++){
		int a, p; cin >> a >> p;
		st.erase({v[a], a});
		v[a].f--;
		v[a].s += p;
		st.insert({v[a], a});
		int ans = st.order_of_key({v[1], 1});
		cout << ans+1 << endl;
	}
	
	
	
	exit(0);
}
