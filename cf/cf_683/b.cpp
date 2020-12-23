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

const int MAX = 5e3+10;

int dp[MAX][MAX];

string s, t;
int solve(int i, int j){
	if(i<0 or j<0) return 0;
	int &res = dp[i][j];
	if(res != -1) return res;
	res = 0;
	if(s[i]==t[j]) res = max(res, 2 + solve(i-1, j-1));
	res = max(res, max(solve(i-1, j), solve(i, j-1)) - 1);
	return res;
}

int main(){
	memset(dp, -1, sizeof dp);
	int n, m; cin >> n >> m;
	cin >> s >> t;
	int ans = 0;
	solve(n-1, m-1);
	for(int i=0;i <n; i++) for(int j=0;j<m; j++) ans = max(ans, dp[i][j]);
	cout << ans << endl;

	exit(0);
}
