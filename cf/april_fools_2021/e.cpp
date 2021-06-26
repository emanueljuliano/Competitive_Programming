#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

char M[9][9];
int dp[9][9];
int n, m;
int solve(int i, int j){
	if(i>=n or j>=m) return 0;
	int &ret = dp[i][j];
	if(ret != -1) return ret;
	ret = M[i][j] == '*';
	if(i==n-1 and j==m-1) return ret;

	if(i+1<n and j+1<m and M[i][j+1]=='*' and M[i+1][j]=='*') 
		return ret = ret + max(solve(i, j+1), solve(i+1, j));

	if(i+1<n and M[i+1][j]=='*') 
		return ret = ret + solve(i+1, j);
	if(j+1<m and M[i][j+1]=='*') 
		return ret = ret + solve(i, j+1);
	if(i==0 and j+1<m) return ret = ret + solve(i, j+1);
	return ret = ret + max(solve(i, j+1), solve(i+1, j));
}

int main(){ _
	cin >> n >> m;
	for(int i=0;i <n; i++) for(int j=0; j<m; j++) cin >> M[i][j];

	memset(dp, -1, sizeof dp);
	cout << solve(0, 0) << endl;	
	
	exit(0);
}
