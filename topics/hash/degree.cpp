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
	str_hash() {}
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

template<int MOD> int str_hash<MOD>::P = uniform(71, MOD-1);
const int MOD = 1e9+7;
string s="", t="";
str_hash<MOD> h1, h2;
int n;
int rec(int i, int sz){
	if(sz==1) return 1;
//	cout << "(" << i << ", " << i+sz-1 << ") (" << n-i-sz << ", " << n-1-i << ")" << endl;
	if(h1(i, i+sz-1)!=h2(n-i-sz, n-1-i)) return 0;
	//cout << i << " " << j << " " << h1(i, j) << " " << h2(i, j) << endl;
	int m = (sz)/2;
	return 1+ rec(i, m);
}

int main(){ _
	cin >> s;
	t = s; reverse(t.begin(), t.end());
	h1 = str_hash<MOD> (s);
	h2 = str_hash<MOD> (t);
	n = s.size();
	int ans = 0;
	vector<int> pd;
	for(int i=0;i <s.size(); i++){
		if(i==0) pd.pb(1);
		else{
			if(h1(0, i) == h2(n-1-i, n-1)) pd.pb(1+pd[(i-1)/2]);
			else pd.pb(0);
		}
		ans+=pd[i];
	}
//	for(auto k : pd) cout << k << " ";
//	cout << endl;
	cout << ans << endl;

	exit(0);
}
