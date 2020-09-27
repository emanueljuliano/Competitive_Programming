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
	int t; cin >> t;
	int cs = 0;
	while(t--){ cs++; cout << "Case " << cs << ":" << endl;
		int n; cin >> n;
		vector<pair<ii, ii>> ev;
		ord_set<ii> st;
		for(int i=0;i <n; i++){
			int p; cin >> p;
			if(p==1){
				int l, v, r; cin >> l >> v >> r;
				ev.pb({{l, 0}, {v, i}});
				ev.pb({{r, 2}, {v, i}});
			}
			else{
				int l, k; cin >> l >> k;
				ev.pb({{l, 1}, {k, i}});
			}
		}
		sort(ev.begin(), ev.end());
		for(auto IT : ev){
			int flag = IT.f.s;
			int x = IT.f.f;
			ii k = IT.s;
		//	cout << "flag = " << flag << " x= " << x << " k= " << k << endl;
			if(flag==0) st.insert(k);
			else if(flag==2) st.erase(k);
			else{
				if(st.size()<k.f) cout << -1 <<endl;
				else cout << (*st.find_by_order(k.f-1)).f << endl;
			}
		}
	}



	exit(0);
}
