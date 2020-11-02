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

const int MAX = 3e6;

struct trie{
	int p;
	vector<vector<int>> t;
	vector<int> fim, pref;
	trie() : t(MAX, vector<int>(2)), fim(MAX), pref(MAX) {p = 1;}

	void insert(string s){
		int x = 0;
		for(char c : s){
			int &y = t[x][c-'a'];
			if(!y) y = p++;
			x=y;
			pref[x]++;
		}
		fim[x]++;
	}
	void erase(string s){
		int x = 0;
		vector<int> pos; pos.pb(x);
		for(char c : s){
			int &y = t[x][c-'a'];
			x = y, pref[x]--;
			if(!pref[x]) y = 0;
		}
		fim[x]--;
	}
	bool find(string s){
		int x = 0;
		for(char c : s){
			x = t[x][c-'a'];
			if(!x) return false;
		}
		return fim[x];
	}
	ll query(string s){
		int x = 0;
		ll ret = 0;
		for(int i=0; i<s.size(); i++){
			int c = s[i]-'a';
			if(t[x][!c]) ret += 1LL<<(s.size()-1-i), x = t[x][!c];
			else x = t[x][c];
		}
		return ret;
	}
};

int main(){ _

	int n; cin >> n;
	vector<ll> v(n+1);
	v[0]=0;
	for(int i=1;i <=n; i++) cin >> v[i];	

	ll ans = 0;
	ll at = 0;
	trie t;
	vector<string> w;
	for(auto a : v){
		at ^= a;
		string s;
		for(ll i=0; i<41; i++) s+=('a' + !!(at & 1LL<<(40-i)));
		t.insert(s);
		w.pb(s);
	}

	v.pb(0);
	reverse(v.begin(), v.end());
	v.pop_back();
	at = 0;
	for(auto a : v){
		at ^= a;
		string s;
		for(int i=0; i<41; i++) s+=('a' + !!(at & 1LL<<(40-i)));
		ans = max(ans, t.query(s));
		t.erase(w.back());
		w.pop_back();
	}

	cout << ans << endl;


	exit(0);
}
