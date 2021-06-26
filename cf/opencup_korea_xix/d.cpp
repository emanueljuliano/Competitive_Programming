#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 3e5+10;
vector<pair<int, int>> v;
vector<vector<int>> g(MAX);
int vis[MAX];

bool is_cyc(int n) {
	bool ret = false;
	function<void(int)> dfs = [&](int i) {
		vis[i] = 1;
		for (auto u : g[i]) {
			if(vis[u] == 1) ret = true;
			else if(!vis[u]) dfs(u);
		}
		vis[i] = 2;
	};
	for (int i=0; i<n; i++) if(!vis[i]) dfs(i);
	return ret;
}

void solve(int i) {
	vector<pair<int, int>> stk;
	vis[i] = 1;

	for (auto u : g[i]) {
		if (!vis[u]) solve(u);
		stk.push_back({v[u].second, 1});
	}
	sort(stk.begin(), stk.end());

	while (stk.size() > 1) {
		auto [x1, c1] = stk.back(); stk.pop_back();
		auto [x2, c2] = stk.back();
		if (x1==x2) {
			stk.pop_back();
			stk.push_back({x1, c1+c2});
		}
		else {
			if(c1>1) stk.push_back({x1-1, c1-1});
		}
	}
	if (stk.size()) {
		auto [x, c] = stk.back();
		v[i].second = min(v[i].second, x-c);
	}
}

int main(){ _
	int n, m; cin >> n >> m;

	for (int i=0; i<n; i++) {
		int l, r; cin >> l >> r; l--, r--;
		v.push_back({l, r});
	}
	
	vector<int> dg(n);
	set<pair<int, int>> st2;
	for (int i=0; i<m; i++) {
		int a, b; cin >> a >> b; a--, b--;
		if(st2.count({a, b})) continue;
		else st2.insert({a, b});
		dg[b]++;
		g[a].push_back(b);
	}

	if (is_cyc(n)) {
		cout << -1 << endl;
		exit(0);
	}

	memset (vis, 0, sizeof vis);
	for (int i=0; i<n; i++) if(!vis[i]) solve(i);

	vector<vector<pair<int, int>>> ev(n+10);
	for (int i=0; i<n; i++) {
		auto [l, r] = v[i];
		//cout << l << " " << r << endl;
		if (r<l) {
			cout << -1 << endl;
			exit(0);
		}
		ev[l].push_back({0, i});
		ev[r+1].push_back({1, i});
	}

	set<pair<int, int>> st;
	set<int> to_add;
	bool show = true;
	vector<int> ans;
	for (int it=0; it<n+1; it++) {
		for (auto [flag, id] : ev[it]) {
			if (flag == 0) {
				if (dg[id]==0) st.insert({v[id].second, id});
				else to_add.insert(id);
			}
			else {
				if (to_add.count(id) or st.count({v[id].second, id})) {
					show = false;
				}
			}
		}

		/*cout << endl << it << endl;
		cout << "To add" << endl;
		for (auto u : to_add) cout << u << " ";
		cout << endl;
		cout << "Set" << endl;
		for (auto [a, b] : st) cout << a << " " << b << "; ";
		cout << endl;
		*/

		if (st.size()) {
			auto [r, id] = *st.begin();
			st.erase({r, id});
			for (auto u : g[id]) {
				dg[u]--;
				if (!dg[u] and to_add.count(u)) {
					to_add.erase(u);
					st.insert({v[u].second, u});
				}
			}
			//cout << "id " << id << endl;
			ans.push_back(id);
		}
		else if(it<n) show = false;
	}

	if(!show) cout << -1 << endl;
	//else if(true) cout << 1 << endl;
	else {
		for (auto u : ans) cout << u+1 << endl;
	}
	
	exit(0);
}
