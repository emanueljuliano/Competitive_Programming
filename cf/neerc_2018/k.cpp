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


int main(){ _
	int n; cin >> n;
	vector<ii> v(n);
	ll tot = 0;
	for(auto &i: v) cin >> i.f >> i.s, tot+=i.f+i.s;

	set<ii> st;
	vector<int> vis(n);

	for(int i=0; i<n; i++) st.insert({v[i].f+v[i].s, i});
	
	bool show = true;
	vector<int> ans(n);
	while(st.size()){
		ii aux = *st.begin(); st.erase(aux);
		int c = aux.f, id=aux.s;
		if(vis[id]) continue;
		vis[id] = 1;
		ans[id] = c;
		if(id != 0 and !vis[id-1]){
			if(v[id-1].f > c+1) show = false;
			st.insert({min(c+1, v[id-1].f+v[id-1].s), id-1});
		}
		if(id != n-1 and !vis[id+1]){
			if(v[id+1].f > c+1) show = false;
			st.insert({min(c+1, v[id+1].f+v[id+1].s), id+1});	
		}
	}
	if(!show) return cout << -1 << endl, 0;

	ll val = 0;
	for(int i=0;i <n; i++) val += ans[i]-v[i].f;
	cout << val << endl;
	for(auto u : ans) cout << u << " ";
	cout << endl;
		
	
	
	exit(0);
}
