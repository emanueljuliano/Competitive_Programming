#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;

const int LOG = 25;
const int MOD = 1e9+7;

int basis[LOG]; // basis[i] = mask do cara com bit mais significativo i
int rk=0; // tamanho da base

void insert(int mask) {
	for (int i = LOG - 1; i >= 0; i--) if (mask>>i&1) {
		if (!basis[i]) {
			basis[i] = mask, rk++;
			return;
		}
		mask ^= basis[i];
	}
}

int get(int mask) {
	int ret = 0;
	for (int i = LOG - 1; i >= 0; i--) if (mask>>i&1) {
		if (!basis[i]) return -1;
		mask ^= basis[i], ret |= (1<<i);
	}
	return ret;
}

int main(){ _
	int n, q; cin >> n >> q;
	vector<int> v(n); for(auto &u : v) cin >> u;

	vector<pair<ii, int>> query;
	vector<int> ans(q);
	for(int i=0;i <q; i++){
		int a, b; cin >> a >> b;
		query.pb({{a, b}, i});
	}

	sort(query.begin(), query.end());

	vector<int> p2(n+10);
	p2[0] = 1;
	for(int i=1;i <=n; i++) p2[i] = (p2[i-1]*2)%MOD;

	int at = 0;
	for(int i=0;i<q; i++){
		while(at < query[i].f.f) insert(v[at]), at++;

		if(get(query[i].f.s)!=-1 or !query[i].f.s) ans[query[i].s] = p2[at-rk];
	}

	for(auto u : ans) cout << u << endl;


	exit(0);
}
