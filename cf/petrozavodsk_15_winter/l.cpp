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

const int MAX = 5e3+10;

char dp[MAX][MAX][3];

int n, m;
string s, t;

char solve(int i, int j, bool can) {
	if (i == n and j == m) return 1;
	if (j == m) return 0;

	auto& ans = dp[i][j][can];
	if (ans+1) return ans;

	ans = 0;
	if (i < n and s[i] == t[j]) ans |= solve(i+1, j+1, false);
	if(can) ans|= solve(i, j+1, can);
	if (i > 0 and t[j] != s[i-1]) ans |= solve(i, j+1, true);
	if (j > 0 and t[j] != t[j-1]) ans |= solve(i, j+1, true);
	return ans;
}

int main() { _
	memset(dp, -1, sizeof(dp));
	cin >> s >> t;
	n = s.size(), m = t.size();
	bool ans = solve(0, 0, 0);
	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	exit(0);
}

