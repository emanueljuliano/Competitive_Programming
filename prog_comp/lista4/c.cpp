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

#define f first
#define s second

const int MAX = 1e3+10;
namespace hld {
	vector<pair<int, int> > g[MAX];
	int pos[MAX], sz[MAX];
	int sobe[MAX], pai[MAX];
	int h[MAX], v[MAX], t;

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = sobe[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i.f != p) {
			sobe[i.f] = i.s; pai[i.f] = k;
			h[i.f] = (i == g[k][0] ? h[k] : i.f);
			build_hld(i.f, k, f); sz[k] += sz[i.f];

			if (sz[i.f] > sz[g[k][0].f] or g[k][0].f == p) swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
	}
	int lca(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);
		return h[a] == h[b] ? b : lca(pai[h[a]], b);
	}
}


int main(){ _
	int t; cin >> t;
	int cs = 1;
	while(t--){ cout << "Case " << cs++ << ":" << endl;
		int n; cin >> n;
		for(int i=0;i <n; i++) hld::g[i].clear();

		for(int i=0; i<n; i++){
			int c; cin >> c;
			for(int j=0;j <c; j++){
				int a; cin >> a; a--; hld::g[a].pb({i, 0}), hld::g[i].pb({a, 0});
			}
		}
		hld::build();
		int q; cin >> q;
		while(q--){
			int a, b; cin >> a >> b; a--, b--;
			cout << hld::lca(a, b)+1 << endl;
		}
	}
		
	exit(0);
}
