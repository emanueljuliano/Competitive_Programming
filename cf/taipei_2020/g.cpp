#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+10;

vector<int> g[MAX];
int vis[MAX];
vector<int> cyc;
stack<int> st;
int ciclo[MAX];

void dfs(int i, int p=-1) {
	vis[i] = 2;
	st.push(i);
	for (int j : g[i]) if (j != p) {
		if (!vis[j]) dfs(j, i);
		else if (vis[j] == 2) {
			assert(cyc.size() == 0);
			while (st.top() != j) {
				cyc.push_back(st.top());
				st.pop();
			}
			cyc.push_back(j);
		}
	}
	vis[i] = 1;
	if (st.size()) st.pop();
}

map<vector<int>, int> mphash;

int fhash(int v, int p=-1) {
	vector<int> h;
	for (int u : g[v]) if (u != p and !ciclo[u]) h.push_back(fhash(u, v));
	sort(h.begin(), h.end());
	auto it = mphash.find(h);
	if (it == mphash.end()) return mphash[h] = mphash.size();
	else return it->second;
}

int max_sulf(vector<int> s) {
	s.push_back(-1);
	int ans = max_element(s.begin(), s.end()) - s.begin();
	for (int i = ans+1, j = 0; i < s.size(); i++) {
		if (ans+j < i and s[i] == s[ans+j]) j++;
		else {
			if (ans+j < i and s[i] > s[ans+j]) ans = i-j;
			j = 0;
		}
	}
	return ans;
}

vector<int> ma2(vector<int> h) {
	int n = h.size();
	for (int i = 0; i < n; i++) h.push_back(h[i]);

	int idx = max_sulf(h);
	assert(idx < n);
	
	vector<int> ret;
	for (int i = idx; i < idx+n; i++) ret.push_back(h[i]);
	return ret;
}

vector<int> ma(vector<int> h) {
	auto ans = ma2(h);
	reverse(h.begin(), h.end());
	return max(ans, ma2(h));
}

int main() { _
	int t; cin >> t;
	while (t--) {
		int k; cin >> k;
		set<vector<int>> se;
		while (k--) {
			int n; cin >> n;
			for (int i = 0; i < n; i++) g[i].clear(), vis[i] = 0, ciclo[i] = 0;
			cyc.clear();

			for (int i = 0; i < n; i++) {
				int a, b; cin >> a >> b; a--, b--;
				g[a].push_back(b), g[b].push_back(a);
			}

			dfs(0);
			for (int i : cyc) ciclo[i] = 1;

			vector<int> H;
			for (int i : cyc) H.push_back(fhash(i));
			
			se.insert(ma(H));
		}
		for(auto u : se) {
			for(auto c : u) cout << c << " ";
			cout << endl;
		}
		cout << se.size() << endl;
		cout << endl;
	}
	exit(0);
}
