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

const int MAX = 1e5+10;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		if (!lazy[p]) return;
		int m = (l+r)/2;
		seg[2*p] += lazy[p]*(m-l+1);
		seg[2*p+1] += lazy[p]*(r-(m+1)+1);
		lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		prop(p, l, r);
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return seg[p];
		if (a <= l and r <= b) {
			seg[p] += (ll)x*(r-l+1);
			lazy[p] += x;
			return seg[p];
		}
		prop(p, l, r);
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}
};

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
	ll query_path(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(pos[b], pos[a]);
		return seg::query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
	}
	void update_path(int a, int b, int x) {
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return (void)seg::update(pos[b], pos[a], x);
		seg::update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
	}
	ll query_subtree(int a) {
		return seg::query(pos[a], pos[a]+sz[a]-1);
	}
	void update_subtree(int a, int x) {
		seg::update(pos[a], pos[a]+sz[a]-1, x);
	}
	int lca(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);
		return h[a] == h[b] ? b : lca(pai[h[a]], b);
	}
}

const int MOD = 1e9+7;
const ll inv2 = (MOD+1)/2;
int main(){ _
	int n; cin >> n;
	vector<ii> e1, e2;
	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b; a--, b--;
		hld::g[a].pb(b), hld::g[b].pb(a);
		e1.pb({a, b});
	}

	hld::build();
	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b; a--, b--;
		int c = hld::lca(a, b);
		e2.pb({a, b});

		hld::update_path(a, a, 1);
		hld::update_path(b, b, 1);
		hld::update_path(c, c, -2);
	}

	ll ansa = 0;
	ll minia = INF;
	for(int i=1;i <n; i++){
		ll q = hld::query_subtree(i);
		minia = min(q, minia);
	}
	for(int i=1;i <n; i++){
		ll q = hld::query_subtree(i);
		if(q==minia) ansa++;
	}
	
	for(int i=0;i <n; i++) hld::g[i].clear();
	
	for(int i=0;i <n-1; i++){
		int a = e2[i].f, b = e2[i].s;
		hld::g[a].pb(b), hld::g[b].pb(a);
	}

	hld::build();
	for(int i=0;i <n-1; i++){
		int a = e1[i].f, b = e1[i].s;
		int c = hld::lca(a, b);
		e2.pb({a, b});

		hld::update_path(a, a, 1);
		hld::update_path(b, b, 1);
		hld::update_path(c, c, -2);
	}

	ll ansb = 0;
	ll minib = INF;
	for(int i=1;i <n; i++){
		ll q = hld::query_subtree(i);
		minib = min(q, minib);
	}
	for(int i=1;i <n; i++){
		ll q = hld::query_subtree(i);
		if(q==minib) ansb++;
	}

	if(minia<minib or minia==1) cout << minia+1 << " " << ansa << endl;
	else if (minib<minia) cout << minib+1 << " " << ansb << endl;
	else cout << minia+1 << " " << ansa+ansb << endl;
	
	exit(0);
}
