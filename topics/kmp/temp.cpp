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

vector<int> matching(string& t, string& s) {
	vector<int> p = pi(s+'$'), match;
	for (int i = 0, j = 0; i < t.size(); i++) {
		while (j and s[j] != t[i]) j = p[j-1];
		if (s[j] == t[i]) j++;
		if (j == s.size()) match.push_back(i-j+1);
	}
	return match;
}

struct KMPaut : vector<vector<int>> {
	KMPaut(){}
	KMPaut (string& s) : vector<vector<int>>(26, vector<int>(s.size()+1)) {
		vector<int> p = pi(s);
		auto& aut = *this;
		aut[s[0]-'a'][0] = 1;
		for (char c = 0; c < 26; c++)
			for (int i = 1; i <= s.size(); i++)
				aut[c][i] = s[i]-'a' == c ? i+1 : aut[c][p[i-1]];
	}
};

int main(){ _
	



	exit(0);
}
