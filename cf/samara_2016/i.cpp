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
	vector<vector<int>> g(n);
	vector<int> ans(n, 1), dg(n, 0);
	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b; a--; b--;
		dg[a]++;
		dg[b]++;
		g[a].pb(b);
		g[b].pb(a);
	}	
	int mini = INF;
	int id = -1;
	for(int i=0;i <n; i++) if(dg[i]<mini) mini = dg[i], id=i;
	ans[id] = 0;
	for(auto u : g[id]) ans[u]=0;
	for(auto k : ans) cout << k << " ";
	cout << endl;
	
	
	
	exit(0);
}
