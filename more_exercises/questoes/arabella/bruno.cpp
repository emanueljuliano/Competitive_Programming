#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
int n, m;

vector<int> adj[N], vis[N];

int calc(int p, int q)
{
	return lower_bound(adj[p].begin(), adj[p].end(), q+1)-adj[p].begin();
}

int dfs(int p, int a)
{
	if (a == vis[p].size()) return 0;
	int& res = vis[p][a];
	if (res) return res;
	return res = max(dfs(adj[p][a], calc(adj[p][a], p))+1, dfs(p, a+1));
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		vis[a].push_back(0);
		adj[b].push_back(a);
		vis[b].push_back(0);
	}
	for (int i = 1; i <= n; ++i)
		sort(adj[i].begin(), adj[i].end());
	for (int i = 1; i <= n; ++i) 
		cout << (i==1?"":" ") << 1+dfs(i, 0);
	cout << endl;
}

