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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

ll mul(ll a, ll b, ll m) {
	ll ret = a*b - ll(a*(long double)b/m+0.5)*m;
	return ret < 0 ? ret+m : ret;
}

ll expo(ll a, ll b, ll m) {
	if (!b) return 1;
	ll ans = expo(mul(a, a, m), b/2, m);
	return b%2 ? mul(a, ans, m) : ans;
}

bool prime(ll n) {
	if (n < 2) return 0;
	if (n <= 3) return 1;
	if (n % 2 == 0) return 0;

	ll d = n - 1;
	int r = 0;
	while (d % 2 == 0) {
		r++;
		d /= 2;
	}

	for (int i : {2, 325, 9375, 28178, 450775, 9780504, 795265022}) {
		if (i >= n) break;
		ll x = expo(i, d, n);
		if (x == 1 or x == n - 1) continue;

		bool deu = 1;
		for (int j = 0; j < r - 1; j++) {
			x = mul(x, x, n);
			if (x == n - 1) {
				deu = 0;
				break;
			}
		}
		if (deu) return 0;
	}
	return 1;
}

ll rho(ll n) {
	if (n == 1 or prime(n)) return n;
	if (n % 2 == 0) return 2;

	while (1) {
		ll x = 2, y = 2, ciclo = 2, i = 0, d = 1;
		ll c = uniform(1, n-1);

		while (d == 1) {
			if (++i == ciclo) ciclo *= 2, y = x;
			x = (mul(x, x, n) + c) % n;

			if (x == y) break;

			d = __gcd(abs(x-y), n);
		}

		if (x != y) return d;
	}
}

void fact(ll n, vector<ll>& v) {
	if (n == 1) return;
	if (prime(n)) v.pb(n);
	else {
		ll d = rho(n);
		fact(d, v);
		fact(n / d, v);
	}
}

int main(){ _
	int n, m, k; cin >> m >> n >> k;	
	
	vector<ll> v(n);
	vector<vector<pair<ll, int>>> f(n);
	for(int i=0;i <n; i++){
		cin >> v[i];
		vector<ll> aux;
		fact(v[i], aux);
		sort(aux.begin(), aux.end());
		int it = 1;
		f[i].pb({aux[0], 1});
		while(it<aux.size()){
			while(it<aux.size() and f[i].back().f == aux[it]) f[i][f[i].size()-1].s++, it++;
			if(it<aux.size()) f[i].pb({aux[it], 1}), it++;
		}
	}
	vector<vector<int>> div;

	vector<pair<ii, int>> e;
	vector<ll> ans(m);
	for(int i=0; i<k; i++){
		ll a, b, c; cin >> a >> b >> c; a--, b--;
		e.pb({{a, b}, c});
	}
	sort(e.begin(), e.end());
	vector<int> vis(m);
	set<ll> st;
	for(int j=0;j <e.size(); j++){
		ll a, b, c; a = e[j].f.f, b=e[j].f.s, c=e[j].s;
		if(vis[a]) continue;
		for(int i=0;i <f[b].size(); i++){
			if(f[b][i].s==c and !st.count(f[b][i].f)){
				st.insert(f[b][i].f);
				vis[a] = 1;
				ans[a] = f[b][i].f;
				break;
			}
		}
	}
	sort(ans.begin(), ans.end());
	for(auto a : ans) cout << a << " ";
	cout << endl;
	
	exit(0);
}
