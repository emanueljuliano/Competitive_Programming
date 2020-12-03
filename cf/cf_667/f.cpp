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

const int MAX = 220;
int dp[MAX][MAX][MAX]; // mudei, pos -> numbero de abs
string s, t;
int n, k;

int solve(int mudei, int b, int pos){
	if(mudei>k or b<0) return -INF;
	if(pos==n and b) return -INF;
	if(pos==n) return 0;

	int &res = dp[mudei][b][pos];
	if(res != -1) return res;
	
	res = solve(mudei, b-(s[pos]==t[1]), pos+1) + (s[pos]==t[0])*b;
	res = max(res, solve(mudei+1, b-1, pos+1));
	res = max(res, solve(mudei+1, b, pos+1) + b);
	return res;
}

int main(){ _
	cin >> n >> k;
	cin >> s >> t;
	if(t[0]==t[1]){
		int tot = 0;
		for(auto u : s) if(u==t[0]) tot++;
		tot += k;
		tot = min(tot, n);
		return cout << tot*(tot-1)/2 << endl, 0;
	}
	memset(dp, -1, sizeof dp);
	int ans = 0;
	for(int i=0;i <=n; i++) ans = max(ans, solve(0, i, 0));
	cout << ans << endl;
	
	exit(0);
}
