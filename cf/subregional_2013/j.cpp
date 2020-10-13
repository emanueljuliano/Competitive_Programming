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

const int MAX = 2e4+10;

namespace hld {
	vector<pair<int, int> > g[MAX];
	int pos[MAX], sz[MAX];
	int sobe[MAX], pai[MAX];
	int h[MAX], v[MAX], t;
	int men[MAX], seg[2*MAX];

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = sobe[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i.f != p) {
			sobe[i.f] = i.s; pai[i.f] = k;
			h[i.f] = (i == g[k][0] ? h[k] : i.f);
			men[i.f] = (i == g[k][0] ? min(men[k], i.s) : i.s);
			build_hld(i.f, k, f); sz[k] += sz[i.f];

			if (sz[i.f] > sz[g[k][0].f] or g[k][0].f == p) swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		for (int i = 0; i < t; i++) seg[i+t] = v[i];
		for (int i = t-1; i; i--) seg[i] = min(seg[2*i], seg[2*i+1]);
	}
	int query_path(int a, int b) {
		if (a == b) return INF;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] != h[b]) return min(men[a], query_path(pai[h[a]], b));
		int ans = INF, x = pos[b]+1+t, y = pos[a]+t;
		for (; x <= y; ++x/=2, --y/=2) ans = min({ans, seg[x], seg[y]});
		return ans;
	}
};

int id[MAX];
void build(){
	for(int i=0;i <MAX; i++) id[i]=i;
}

int find(int p){
	if(p==id[p]) return p;
	return id[p] = find(id[p]);
}

void une(int p, int q, int c){
	int pp = find(p), qq=find(q);
	if(pp==qq) return;

	id[pp] = qq;
	hld::g[p].pb({q, c});
	hld::g[q].pb({p, c});
}

int main(){ _
	int n, m, q; cin >> n >> m >> q;	
	
	vector<pair<int, ii>> e;
	for(int i=0;i <m; i++){
		int a, b, c; cin >> a >> b >> c; a--, b--;
		e.pb({c, {a, b}});
	}

	sort(e.begin(), e.end(), greater<>());
	
	build();
	for(auto p : e){
		int c = p.f, a=p.s.f, b=p.s.s;
		une(a, b, c);
	}
	
	hld::build();
	while(q--){
		int a, b; cin >> a >> b; a--, b--;
		cout << hld::query_path(a, b) << endl;
	}


	exit(0);
}
