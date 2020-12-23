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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;


int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<ii> v(n); for(auto &i:v) cin >> i.f >> i.s;
		sort(v.begin(), v.end());

		vector<int> ans(n);
		vector<int> res(n+1);
		int at = 0;
		for(int i=0;i <n; i++){
			ii p = {v[i].s, INF};
			int lo = lower_bound(v.begin(), v.end(), p) - v.begin();
			at += res[i];
			ans[i] = lo-i + at;
			res[lo]--;
			at++;
		}
		int maxi = 0;
		for(int i=0;i <n; i++) maxi = max(maxi, ans[i]);
		cout << n-maxi << endl;
	}
	
	
	
	exit(0);
}
