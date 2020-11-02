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
			if(t[x][!c]) ret += 1<<(s.size()-1-i), x = t[x][!c];
			else x = t[x][c];
		}
		return ret;
	}
};

int main(){ _
	int q; cin >> q;
	trie t;
	string aux;
	for(int i=0;i <=30; i++) aux+='a';
	t.insert(aux);
	while(q--){
		char c; int n; cin >> c >> n;
		string s;
		for(int i=0;i <=30; i++) s+= 'a';
		int at = 30;
		while(n){
			s[at]+=n%2;
			n/=2;
			at--;
		}
		if(c=='+') t.insert(s);
		else if(c=='-') t.erase(s);
		else{
			int ans = t.query(s);
			cout << ans << endl;
		}
	}

	exit(0);
}
