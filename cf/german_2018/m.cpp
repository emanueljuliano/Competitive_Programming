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

const int MAX = 505*505;

int M[505][505], id[MAX];
int vx[4] = {1, -1, 0, 0};
int vy[4] = {0, 0, 1, -1};
int n, m;

int f(int x, int y) {return x*m + y;}

bool val(int x, int y){
	return x>=0 and y>=0 and x<n and y<m;
}

int find(int p){
	if(id[p]==p) return p;
	return id[p] = find(id[p]);
}

void une(int p, int q){
	p = find(p), q = find(q);
	id[p] = q;
}

void build(){
	for(int i=0; i<MAX; i++) id[i] = i;
}

namespace seg {
	int seg[2 * MAX];
	int n;

	void build(int n2, int *v) {
		n = n2;
		for(int i=0; i<n; i++) seg[i+n] = v[i];
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
	int query(int a, int b) {
		if (a == b) return 0;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(pos[b]+1, pos[a]);
		return max(seg::query(pos[h[a]], pos[a]), query(pai[h[a]], b));
	}
}

int main(){ _
	int q; cin >> n >> m >> q;
	vector<pair<int, ii>> edges;
	for(int i=0;i <n; i++) for(int j=0; j<m; j++) cin >> M[i][j];

	for(int i=0;i <n; i++) for(int j=0; j<m; j++) for(int k=0; k<4; k++) {
		int x = i+vx[k], y = j+vy[k];
		if(val(x, y)) edges.pb({max(M[i][j], M[x][y]), {f(i, j), f(x, y)}});
	}
	sort(edges.begin(), edges.end());

	build();
	for(auto p : edges){
		int d = p.f, a = p.s.f, b = p.s.s;
		if(find(a)!=find(b)) hld::g[a].pb({b, d}), hld::g[b].pb({a, d}), une(a, b);
	}

	hld::build();
	
	while(q--){
		int a, b, c, d; cin >> a >> b >> c >> d; a--, b--, c--, d--;
		int v = f(a, b), u = f(c, d);
		if(v==u) cout << M[a][b] << endl;
		else cout << hld::query(v, u) << endl;
	}

	exit(0);
}
