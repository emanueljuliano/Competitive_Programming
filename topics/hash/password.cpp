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

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

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
const int MOD = 1e9+7;

int main(){ _
	string s; cin >> s;
	str_hash<MOD> h(s);
	vector<ii> pos;
	for(int i=0;i <s.size()-1; i++){
		int a=h(0, i), b = h(s.size()-1-i, s.size()-1);
		if(a==b) pos.pb({i, a});
	}
	reverse(pos.begin(), pos.end());
	int ans = -1;
	for(auto p : pos){
		for(int j=1; j<s.size()-1-p.f; j++){
			if(h(j, j+p.f) == p.s){
				ans = p.f; break;
			}
		}
		if(ans!=-1) break;
	}
	if(ans==-1) cout << "Just a legend" << endl;
	else{
		for(int i=0;i <=ans; i++) cout << s[i];
		cout << endl;
	}
	exit(0);
}
