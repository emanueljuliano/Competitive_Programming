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

const ll MOD = (1ll<<61)-1;

ll mulmod(ll a, ll b) {
	const static ll LOWER = (1ll<<30)-1, GET31 = (1ll<<31)-1;
	ll l1 = a&LOWER, h1 = a>>30, l2 = b&LOWER, h2 = b>>30;
	ll m = l1*h2 + l2*h1, h = h1*h2;
	ll ans = l1*l2 + (h>>1) + ((h&1)<<60) + (m>>31) + ((m&GET31)<<30) + 1;
	ans = (ans&MOD) + (ans>>61);
	ans = (ans&MOD) + (ans>>61);
	return ans-1;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r) {
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

struct str_hash {
	static ll P;
	int n;
	string s;
	vector<ll> h, power;
	str_hash(string s_) : n(s_.size()), s(s_), h(n), power(n) {
		power[0] = 1;
		for (int i = 1; i < n; i++) power[i] = mulmod(power[i-1], P);
		h[0] = s[0];
		for (int i = 1; i < n; i++) h[i] = (mulmod(h[i-1], P) + s[i]) % MOD;
	}
	ll operator()(int i, int j) { // retorna hash da substring s[i..j]
		if (!i) return h[j];
		ll ret = h[j] - mulmod(h[i-1], power[j-i+1]);
		return ret < 0 ? ret+MOD : ret;
	}
};
ll str_hash::P = uniform((int)1e6+7, MOD-1);
ll P = uniform((int)27, MOD-1);

vector<ll> power((int)1e6+7);


int main(){ _
	map<ll, ll> mp, mp2;
	int n, m; cin >> n >> m;
	power[0] = 1;
	for (int i = 1; i <= n; i++) power[i] = mulmod(power[i-1], P);

	vector<ll> g(n+5), g2(n+5);
	for(int i=1; i<=n; i++) g2[i] = (i + power[i])%MOD;
	for(int i=1;i <=m; i++){
		int a, b; cin >> a >> b;
		g[a]+= b + power[b]; g[a]%=MOD;
		g[b]+= a + power[a]; g[b] %= MOD;
		g2[a]+= b + power[b]; g2[a] %= MOD;
		g2[b]+= a + power[a]; g2[b] %= MOD;
	}
	ll ans = 0;
	for(int i=1; i<=n; i++){
		mp[g[i]]++;
		if(g2[i]!=0) mp[g2[i]]++;
	}

	for(auto x : mp){
		//		cout  << x.f << " " << x.s << endl;
		ans += x.s*(x.s-1)/2;
	}
	//	cout << "DOIS" << endl;
	for(auto x : mp2){
		//		cout  << x.f << " " << x.s << endl;
		ans += x.s*(x.s-1)/2;
	}

	cout << ans << endl;


	exit(0);
}
