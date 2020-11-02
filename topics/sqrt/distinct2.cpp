#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;

const ll LINF = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

const ll MAX = 3e6+10;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

ll v[MAX], n, nxt[MAX], prv[MAX];
map<ll, set<ll> > ocor;

namespace bit {
	ord_set<ii> bit[MAX];

	void build() {
		for (ll i = 1; i <= n; i++) bit[i].insert({nxt[i-1], i-1});
		for (ll i = 1; i <= n; i++) {
			ll j = i + (i&-i);
			if (j <= n) for (auto x : bit[i]) bit[j].insert(x);
		}
	}
	ll pref(ll p, ll x) {
		ll ret = 0;
		for (; p; p -= p&-p) ret += bit[p].order_of_key({x, -INF});
		return ret;
	}
	ll query(ll l, ll r, ll x) {
		return pref(r+1, x) - pref(l, x);
	}
	void update(ll p, ll x) {
		ll p2 = p;
		for (p++; p <= n; p += p&-p) {
			bit[p].erase({nxt[p2], p2});
			bit[p].insert({x, p2});
		}
	}
}

void build() {
	for (ll i = 0; i < n; i++) nxt[i] = INF;
	for (ll i = 0; i < n; i++) prv[i] = -INF;
	vector<ii> t;
	for (ll i = 0; i < n; i++) t.push_back({v[i], i});
	sort(t.begin(), t.end());
	for (ll i = 0; i < n; i++) {
		if (i and t[i].f == t[i-1].f) prv[t[i].s] = t[i-1].s;
		if (i+1 < n and t[i].f == t[i+1].f) nxt[t[i].s] = t[i+1].s;
	}

	for (ll i = 0; i < n; i++) ocor[v[i]].insert(i);

	bit::build();
}

void muda(ll p, ll x) {
	bit::update(p, x);
	nxt[p] = x;
}

ll query(ll a, ll b) {
	return b-a+1 - bit::query(a, b, b+1);
}

void update(ll p, ll x) { // mudar valor na pos. p para x
	if (prv[p] > -INF) muda(prv[p], nxt[p]);
	if (nxt[p] < INF) prv[nxt[p]] = prv[p];

	ocor[v[p]].erase(p);
	if (!ocor[x].size()) {
		muda(p, INF);
		prv[p] = -INF;
	} else if (*ocor[x].rbegin() < p) {
		ll i = *ocor[x].rbegin();
		prv[p] = i;
		muda(p, INF);
		muda(i, p);
	} else {
		ll i = *ocor[x].lower_bound(p);
		if (prv[i] > -INF) {
			muda(prv[i], p);
			prv[p] = prv[i];
		} else prv[p] = -INF;
		prv[i] = p;
		muda(p, i);
	}
	v[p] = x; ocor[x].insert(p);
}


int main(){ _
	cin >> n;
	for(ll i=0;i <n; i++) cin >> v[i];
	build();
	ll q; cin >> q;
	while(q--){
		char c; ll a, b; cin >> c >> a >> b; a--;
		if(c=='Q') cout << query(a, b-1) << endl;
		else update(a, b);
	}
		
	
	
	exit(0);
}
