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
	vector<ii> v;
	vector<ii> ev(n+10);
	vector<int> ans(n+10, -1);
	for(int i=0;i <n; i++){
		int a, b; cin >> a >> b;
		v.pb({a, b});
		if(a==b) ans[a]=i;
		else{
			ev[a].pb({1, i});
			ev[b+1].pb({0, i});
		}
	}
	set<int> st;
	for(int i=1; i<=n; i++){
		sort(ev[i].begin(), ev[i].end());
		for(int j=0;j <ev[i].size(); j++){
			ii aux = ev[i][j];
			if(aux.f) st.insert(aux.s);	
			else st.erase(aux.s);
		}
		if(ans[i] != -1) continue;
		if(st.size()==1){
			int ind = *st.begin();
			st.erase(ind);
			ans[i]=ind;
		}
	}
	
	bool flag = true;
	for(int i=1; i<=n; i++){
		if(ans[i]==-1) flag = false;
	}
	if(flag){
		cout << "YES" << endl;
		for(int i=1; i<=n; i++) cout << ans[i] << " ";
		cout << endl;
	}
	else{
		
	}
	
	exit(0);
}
