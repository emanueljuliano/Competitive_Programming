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
ll str_hash::P = uniform(27, MOD-1);

int main(){ _
	int n; cin >> n;
	string s; cin >> s;
	int sz = s.size();
	set<ll> st;
	str_hash H(s);
	st.insert(H(0, sz-1));
	n--;
	for(int i=0;i <n; i++){
		cin >> s; sz = s.size();
		s+=s;
		str_hash h(s);
		bool has = false;
		for(int j=0; j<sz; j++) if(st.count(h(j, j+sz-1))) {has = true; break;}
		if(!has) st.insert(h(0, sz-1));
	}
	
	cout << st.size() << endl;	
	exit(0);
}
