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

vector<pair<ii, int>> vx, vy;
int n, m;

bool val(int k){
	vector<pair<ii, int>> ev;
	for(int i=0;i <n; i++){
		if(vx[i].f.s-vx[i].f.f < 2*k) continue;

		ev.pb({{vx[i].f.f+k, 0}, i});
		ev.pb({{vx[i].f.s-k, 2}, i});
	}
	for(int i=0;i <m; i++){
		if(vy[i].f.s-vy[i].f.f < 2*k) continue;
		ev.pb({{vy[i].s, 1}, i});
	}

	sort(ev.begin(), ev.end());
	ord_set<ii> st;
	for(auto IT : ev){
		auto [x, t] = IT.f;
		int id = IT.s;
		if(t==0){
			st.insert({vx[id].s, id});
		}
		else if(t==2){
			st.erase({vx[id].s, id});
		}
		else{
			int y1 = vy[id].f.f+k, y2 = vy[id].f.s-k;
			bool has = st.order_of_key({y2+1, -INF}) - st.order_of_key({y1, -INF}) > 0;
			if(has) return true;
		}
	}
	return false;
}

int bb(int l, int r){
	if(l==r) return l;
	int mm = (l+r+1)/2;
	if(val(mm)) l = mm;
	else r = mm-1;
	return bb(l, r);
}

int main(){ _
	int t; cin >> t;

	while(t--){
		cin >> n >> m;

		vx.clear(), vy.clear();
		for(int i=0;i <n; i++){
			int x1, x2, y; cin >> x1 >> x2 >> y;
			if(x1>x2) swap(x1, x2);
			vx.pb({{x1, x2}, y});
		}
		for(int i=0;i <m; i++){
			int y1, y2, x; cin >> y1 >> y2 >> x;
			if(y1>y2) swap(y1, y2);
			vy.pb({{y1, y2}, x});
		}

		cout << bb(0, (int)1e5+10) <<endl;
	}

	exit(0);
}
