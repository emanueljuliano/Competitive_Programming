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


int main(){ _
	int n, m; cin >> n >> m;
	vector<pair<ii, int>> ev;
	for(int i=0;i <n; i++){
		int a, b; cin >> a >> b;
		ev.pb({{a, b}, i});
	}
	set<ii> st;
	vector<int> ans;
	int lim = 1;
	sort(ev.begin(), ev.end());
	for (auto IT : ev){
		int x = IT.f.f , y = IT.f.s, id = IT.s;
	//	cout << x << " " << y << " " << id << " " << lim<< endl;
	//	for(auto k : st) cout << k.f << " " << k.s << endl;
		if(x>lim){
			if(st.empty()){
				return cout << "NO" << endl, 0;
			}
			auto aux = *st.rbegin();
			lim = aux.f+1;
			ans.pb(aux.s);
			st.clear();
		}
		if(x>lim) return cout << "NO" << endl, 0;
		st.insert({y, id});
	}
	//if(lim != m+1) return cout << "NO" << endl, 0;
	if(lim != m+1){
		if(st.empty()){
			return cout << "NO" << endl, 0;
		}
		auto aux = *st.rbegin();
		lim = aux.f+1;
		ans.pb(aux.s);
		if(lim != m+1) return cout << "NO" << endl, 0;
	}
	
	cout << "YES" << endl;
	cout << ans.size() << endl;
	for(auto k: ans) cout << k+1 << " " ;
	cout << endl;
	
	
	exit(0);
}
