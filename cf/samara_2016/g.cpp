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
	int n; cin >> n;
	vector<pair<ii, int>> v, w;
	for(int i=0;i <n; i++){
		int a, b; cin >> a >> b;
		v.pb({{a, b}, i});
	}	
	sort(v.begin(), v.end(), greater<>());
	int m; cin >> m;
	for(int i =0;i <m; i++){
		int a, b; cin >>a  >> b;
		w.pb({{a, b}, i});	
	}
	sort(w.begin(), w.end(), greater<>());
		
	set<ii> st;
	int it = 0;
	vector<int> ans(n);
	for(int i=0;i <n; i++){
		while(it<m and w[it].f.f >= v[i].f.f){
			st.insert({w[it].f.s, w[it].s});
			it++;
		}
		auto lo = st.lower_bound({v[i].f.s, -1});
		if(lo==st.end()){
			cout << -1 << endl; exit(0);
		}
		ii axe = *lo;
		ans[v[i].s] = axe.s;
		st.erase(lo);
	}

	for(auto x : ans) cout << x+1 << " ";
	cout << endl;	
	
	exit(0);
}
