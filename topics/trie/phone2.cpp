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

const int MAX = 1e5;

struct trie{
	int p;
	vector<vector<int>> t;
	vector<int> fim;
	trie() : t(MAX, vector<int>(26)), fim(MAX) {p = 1;}

	bool insert(string s){
		int i = 0;
		for(char c : s){
			int &j = t[i][c-'a'];
			if(!j) j = p++;
			i=j;
			if(fim[i]) return false; 
		}
		fim[i] = 1;
		for(int j=0; j<26; j++) if(t[i][j]) return false;
		return true;
	}
	bool find(string s){
		int i = 0;
		for(char c : s){
			i = t[i][c-'a'];
			if(!i) return false;
		}
		return fim[i];
	}
};

int main(){ _
	int tt; cin >> tt;
	while(tt--){
		int n; cin >> n;
		trie t;
		bool show = true;
		
		for(int i=0;i <n; i++){
			string s; cin >> s;
			for(auto &c : s) c = c-'0'+'a';
			show &= t.insert(s);
		}
		if(show) cout << "YES" << endl;
		else cout << "NO" << endl;
	}	

	exit(0);
}
