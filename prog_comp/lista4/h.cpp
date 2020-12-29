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

vector<int> pi(string s) {
	vector<int> p(s.size());
	for (int i = 1, j = 0; i < s.size(); i++) {
		while (j and s[j] != s[i]) j = p[j-1];
		if (s[j] == s[i]) j++;
		p[i] = j;
	}
	return p;
}

bool matching(string& t, string& s) {
	vector<int> p = pi(s+'$');
	for (int i = 0, j = 0; i < t.size(); i++) {
		while (j and s[j] != t[i]) j = p[j-1];
		if (s[j] == t[i]) j++;
		if (j == s.size()) return true;
	}
	return false;
}

int main(){ _
		
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		int m; cin >> m;
		while(m--){
			string s2; cin >> s2;
			if(matching(s, s2)) cout << "y" << endl;
			else cout << "n" << endl;
		}
	}
	exit(0);
}
