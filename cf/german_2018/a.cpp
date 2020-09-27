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

const int MAX = 1005*1005;
int h, m;
int f(int x, int y){ return x*m+y;}
int n;

template<typename T> struct rmq {
	vector<T> v;
	int n; static const int b = 30;
	vector<int> mask, t;

	int op(int x, int y) { return v[x] < v[y] ? x : y; }
	int msb(int x) { return __builtin_clz(1)-__builtin_clz(x); }
	rmq() {}
	rmq(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
		for (int i = 0, at = 0; i < n; mask[i++] = at |= 1) {
			at = (at<<1)&((1<<b)-1);
			while (at and op(i, i-msb(at&-at)) == i) at ^= at&-at;
		}
		for (int i = 0; i < n/b; i++) t[i] = b*i+b-1-msb(mask[b*i+b-1]);
		for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
			t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
	}
	int small(int r, int sz = b) { return r-msb(mask[r]&((1<<sz)-1)); }
	T query(int l, int r) {
		if (r-l+1 <= b) return small(r, r-l+1);
		int ans = op(small(l+b-1), small(r));
		int x = l/b+1, y = r/b-1;
		if (x <= y) {
			int j = msb(y-x+1);
			ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
		}
		return ans;
	}
};

namespace lca {
	vector<int> g[MAX];
	int v[2*MAX], pos[MAX], dep[2*MAX];
	int t;
	rmq<int> RMQ;

	void dfs(int i, int d = 0, int p = -1) {
		v[t] = i, pos[i] = t, dep[t++] = d;
		for (int j : g[i]) if (j != p) {
			dfs(j, d+1, i);
			v[t] = i, dep[t++] = d;
		}
	}
	void build(int n, int root) {
		t = 0;
		dfs(root);
		RMQ = rmq<int>(vector<int>(dep, dep+2*n-1));
	}
	int lca(int a, int b) {
		a = pos[a], b = pos[b];
		return v[RMQ.query(min(a, b), max(a, b))];
	}
	int dist(int a, int b) {
		return dep[pos[a]] + dep[pos[b]] - 2*dep[pos[lca(a, b)]];
	}
}

int main(){ _
	string str;
	cin >> h >> m;
	getline(cin, str);
	getline(cin, str);
	for(int i=0;i <h; i++){
		getline(cin , str);
		for(int j=1; j<str.size()-1; j+=2){
			int a = f(i, j/2);
			if(i!=n-1 and str[j]==' '){
				int b = f(i+1, j/2);
				lca::g[a].pb(b); lca::g[b].pb(a);
			}
			if(j/2 != m-1 and str[j+1]==' '){
				int b = f(i, j/2+1);
				//		cout << "entrou? " << a << " " << b << endl;
				lca::g[a].pb(b), lca::g[b].pb(a);
			}
		}
	}
	n = h*m;

	int q; cin >> q;
	vector<int> v;
	while(q--){
		int a, b; cin >> a >> b; a--; b--;
		v.pb(f(a, b));
	} q = v.size();

	lca::build(n, 0);
	ll ans = 0;
	for(int i=0;i <q-1; i++){
		ans +=  lca::dist(v[i], v[i+1]);
	}
	cout << ans << endl;

	exit(0);
}
