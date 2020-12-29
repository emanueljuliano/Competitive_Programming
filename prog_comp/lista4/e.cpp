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
KMPaut A, B;
int dp[1010][55][55];
string x, s, t;
int rec(int a, int b, int c){
	if(a==x.size()) return 0;

	int &ret = dp[a][b][c];
	if(ret != INF) return ret;
	if(x[a]=='*'){
		ret = -INF;
		for(int i=0;i <26; i++){
			bool es, et;
			es = A[i][b]==s.size();
			et = B[i][c]==t.size();
			ret = max(ret, rec(a+1, A[i][b], B[i][c]) + es - et);
		}
	}
	else{
		ret = 0;
		int es, et, at = x[a]-'a';
		es = A[at][b]==s.size();
		et = B[at][c]==t.size();
		ret = rec(a+1, A[at][b], B[at][c]) + es - et;
	}
//	cout << a << " " << b << " " << c << " " << ret << endl;
	return ret;
}

int main(){ _
	memset(dp, INF, sizeof dp);
	cin >> x;
	cin >> s >> t;

	A = KMPaut (s);
	B = KMPaut (t);
	cout << rec(0, 0, 0) << endl;
	exit(0);
}
