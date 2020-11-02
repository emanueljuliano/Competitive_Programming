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

const int MAX = 2e6;

string bad;
int k;
struct trie{
	int p;
	vector<vector<int>> t;
	vector<int> fim, pref;
	trie() : t(MAX, vector<int>(26)), fim(MAX), pref(MAX) {p = 1;}

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
	int dfs(int v, int at){
		if(at>k) return 0;
		int ret = 1;
		for(int i=0;i <26; i++) if(t[v][i]) 
			ret += dfs(t[v][i], at + !(bad[i]-'0'));
		return ret;
	}
};

int main(){ _
	string s; cin >> s;
	cin >> bad;
	cin >> k;
	trie t;
	for(int i=0;i <s.size(); i++) t.insert(s.substr(i, s.size()-i)); 
	cout << t.dfs(0, 0)-1 << endl;
	exit(0);
}
