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

const int MAX = 1e4+10;
int divi[MAX];
vector<int> primes;
int lim = 1e4;
void crivo() {
	divi[1] = 1;
	for (int i = 2; i <= lim; i++) {
		if (divi[i] == 0) divi[i] = i, primes.push_back(i);
		for (int j : primes) {
			if (j > divi[i] or i*j > lim) break;
			divi[i*j] = j;
		}
	}
}

void fact2(int n, vector<ll>& v) {
	if (n != divi[n]) fact2(n/divi[n], v);
	v.push_back(divi[n]);
}

void fact(ll n, vector<ll>& v) {
	if (n == 1) return;
	if(n<=lim) {
		fact2(n, v);
		return;
	}
	if (prime(n)) v.pb(n);
	else {
		ll d = rho(n);
		fact(d, v);
		fact(n / d, v);
	}
}

int main(){ _
	int n, k; cin >> n >> k;
	vector<ll> v(n);
	map<ll, int> pint;
	vector<ll> rpint(n);
	vector<vector<pair<ll, int>>> mp(n);

	map<ll, vector<ll>> fat;
	vector<pair<ll, int>> nprime;
	crivo();
	int pt = 0;
	for(int i=0;i <n; i++){
		ll &a = v[i];
		cin >> a;
		vector<ll> f;
		fact(a, f);
		sort(f.begin(), f.end());
		auto it = unique(f.begin(), f.end());
		f.resize(distance(f.begin(), it));

		if(f[0]==f.back()) {
			if(!pint.count(f[0])) pint[f[0]] = pt, rpint[pt]=f[0], pt++;
			mp[pint[f[0]]].pb({a, i});
		}
		else{
			nprime.pb({a, i});
			fat[a] = f;
		}
	}
	mp.resize(pt);
	if(k==1) return cout << 0 << endl, 0;

	set<int> ans;
	set<ll> val;
	bool has_tree = false;
	for(int i=0; i<n; i++){
		auto w = mp[i];
		if(w.size()>=2){
			val.insert(rpint[i]);
			ans.insert(w[0].s), ans.insert(w[1].s);
		}
		if(w.size()>=3) has_tree = true;
	}

	map<ll, bool> memo;
	auto valido = [&](ll p){
		if(memo.count(p)) return memo[p];
		for(auto u : fat[p]) if(!val.count(u)) return memo[p] = false;
		return memo[p] = true;
	};
	map<ll, int> memo2;
	auto nvalido = [&](ll p){
		if(memo2.count(p)) return memo2[p];
		int ret = 1;
		auto fp = fat[p];
		for(int i=1; i<fp.size(); i++) ret += fp[i]!=fp[i-1];
		return memo2[p] = ret;
	};
	
	if(ans.size()>k){
		ans.clear();
		if(k%2==0){
			for(auto w : mp){
				if(w.size()>=2 and ans.size()<k){
					ans.insert(w[0].s), ans.insert(w[1].s);
				}
			}
		}
		else if(has_tree){
			for(auto w : mp){
				if(w.size()>=3){
					ans.insert(w[0].s), ans.insert(w[1].s), ans.insert(w[2].s);
					break;
				}
			}
			for(auto w : mp){
				if(w.size()>=2 and ans.size()<k){
					ans.insert(w[0].s), ans.insert(w[1].s);
				}
			}
		}
		else{
			pair<ll, int> at = {-1, -1};
			int mini = INF;
			for(auto [u, id] : nprime) if(valido(u) and nvalido(u)<mini) 
				mini = nvalido(u), at = {u, id};
			if(at.s!=-1) ans.insert(at.s);
			
			for(int i=0; i<n; i++){
				auto w = mp[i];
				if(w.size()>=2 and at.f%rpint[i]==0){
					ans.insert(w[0].s), ans.insert(w[1].s);
				}
			}
			for(auto w : mp){
				if(w.size()>=2  and ans.size()<k){
					ans.insert(w[0].s), ans.insert(w[1].s);
				}
			}
		}
	}
	else{
		for(auto w : mp) if(w.size()>=2){
			for(auto [u, id] : w) if(ans.size()<k){
				ans.insert(id);
			}
		}
		for(auto [u, id] : nprime) if(valido(u) and ans.size()<k) 
			ans.insert(id);	
	}
	
	if(ans.size()!=k) cout << 0 << endl;
	else{
		for(auto u : ans) cout << v[u] << " ";
		cout << endl;
	}
	
	exit(0);
}
