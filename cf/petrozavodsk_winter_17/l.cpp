#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 4e5+10;

int N;
map<pair<int, int>, int> ans;

namespace DTree {
	int n;
	vector<int> g[MAX];

	// The dominator tree
	vector<int> tree[MAX];
	int dfs_l[MAX], dfs_r[MAX];

	// Auxiliary data
	vector<int> rg[MAX], bucket[MAX];
	int idom[MAX], sdom[MAX], prv[MAX], pre[MAX];
	int ancestor[MAX], label[MAX];
	vector<int> preorder;

	void dfs(int v) {
		static int t = 0;
		pre[v] = ++t;
		sdom[v] = label[v] = v;
		preorder.push_back(v);
		for (int nxt: g[v]) {
			if (sdom[nxt] == -1) {
				prv[nxt] = v;
				dfs(nxt);
			}
			rg[nxt].push_back(v);
		}
	}
	int eval(int v) {
		if (ancestor[v] == -1) return v;
		if (ancestor[ancestor[v]] == -1) return label[v];
		int u = eval(ancestor[v]);
		if (pre[sdom[u]] < pre[sdom[label[v]]]) label[v] = u;
		ancestor[v] = ancestor[u];
		return label[v];
	}

	int subsize[MAX];
	void dfs2(int v) {
		static int t = 0;
		dfs_l[v] = t++;
		for (int nxt: tree[v]) dfs2(nxt), subsize[v] += subsize[nxt];

		if(v < N) subsize[v] += 1;
		else if (tree[v].size()) {
			//cout << v << " " << subsize[v] << endl;
			//cout << prv[v]+1 << " " << tree[v][0]+1 << endl << endl;
			ans[{min(prv[v], tree[v][0]), max(prv[v], tree[v][0])}] = subsize[v];
		}
		dfs_r[v] = t++;
	}
	void build(int s) {
		for (int i = 0; i < n; i++) {
			sdom[i] = pre[i] = ancestor[i] = -1;
			rg[i].clear();
			tree[i].clear();
			bucket[i].clear();
		}
		preorder.clear();
		dfs(s);
		if (preorder.size() == 1) return;
		for (int i = int(preorder.size()) - 1; i >= 1; i--) {
			int w = preorder[i];
			for (int v: rg[w]) {
				int u = eval(v);
				if (pre[sdom[u]] < pre[sdom[w]]) sdom[w] = sdom[u];
			}
			bucket[sdom[w]].push_back(w);
			ancestor[w] = prv[w];
			for (int v: bucket[prv[w]]) {
				int u = eval(v);
				idom[v] = (u == v) ? sdom[v] : u;
			}
			bucket[prv[w]].clear();
		}
		for (int i = 1; i < preorder.size(); i++) {
			int w = preorder[i];
			if (idom[w] != sdom[w]) idom[w] = idom[idom[w]];
			tree[idom[w]].push_back(w);
		}
		idom[s] = sdom[s] = -1;
		dfs2(s);
	}

	// Whether every path from s to v passes through u
	bool dominates(int u, int v) {
		if (pre[v] == -1) return 1; // vacuously true
		return dfs_l[u] <= dfs_l[v] && dfs_r[v] <= dfs_r[u];
	}
};

ll d[MAX];
vector<pair<int, int>> g[MAX];
vector<pair<int, int>> dag;
int vis2[MAX];
int n;

void dijkstra(int x) {
	for (int i=0; i<n; i++) d[i] = LINF;
	d[x] = 0;
	priority_queue<tuple<ll, int, int>> pq;
	pq.push({0, x, x});

	while (pq.size()) {
		auto [ndist, u, p] = pq.top(); pq.pop();

		if (-ndist > d[u]) continue;
		dag.emplace_back(p, u);
		if(vis2[u]) continue;
		vis2[u] = 1;

		for (auto [idx, w] : g[u]) if (d[idx] >= d[u] + w) {
			d[idx] = d[u] + w;
			pq.push({-d[idx], idx, u});
		}
	}
}

int main(){ _
	int m; cin >> n >> m;
	vector<pair<int, int>> eg;
	for (int i=0; i<m; i++) {
		int a, b, c; cin>>  a >> b >> c; a--, b--;
		g[a].push_back({b, c}), g[b].push_back({a, c});
		eg.push_back({min(a, b), max(a, b)});
	}
	dijkstra(0);
	
	int pt = 0;
	for (auto [a, b] : dag) {
		//cout << a+1 << " " << b+1 << endl;
		DTree::g[a].push_back(n+pt);
		DTree::g[n+pt].push_back(b);
		pt++;
	}
	DTree::n = n+pt;
	N = n;
	DTree::build(0);
	
	for (auto [a, b] : eg) {
		cout << ans[{min(a, b), max(a, b)}] << endl;
	}

	
	exit(0);
}
