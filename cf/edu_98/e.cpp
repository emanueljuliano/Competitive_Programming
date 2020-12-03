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

const int MAX = 2e3+100;

namespace bit {
	ll bit[2][MAX+2];
	int n;

	void build(int n2, int* v) {
		n = n2;
		for (int i = 1; i <= n; i++)
			bit[1][min(n+1, i+(i&-i))] += bit[1][i] += v[i-1];
	}
	ll get(int x, int i) {
		ll ret = 0;
		for (; i; i -= i&-i) ret += bit[x][i];
		return ret;
	}
	void add(int x, int i, ll val) {
		for (; i <= n; i += i&-i) bit[x][i] += val;
	}
	ll get2(int p) {
		return get(0, p) * p + get(1, p);
	}
	ll query(int l, int r) {
		r = min(r, n-1);
		return get2(r+1) - get2(l);
	}
	void update(int l, int r, ll x) {
		r = min(r, n-1);
		add(0, l+1, x), add(0, r+2, -x);
		add(1, l+1, -x*l), add(1, r+2, x*(r+1));
	}
};


int main(){ _
	int n, m, k; cin >> n >> m >> k;
	bit::n = n+10;
	vector<ii> v(m);
	for(auto &i : v) cin >> i.f >> i.s;
	ll ans = 0;
	for(int i=1; i<=n-k+1; i++){
		ll sum1 = 0;
		vector<vector<int>> ev(2*n+10);
		for(int j=0;j <v.size(); j++) {
			int cov = min(v[j].s, i+k-1) - max(i, v[j].f) + 1;
			cov = max(cov, 0);
			if(v[j].s<i+k) sum1 += cov;
			else {
				bit::update(v[j].f, v[j].s, 1);
				ev[v[j].s-cov].pb(j);
			}
		}
		for(int j=i; j<=n+2; j++){
			ans = max(ans, sum1+bit::query(j, j+k-1));
			for(auto id : ev[j]){
				int cov = min(v[id].s, i+k-1) - max(i, v[id].f) + 1;
				cov = max(cov, 0);
				bit::update(v[id].f, v[id].s, -1);
				sum1 += cov;
			}
		}
	}
	cout << ans << endl;
	
	exit(0);
}
