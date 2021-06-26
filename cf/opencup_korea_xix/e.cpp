#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n, m; cin >> n >> m;	
	vector<set<int>> g(n);

	map<int, set<int>> mp;

	for (int i=0;i <m; i++) {
		int a, b; cin >> a >> b; a--, b--;
		g[a].insert(b), g[b].insert(a);
	}

	for (int i=0;i <n; i++) mp[g[i].size()].insert(i);
	
	bool show = true;
	
	while (mp[2].size()) {
		int u = *mp[2].begin();
		mp[2].erase(u);
		int a = *g[u].begin();
		int b = *g[u].rbegin();
		mp[g[a].size()].erase(a);
		mp[g[b].size()].erase(b);
		g[a].erase(u), g[b].erase(u);
		g[a].insert(b), g[b].insert(a);
		mp[g[a].size()].insert(a);
		mp[g[b].size()].insert(b);
	}
	
	for (int i=3;i <n; i++) if (mp[i].size()) show = false;

	if(show) cout << "Yes" << endl;
	else cout << "No" << endl;

	exit(0);
}
