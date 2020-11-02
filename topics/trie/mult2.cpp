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
//
// trie T() constrói uma trie para o alfabeto das letras minúsculas
// trie T(tamanho do alfabeto, menor caracter) também pode ser usado
//
// Todas as operações ocorrem em O(|s|)
// 
// T.insert(s) para inserir
// T.erase(s) para remover
// T.find(s) para encontrar
// T.count_pref retorna o numero de strings na trie que possuem s como prefixo
//
// O nó de índice 0 é especial, ele corresponde tanto à raiz
// quanto para indicar que a string não pertence à trie

struct trie {
	vector<vector<int>> to;
	vector<int> end, pref;
	int sigma; char norm;
	trie(int sigma_=26, char norm_='a') : sigma(sigma_), norm(norm_) {
		to = {vector<int>(sigma)};
		end = {0}, pref = {0};
	}
	void insert(string s) {
		int x = 0;
		for(auto c : s) {
			int &nxt = to[x][c-norm];
			if(!nxt) {
				nxt = to.size();
				to.push_back(vector<int>(sigma));
				end.push_back(0), pref.push_back(0);
			}
			x = nxt, pref[x]++;
		}
		end[x]++;
	}
	void erase(string s) {
		int x = 0;
		for(char c : s) {
			int &nxt = to[x][c-norm];
			x = nxt, pref[x]--;
			if(!pref[x]) nxt = 0;
		}
		end[x]--;
	}
	int find(string s) {
		int x = 0;
		for(auto c : s) {
			x = to[x][c-norm];
			if(!x) return 0;
		}
		return x;
	}
	int count_pref(string s) {
		return pref[find(s)];
	}
	int query(string s){
		int x = 0, ret = 0;
		for(int i=0; i<s.size(); i++){
			int c = s[i]-norm;
			if(to[x][!c]) ret += 1<<(s.size()-1-i), x = to[x][!c];
			else x = to[x][c];
		}
		return ret;
	}
};

string to_str(int x){
	string ret;
	for(int i=0;i <31; i++) ret += ('a' + !!(x & 1<<(30-i)));
	return ret;
}

int main(){ _
	trie t;
	int q; cin >> q;
	t.insert(to_str(0));

	while(q--){
		char c; int a; cin >> c >> a;
		if(c=='+') t.insert(to_str(a));
		else if(c=='-') t.erase(to_str(a));
		else cout << t.query(to_str(a)) << endl;
	}
	exit(0);
}
