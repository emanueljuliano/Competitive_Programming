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

int main(){ _
	int n; cin >> n;
	vector<ii> w;
	vector<pair<ii, int>> ev;
	for(int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		ev.pb({{a, 0}, i});
		w.pb({a, b});
	}
	int m; cin >> m;
	vector<int> k(m);
	vector<ii> v;
	for(int i=0; i<m; i++){
		int a, b, c; cin >> a >> b >> c;
		v.pb({a, b});
		k[i]=c;
		ev.pb({{a, -1}, i});
		ev.pb({{b, 1}, i});
	}
	sort(ev.begin(), ev.end());
	vector<int> ans(n);
	bool show = true;
	set<ii> st;
	for(auto IT : ev){
		int  f=IT.f.s, id=IT.s;

		if(f==-1){
			int b = v[id].s;
			st.insert({b, id});
		}
		else if(f==1){
			int b = v[id].s;
			if(k[id]) st.erase({b, id});
		}
		else{
			int b = w[id].s;
			auto it = st.lower_bound({b, -1});
			if(it==st.end()) {show=false; break;}
			auto [bb, idd] = *it;
			ans[id]=idd, k[idd]--;
			if(!k[idd]) st.erase({bb, idd});
		}
	}
	
	if(!show) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		for(auto u : ans) cout << u+1 << " ";
		cout << endl;
	}
	
	
	
	exit(0);
}
