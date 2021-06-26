#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 5005;
const int MAXK = 30;

bool dp[MAX][MAXK];

int main() { _

	int n;
	cin >> n;

	string s;
	cin >> s;

	int m = s.size();

	memset(dp, 0, sizeof dp);
	for (int i = 0; i < n; i++)
		dp[0][i] = 1;

	for (int i = 0; i < m; i++) {
		for (int x = 0; x < n; x++) {
			if (!dp[i][x]) continue;
			if (s[i] == '=') dp[i+1][x] = 1;
			else if (s[i] == '<') 
				for (int y = x + 1; y < n; y++) 
					dp[i+1][y] = 1;
			else 
				for (int y = x - 1; y >= 0; y--) 
					dp[i+1][y] = 1;
		}
	}

	int st = -1;
	for (int i = 0; i < n; i++) {
		if (dp[m][i]) {
			st = i;
			break;
		}
	}

	if (st == -1) {
		cout << st << endl;
		return 0;
	}

	int at = m;
	string ans;
	ans.push_back('a'+st);
	
	//cout << ans << endl << endl;
	
	while (at > 0) {
		int nxt = 0;
		if (s[at - 1] == '<') {
			for (int i = st - 1; i >= 0; i--) {
				if (dp[at - 1][i]) {
					nxt = i;
					break;
				}
			}
		}
		else if (s[at - 1] == '>') {
			for (int i = st + 1; i < n; i++) {
				if (dp[at - 1][i]) {
					nxt = i;
					break;
				}
			}
		}
		else nxt = st;

    cout << ans << " " << nxt << endl;
		ans += ('a' + nxt);
		at -= 1;
		cout << ans << endl;
	}

	reverse(ans.begin(), ans.end());
	cout << ans << endl;

	exit(0);
}
