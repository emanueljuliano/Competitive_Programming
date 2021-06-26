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
	int n, m; cin >> n >> m;
	vector<ii> v(n, {-1, -1});
	vector<int> dg(n);
	for(int i=0;i <m; i++){
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		v[a] = {b, c};
		dg[b]++;
	}

	vector<vector<int>> ans;
	for(int i=0;i <n; i++){
		if(dg[i]==0 and  v[i].f!=-1){
			vector<int> w;
			w.pb(i);
			int x = i;
			int mini = v[x].s;
			while(v[x].f!=-1) mini=min(mini, v[x].s), x = v[x].f;
			w.pb(x);
			w.pb(mini);
			ans.pb(w);
		}
	}

	cout << ans.size() << endl;
	for(auto u : ans) cout << u[0]+1 << " " << u[1]+1 << " " << u[2] << endl;

	

	
	
	exit(0);
}
