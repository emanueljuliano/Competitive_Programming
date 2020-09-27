#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;

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
	ll query_path(int a, int b) {
		if (a == b) return 0;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(pos[b]+1, pos[a]);
		return seg::query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
	}
	void update_path(int a, int b, int x) {
		if (a == b) return;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return (void)seg::update(pos[b]+1, pos[a], x);
		seg::update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
	}
}

ll red(ii a){
	return a.f*a.s - a.f*(a.s/2);
}
bool ord(ii a, ii b){
	ll ra = red(a);
	ll rb = red(b);
	return ra < rb;
}
struct ord2
{
	bool operator()(const ii& a, const ii& b)
	{
		ll ra = red(a);
		ll rb = red(b);
		return ra < rb;
	}
};

ll f(ii a){return (ll)a.f*a.s;}
int main(){ _
	int t; cin >> t;
	while(t--){
		ll n, S; cin >> n >> S;
		vector<pair<ii, int>> e1, e2;
		vector<int> dg(n);
		for(int i=0; i<n-1; i++){
			int a, b, c, d; cin >> a >> b >> c >> d; a--, b--; d--;
			hld::g[a].pb({b, 0});
			hld::g[b].pb({a, 0});
			dg[a]++, dg[b]++;
			if(d) e2.pb({{a, b}, c});
			else e1.pb({{a, b}, c});
		}
		hld::build();
		for(int i=1;i <n; i++){
			if(dg[i]==1) hld::update_path(i, 0, 1);
		}
		priority_queue<ii,vector<ii>,ord2> pq1, pq2;
		ll soma = 0;
		for(auto p : e1){
			int a = p.f.f, b = p.f.s, c = p.s;
			ll x = hld::query_path(a, b);
			pq1.push({x, c});
			soma += x*c;
		}	for(auto p : e2){
			int a = p.f.f, b = p.f.s, c = p.s;
			ll x = hld::query_path(a, b);
			pq2.push({x, c});
			soma += x*c;
		}

		int ans = 0;
		ll soma1 = soma, val1=0;
		vector<ll> v1;
		v1.pb(0);
		while(soma1 > S and pq1.size()){
			ii at = pq1.top();
			pq1.pop();
			soma1 -= red(at);
			val1+=red(at);
			if(at.s/2) pq1.push({at.f, at.s/2});
			ans++;
			v1.pb(val1);
		}
		if(soma1 >S) ans = INF;
		int at2=0;
		while(soma > S and pq2.size()){
			ii at = pq2.top();
			pq2.pop();
			soma -= red(at);
			if(at.s/2) pq2.push({at.f, at.s/2});
			at2+=2;
			if(soma-v1.back()<=S){
				int lo = lower_bound(v1.begin(), v1.end(), soma-S) - v1.begin();
				ans = min(ans, at2+lo);
			}
		}

		cout << ans << endl;
		for(int i=0;i <n; i++) hld::g[i].clear();
	}

	exit(0);
}
