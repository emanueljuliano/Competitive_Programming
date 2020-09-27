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
	vector<ll> v(n);
	vector<vector<pair<int, ll>>> g(n);
	for(int i=0;i <m; i++){
		int a, b; ll c; cin >> a >> b >> c; a--, b--;
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	set<pair<ll, int>> st;
	for(int i=0;i <n; i++){
		cin >> v[i];
		st.insert({v[i], i});
	}

	vector<ll> ans(n, -1);
	while(!st.empty()){
		pair<ll, int> p = *st.begin();
		st.erase(p);
		ll c=p.f;
		int x = p.s;
		if(ans[x]!=-1) continue;
		ans[x] = c;
		for(auto u : g[x]){
			st.insert({2LL*u.s+ans[x], u.f});
		}
	}
	for(auto x : ans) cout << x << " ";
	cout << endl;
	
	
	
	exit(0);
}
