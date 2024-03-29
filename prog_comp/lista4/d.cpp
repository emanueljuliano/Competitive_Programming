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

const int MAX = 2e5+10;

namespace seg{
	vector<vector<int>> v(MAX);
	void build(int n2, int*v2){
		for(int i=0; i<n2; i++)
			v[v2[i]].pb(i);
	}
	int query(int a, int b, int c){
		return upper_bound(v[c].begin(), v[c].end(), b) 
			- lower_bound(v[c].begin(), v[c].end(), a);
	}
}

namespace hld {
	vector<int> g[MAX];
	int pos[MAX], sz[MAX];
	int peso[MAX], pai[MAX];
	int h[MAX], v[MAX], t;

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = peso[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i != p) {
			pai[i] = k;
			h[i] = (i == g[k][0] ? h[k] : i);
			build_hld(i, k, f); sz[k] += sz[i];

			if (sz[i] > sz[g[k][0]] or g[k][0] == p) swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		seg::build(t, v);
	}
	int query_path(int a, int b, int c) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(pos[b], pos[a], c);
		return seg::query(pos[h[a]], pos[a], c) + query_path(pai[h[a]], b, c);
	}
}


int main(){ _
	int n, m;
	while(cin >> n >> m){
		for(int i=0; i<=n; i++) seg::v[i].clear(), hld::g[i].clear();
		for(int i=0;i <n; i++) cin >> hld::peso[i];
		for(int i=0; i<n-1; i++){
			int a, b; cin >> a >> b; a--; b--;
			hld::g[a].pb(b), hld::g[b].pb(a);
		}
		hld::build();
		while(m--){
			int a, b, c; cin >> a >> b >> c; a--, b--;
			if(hld::query_path(a, b, c)) cout << "Find" << endl;
			else cout << "NotFind" << endl;
		}
	}	
	
	exit(0);
}
