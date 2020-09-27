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

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<int MOD> struct str_hash {
	static int P;
	int n;
	string s;
	vector<ll> h, power;
	str_hash(string s_): n(s_.size()), s(s_), h(n), power(n){
		power[0] = 1;
		for (int i = 1; i < n; i++) power[i] = power[i-1]*P % MOD;
		h[0] = s[0];
		for (int i = 1; i < n; i++) h[i] = (h[i-1]*P + s[i]) % MOD;
	}
	ll operator()(int i, int j){ // returna hash da substring s[i..j]
		if (!i) return h[j];
		return (h[j] - h[i-1]*power[j-i+1] % MOD + MOD) % MOD;
	}
};
template<int MOD> int str_hash<MOD>::P = uniform(27, MOD-1);

const ll MOD = 1e9+7;

int main(){ _
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		string pref, suf;
		for(int i=0; i<s.size()/2; i++){
			if(s[i]==s[s.size()-i-1]){
				pref.pb(s[i]);
				if(i!=s.size()-1-i)
					suf.pb(s[s.size()-1-i]);
			}
			else break;
		}
		int q = pref.size();
		string str;
		string aux, aux2;
		for(int i=q; i<s.size()-pref.size(); i++){
			str.pb(s[i]);
		}
		if(!str.empty()){
		str_hash <(ll)MOD> h(str);
		reverse(str.begin(), str.end());
		str_hash <(ll)MOD> h2(str);

		int ans = 0;
		for(int i=0; i<str.size(); i++){
			if(h(0, i)==h2(str.size()-i-1, str.size()-1)){
				ans = i;
			}
		}
		int ans2 = 0;
		for(int i=0; i<str.size(); i++){
			if(h2(0, i)==h(str.size()-i-1, str.size()-1)){
				ans2 = i;
			}
		}
	
		for(int i=0; i<=ans2; i++){
			aux2.pb(str[i]);
		}
		reverse(str.begin(), str.end());
		for(int i=0; i<=ans; i++)
			aux.pb(str[i]);
		}
		if(aux.size()>aux2.size()){
			cout << pref;
			cout << aux;
			reverse(suf.begin(), suf.end());
			cout << suf;
			cout << endl;
		}
		else{
			cout << pref;
			reverse(aux2.begin(), aux2.end());
			cout << aux2;
			reverse(suf.begin(), suf.end());
			cout << suf;
			cout << endl;
		}
	}
	
	
	
	exit(0);
}
