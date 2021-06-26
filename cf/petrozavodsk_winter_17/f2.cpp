#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

ll mul(ll a, ll b, ll m) {
	ll ret = a*b - ll((long double)1/m*a*b+0.5)*m;
	return ret < 0 ? ret+m : ret;
}

ll pow(ll x, ll y, ll m) {
	if (!y) return 1;
	ll ans = pow(mul(x, x, m), y/2, m);
	return y%2 ? mul(x, ans, m) : ans;
}

bool prime(ll n) {
	if (n < 2) return 0;
	if (n <= 3) return 1;
	if (n % 2 == 0) return 0;

	ll r = __builtin_ctzll(n - 1), d = n >> r;
	for (int a : {2, 325, 9375, 28178, 450775, 9780504, 795265022}) {
		if (a >= n) break;
		ll x = pow(a, d, n);
		if (x == 1 or x == n - 1) continue;
		
		for (int j = 0; j < r - 1; j++) {
			x = mul(x, x, n);
			if (x == n - 1) break;
		}
		if (x != n - 1) return 0;
	}
	return 1;
}

ll rho(ll n) {
	if (n == 1 or prime(n)) return n;
	auto f = [n](ll x) {return mul(x, x, n) + 1;};

	ll x = 0, y = 0, t = 30, prd = 2, x0 = 1, q;
	while (t % 40 != 0 or gcd(prd, n) == 1) {
		if (x==y) x = ++x0, y = f(x);
		q = mul(prd, abs(x-y), n);
		if (q != 0) prd = q;
		x = f(x), y = f(f(y)), t++;
	}
	return gcd(prd, n);
}

vector<ll> fact(ll n) {
	if (n == 1) return {};
	if (prime(n)) return {n};
	ll d = rho(n);
	vector<ll> l = fact(d), r = fact(n / d);
	l.insert(l.end(), r.begin(), r.end());
	return l;
}

vector<pair<ll, int>> ff;
vector<ll> d;
void rec(int pos, ll val) {
	if (pos >= ff.size()) {
		d.push_back(val);
		return;
	}
	rec(pos+1, val);
	for (int i=0; i<ff[pos].second; i++) {
		val*=ff[pos].first;
		rec(pos+1, val);
	}
}

int main(){ _
	int n, k; cin >> n;// >> k;
	k = n/2;
	vector<ll> v(n);
	for (auto &i : v) cin >> i;
	
	map<ll, int> ans;
	for (int p1 = 0; p1 < 12; p1++) {
		int at = uniform(0, n-1);
		//cout << endl << "Iteracao " << p1 << " " << v[at] << endl;
		ll x = v[at];
		vector<ll> f = fact(x);
		sort(f.begin(), f.end());
		f.push_back(-1);
		
		ff.clear(), d.clear();
		vector<ll> pri;
		int it = 0;
		for (int i=0; i<f.size(); i++) {
			if (f[i]!=f[it]) { 
				pri.push_back(f[it]);
				ff.push_back({f[it], i-it}), it = i;
			}
		}
		rec(0, 1);
		sort(d.begin(), d.end());
		map<ll, int> cnt;
		for (ll c : d) cnt[c] = 0;
		for (ll c : v) cnt[gcd(c, x)]++;
		
		ll ans_at = 1;
		for (auto [p, ex] : ff) {
			for (auto [y, c] : cnt) {
				ll acc = 1;
				for (int i=0; i<ex; i++) {
					acc *= p;
					if (y % acc != 0) break;
					cnt[y/acc] += c;
				}
			}	
		}
		for (auto [y, c] : cnt) if (c >= n-k) ans_at = y;
		ans[ans_at]++;
	}	
	
	cout << ans.rbegin()->first << endl;
	
	
	exit(0);
}
