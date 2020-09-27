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
// Trie
// //
// // N deve ser maior ou igual ao numero de nos da trie
// // fim indica se alguma palavra acaba nesse no
// //
// // Complexidade:
// // Inserir e conferir string S -> O(|S|)
//
// // usar static trie T
// // T.insert(s) para inserir
// // T.find(s) para ver se ta
// // T.prefix(s) printa as strings
// // que tem s como prefixo

const int MAX = 1e5+10;
struct trie{
	map<char, int> t[MAX+5];
	int p; vector<string> pref;
	trie(){
		p = 1;
	}
	void insert(string s){
		s += '$';
		int i = 0;
		for (char c : s){
			auto it = t[i].find(c);
			if (it == t[i].end())
				i = t[i][c] = p++;
			else
				i = it->second;
		}
	}
	bool find(string s){
		s += '$';
		int i = 0;
		for (char c : s){
			auto it = t[i].find(c);
			if (it == t[i].end()) return false;
			i = it->second;
		}
		return true;
	}
	void prefix(string &l, int i){
		if (t[i].find('$') != t[i].end())
			pref.pb(l);
		for (auto p : t[i]){
			l += p.f;
			prefix(l, p.s);
			l.pop_back();
		}
	}
	vector<string> prefix(string s){
		int i = 0; pref.resize(0);
		for (char c : s){
			auto it = t[i].find(c);
			if (it == t[i].end()) return pref;
			i = it->second;
		}
		prefix(s, i);
		return pref;
	}
};

int main(){ _
	int t; cin >> t;
	while(t--){
		trie t;
		int n; cin >> n;
		vector<string> v;
		for(int i=0;i <n; i++){
			string s; cin >> s; v.pb(s); t.insert(s);
		}
		bool show = true;
		for(int i=0;i <n; i++){
			vector<string> ans = t.prefix(v[i]);
			if(ans.size()!=1){
				show = false; break;
			}
		}
		if(show) cout << "YES" << endl;
		else cout << "NO" << endl;
	}


	exit(0);
}
