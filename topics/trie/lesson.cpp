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
	int query(string s){
		int x = 0, ret = 0;
		for(int i=0; i<s.size(); i++){
			int c = s[i]-'a';
			int l = pref[t[x][c]];

			if(l < 1<<(s.size()-1-i)) x = t[x][c];
			else ret += 1<<(s.size()-1-i), x=t[x][!c];
			if(!x) return ret;
		}
		return ret;
	}
};

string to_str(int x){
	string ret;
	for(int i=0; i<21; i++) ret += ('a' + !!(x & 1<<(20-i)));
	return ret;
}

int main(){ _
	int n, m;
	cin >> n >> m;
	set<int> st;
	for(int i=0;i <n; i++){
		int a; cin >> a; st.insert(a);
	}
	n = st.size();
	trie t;
	for(auto a : st) t.insert(to_str(a)); 

	int at = 0;
	while(m--){
		int a; cin >> a;
		at ^=a;
		cout << t.query(to_str(at)) << endl;
	}

	exit(0);
}
