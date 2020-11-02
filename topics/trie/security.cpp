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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 4e6;

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
	int min_xor(string s){
		int x = 0;
		int ret=0;
		string er;
		for(int i=0; i<s.size();i++){
			char c = s[i]-'a';
			if(!t[x][c]) c = !c; 
			er += (c+'a');
			x = t[x][c];
			if(c != (s[i]-'a')) ret += 1<<(s.size()-i-1);
		}
		erase(er);
		return ret;
	}
};

int main(){ _
	int n; cin >> n;
	vector<int> v(n), w(n);
	for(auto &i:v) cin >> i;
	for(auto &i:w) cin >> i;
	
	trie t;
	for(auto a : w){
		string s;
		for(int i=0;i <30; i++) s+=('a' + !!(a & 1<<(29-i)));
		t.insert(s);
	}
	for(auto a : v){
		string s;
		for(int i=0;i <30; i++) s+=('a' + !!(a & 1<<(29-i)));	
		cout << t.min_xor(s) << " ";
	}
	cout << endl;
	
	exit(0);
}
