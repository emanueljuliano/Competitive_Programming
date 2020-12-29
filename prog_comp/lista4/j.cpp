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
const int MAX = 1e5+10;
namespace seg {
	int seg[2 * MAX];
	int n;

	void build(int n2, int *v) {
		n = n2; for(int i=0;i <n; i++) seg[n+i] = v[i];
		for (int i = n - 1; i; i--) seg[i] = max(seg[2*i], seg[2*i+1]);
	}
	int query(int a, int b) {
		int ret = 0;
		for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
			if (a % 2 == 1) ret = max(ret, seg[a]);
			if (b % 2 == 0) ret = max(ret, seg[b]);
		}
		return ret;
	}
	void update(int p, int q, int x) {
		seg[p += n] = x;
		while (p /= 2) seg[p] = max(seg[2*p], seg[2*p+1]);
	}
}

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
		seg::build(t, v);
	}
	int query_path(int a, int b) {
		if (a == b) return 0;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(pos[b]+1, pos[a]);
		return max(seg::query(pos[h[a]], pos[a]), query_path(pai[h[a]], b));
	}
	void update_path(int a, int b, int x) {
		if (a == b) return;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return (void)seg::update(pos[b]+1, pos[a], x);
		seg::update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
	}
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		for(int i=0;i <n; i++) hld::g[i].clear();
		vector<ii> e;
		for(int i=0;i <n-1; i++){
			int a, b, c; cin >> a >> b >> c; a--, b--;
			e.pb({a, b});
			hld::g[a].pb({b, c});
			hld::g[b].pb({a, c});
		}
		hld::build();
		while(true){
			string s; cin >> s; if(s=="DONE") break;
			int a, b; cin >> a >> b; a--;
			if(s=="QUERY") cout << hld::query_path(a, b-1) << endl;
			else hld::update_path(e[a].f, e[a].s, b);
		}
		if(t) cout << endl;	
	}
	exit(0);
}
