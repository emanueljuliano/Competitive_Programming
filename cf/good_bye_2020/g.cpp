#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9+7;

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<int MOD> struct str_hash {
	static int P;
	int n;
	string s;
	vector<ll> h, power;
	str_hash(string s_) : n(s_.size()), s(s_), h(n), power(n) {
		power[0] = 1;
		for (int i = 1; i < n; i++) power[i] = power[i-1]*P % MOD;
		h[0] = s[0];
		for (int i = 1; i < n; i++) h[i] = (h[i-1]*P + s[i]) % MOD;
	}
	ll operator()(int i, int j) { // retorna hash da substring s[i..j]
		if (!i) return h[j];
		ll ret = h[j] - h[i-1]*power[j-i+1] % MOD;
		return ret < 0 ? ret+MOD : ret;
	}
};
template<int MOD> int str_hash<MOD>::P = uniform(27, MOD-1);

int main(){ _
	int n, q; cin >> n >> q;

	string aux, t; cin >> aux >> t;
	vector<string> s;
	vector<str_hash<MOD>> h;
	s.pb(aux);
	h.pb(str_hash<MOD>(aux));
	for(int i=0;i <t.size(); i++){
		s.pb(s.back() + t[i] + s.back());
		h.pb(str_hash<MOD>(s.back()));
		if(s.back().size() > (int)1e6) break;
	}
	
	vector<ll> p2, inv2;
	p2.pb(1), inv2.pb(1);
	for(int i=1;i <(int)1e5+10; i++) 
		p2.pb(p2.back()*2%MOD), inv2.pb(inv2.back()*(MOD+1)/2%MOD);

	vector dp(t.size()+5, vector<int>(27, 0));
	for(int i=1;i <=t.size();i++) for(char c='a'; c<='z'; c++){
		dp[i][c-'a'] = 2*dp[i-1][c-'a']%MOD;
		if(t[i-1]==c) dp[i][c-'a']++;
	}

	auto g = [&](int i, int k, char c){
		ll ret = dp[k][c-'a'];
		ret = (ret - dp[i][c-'a']*p2[k-i])%MOD;
		//cout << i << " " << k << " " << c << " " << ret << endl;
		return (ret+MOD)%MOD;
	};

	while(q--){
		int k; cin >> k;
		string w; cin >> w;
		str_hash<MOD> hw(w);
		
		ll ans = 0;
		for(int i=0;i <s.size(); i++) if(s[i].size()>=w.size()){
			if(i>k) break;
			int sz = s[i].size(), wsz=w.size();
		
			for(int j=0;j <sz-wsz+1; j++){
				if(h[i](j, j+wsz-1) == hw(0, wsz-1)) ans = (ans + p2[k-i])%MOD;
			}
			if(wsz==1) {
				ans = (ans + g(i, k, w[0]));
				break;
			}
			if(hw(1, wsz-1)==h[i](0, wsz-2)) ans = (ans + g(i, k, w[0]));
			if(hw(0, wsz-2)==h[i](sz-1-wsz+2, sz-1)) ans = (ans + g(i, k, w[wsz-1]));
			for(int j=1; j<w.size()-1; j++){
				if(hw(0, j-1)==h[i](sz-j, sz-1) and hw(j+1, wsz-1)==h[i](0, wsz-1-j-1)){ 
					//cout << w << " "<< j << " " << s[i] << " "<< i << endl;
					ans = (ans+g(i, k, w[j]))%MOD; 
				}
			}
			break;
		}
		cout << ans%MOD << endl;
	}
	
	
	
	exit(0);
}
