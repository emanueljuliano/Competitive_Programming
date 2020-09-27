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
	KMPaut (string& s) : vector<vector<int>>(15, vector<int>(s.size()+1)) {
		vector<int> p = pi(s);
		auto& aut = *this;
		aut[s[0]-'0'][0] = 1;
		for (char c = 0; c < 15; c++)
			for (int i = 1; i <= s.size(); i++)
				aut[c][i] = s[i]-'0' == c ? i+1 : aut[c][p[i-1]];
	}
};

KMPaut A;
char M[4][3];
ll dp[(int)1e4+10][110][20]; // i, j, k
int n, m;
const int MOD = 1e9+7;

// 1 -> 6, 8
// 2 -> 7, 9
// 3 -> 4, 8
// 4 -> 3, 9, 0
// 5 -> -
// 6 -> 1, 7, 0
// 7 -> 2, 6
// 8 -> 1, 3
// 9 -> 2, 4
// 0 -> 4, 6

ll rec(int x, int y, int k){
	if(m!=0 and y == m) return 0;
	if(x==n) return 1;
	if(k==5) return 0;
	ll &ret = dp[x][y][k];
	if(ret != -1) return ret;
	ret = 0;

	if(k==1) ret = ret + rec(x+1, A[6][y], 6) + rec(x+1, A[8][y], 8);
	if(k==2) ret = ret + rec(x+1, A[7][y], 7) + rec(x+1, A[9][y], 9);
	if(k==3) ret = ret + rec(x+1, A[4][y], 4) + rec(x+1, A[8][y], 8);
	if(k==4) ret = ret + rec(x+1, A[3][y], 3) + rec(x+1, A[9][y], 9) + rec(x+1, A[0][y], 0);
	if(k==6) ret = ret + rec(x+1, A[1][y], 1) + rec(x+1, A[7][y], 7) + rec(x+1, A[0][y], 0);
	if(k==7) ret = ret + rec(x+1, A[2][y], 2) + rec(x+1, A[6][y], 6);
	if(k==8) ret = ret + rec(x+1, A[1][y], 1) + rec(x+1, A[3][y], 3);
	if(k==9) ret = ret + rec(x+1, A[2][y], 2) + rec(x+1, A[4][y], 4);
	if(k==0) ret = ret + rec(x+1, A[4][y], 4) + rec(x+1, A[6][y], 6);
	ret %= MOD;
	return ret;
}

int main(){ _
	memset(dp, -1, sizeof(dp));
	int k; cin >> n >> m >> k;
	string t; cin >> t;
	if(!t.empty()) A = KMPaut (t);
	else{
		t += char('0'+10);
		A = KMPaut(t);
	}
	ll ans = rec(0, 0, k);
	cout << ans << endl;	

	exit(0);
}
