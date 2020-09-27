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

const int MOD = 1e9+9;

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

int main(){ _
	int n, m; cin >> n >> m;
	string s; cin >> s;
	for(int i=0;i <m; i++) s.pb(s[i]);
	str_hash <MOD>hs(s);
	int q; cin >> q;
	map<int, int> mp;
	for(int i=0;i <q; i++){
		string a; cin >> a;
		mp[str_hash<MOD>(a)(0, m-1)]=i+1;
	}
	vector<int> ans;
	set<int> st;
	for(int k=0; k<m; k++){
		st.clear(), ans.clear();
		int at = 0;
		for(int i=k;i <n*m; i+=m){
			int h = hs(i, i+m-1);
			if(mp.count(h)) ans.pb(mp[h]), st.insert(mp[h]);
		}
		if(st.size()==n and ans.size()==n) break;
	}
	if(ans.size()==n and st.size()==n){
		cout << "YES" << endl;
		for(auto x : ans) cout << x << " ";
		cout << endl;
	}
	else cout << "NO" << endl;



	exit(0);
}
