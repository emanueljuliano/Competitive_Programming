#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

typedef tuple<int, int, int> T;

const int MAX = 5e5+10;

vector<int> g[MAX];
T dp[MAX];
int vis[MAX];
vector<int> ans;

T dfs(int i, int p);

T calc(int i, int p) {
	int l = i, r = i, val = 1;
	int mn = 0, mx = 0;

	for (auto u : g[i]) if (u != p) {
		auto [l2, r2, v2] = dfs(u, i);
		l = min(l, l2);
		r = max(r, r2);
		val &= v2;

		if (l2 < i and i < r2) val = false;
		else if (i < l2) mn++;
		else if (r2 < i) mx++;
	}
	if (mn > 1 or mx > 1) val = false;

	return {l, r, val};
}

T dfs(int i, int p) {
	if (vis[i]) return dp[i];
	vis[i] = 1;
	return dp[i] = calc(i, p);
}

void reroot(int i, int p) {
	auto [l, r, val] = calc(i, i);
	if (val) ans.push_back(i);

	T prev = dp[i];
	for (auto u : g[i]) if (u != p) {
		dp[i] = calc(i, u);
		reroot(u, i);
	}
	dp[i] = prev;
}

int main(){ _
	int n; cin >> n;

	for (int i=0; i<n-1; i++) {
		int a, b; cin >> a >> b; a--, b--;
		g[a].push_back(b), g[b].push_back(a);
	}

	if (n==1) return cout << 1 << endl, 0;
	for (int i=0; i<n; i++) if (g[i].size() > 3) 
		return cout << -1 << endl, 0;

	dfs(0, 0);
	reroot(0, 0);

	if (ans.empty()) cout << -1 << endl;
	for (auto u : ans) cout << u+1 << " ";
	cout << endl;
	
	
	exit(0);
}
