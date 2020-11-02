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

const int MAX = 3e5+10;

struct trie{
	int p;
	vector<vector<int>> t;
	int fim[MAX];
	trie() : t(MAX, vector<int>(26)) {p = 1;}

	void insert(string s){
		int i = 0;
		for(char c : s){
			int &j = t[i][c-'a'];
			if(!j) j = p++;
			i=j;
		}
		fim[i] = 1;
	}
	bool find(string s){
		int i = 0;
		for(char c : s){
			i = t[i][c-'a'];
			if(!i) return false;
		}
		return fim[i];
	}
	void prefix(int i, string s){
		if(fim[i]) cout << s << endl;
		for(int j=0;j <26; j++) if(t[i][j])
			prefix(t[i][j], s+char('a'+j));	
	}
	bool prefix(string s){
		int i = 0;
		bool has = true;
		for(char c : s){
			i = t[i][c-'a'];
			if(!i) return false;
		}
		has = false;
		for(int j=0;j <26; j++) if(t[i][j])
			has=true, prefix(t[i][j], s+char('a'+j));
		return has;
	}
};

int main(){ _
	
	int n; cin >> n;
	trie t;
	
	vector<string> v;
	for(int i=0;i <n; i++){
		string s; cin >> s; t.insert(s);
	}

	int m; cin >> m;
	for(int i=0;i <m; i++){
		cout << "Case #" << i+1 << ":" << endl;
		string s; cin >> s;
		bool found = t.prefix(s);
		if(!found) cout << "No match." << endl;
	}

	exit(0);
}
