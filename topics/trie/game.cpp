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

const int MAX = 3e5;

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
	bool win(int x){
		bool ret = true;
		for(int i=0; i<26; i++) if(t[x][i])
			ret &= win(t[x][i]);
		return !ret;
	}
	bool lose(int x){
		bool ret = true;
		int pos = 0;
		for(int i=0; i<26; i++) if(t[x][i])
			ret &= lose(t[x][i]), pos++;
		return (!pos or !ret);	
	}
};

int main(){ _
	int n, k; cin >> n >> k;
	trie t;
	for(int i=0;i <n; i++){
		string s; cin >> s;
		t.insert(s);
	}

	bool win = t.win(0);
	bool lose = t.lose(0);
	if(win and lose) cout << "First" << endl;
	else if(win and !lose){
		if(k%2) cout << "First" << endl;
		else cout << "Second" << endl;
	}
	else cout << "Second" << endl;
	exit(0);
}
