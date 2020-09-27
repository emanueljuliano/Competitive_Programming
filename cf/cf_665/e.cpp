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
	int n, m; cin >> n >> m;

	int cobre = 1;
	vector<pair<ii, ii>> ev;
	for(int i=0;i <n; i++){
		int y, lx, rx; cin >> y >> lx >> rx;
		ev.pb({{lx, 0}, {y, i}});
		ev.pb({{rx, 5}, {y, i}});
		if(lx==0 and rx==(int)1e6) cobre++;
	}

	for(int i=0;i <m; i++){
		int x, ly, ry; cin >> x >> ly >> ry;
		if(ly==0){
			ev.pb({{x, 2}, {ry, i}});
			if(ry==(int)1e6) cobre++;
		}
		else{
			ev.pb({{x, 3}, {ly, i}});
		}
	}

	sort(ev.begin(), ev.end());

	ord_set<int> st;
	ll inter = 0;
	for(auto IT: ev){
		int x = IT.f.f, flag = IT.f.s, y = IT.s.f;

		if(x==(int)1e6) break;
		if(flag==0) st.insert(y);
		else if(flag==5) st.erase(y);
		else if(flag==2){
			inter += st.order_of_key(y+1);
		}
		else if(flag==3){
			inter += st.size() - st.order_of_key(y);
		}
	}
	
	cout << inter+cobre <<endl;

	exit(0);
}
