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
#define string vector<int>

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
	s.pb(INF);
	vector<int> p = pi(s), match;
	s.pop_back();
	for (int i = 0, j = 0; i < t.size(); i++) {
		while (j and s[j] != t[i]) j = p[j-1];
		if (s[j] == t[i]) j++;
		if (j == s.size()) match.push_back(i-j+1);
	}
	return match;
}

int main(){ _
	int n, m; cin >> n >> m;
	vector<int> v(n), w(m);
	for(auto &i : v) cin >> i;
	for(auto &i : w) cin >> i;

	vector<int> s, t;
	for(int i=0;i<n-1; i++){
		s.pb(v[i+1]-v[i]);
	}
	for(int i=0;i<m-1; i++){
		t.pb(w[i+1]-w[i]);
	}

	vector<int> ans = matching(s, t);

	cout << ans.size() + t.empty()<< endl;

	exit(0);
}
