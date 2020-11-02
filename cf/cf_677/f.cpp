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

int dp[72][72][40][72];
int dp1[72][72][40];

int M[72][72];
int n, m, k;

int solve1(int i, int j, int num){
	if(num > m/2) return -INF;
	if(j==m) return solve1(i+1, 0, 0);
	if(i==n) return 0;
	if(dp1[i][j][num] != -1) return dp1[i][j][num];
	return dp1[i][j][num] = max(solve1(i, j+1, num), M[i][j]+solve1(i, j+1, num+1));
}

bool solve(int i, int j, int num, int cap){
	if(num > m/2) return false;
	if(cap==0) return true;
	if(cap<0) return false;
	if(i==n) return false;
	if(j==m) return solve(i+1, 0, 0, cap);
	if(dp[i][j][num][cap] != -1) return dp[i][j][num][cap];
	return (dp[i][j][num][cap] = (solve(i, j+1, num, cap) or solve(i, j+1, num+1, cap-M[i][j])));
}


int main(){ _
	
	cin >> n >> m >> k;
	for(int i=0;i <n; i++) for(int j=0; j<m; j++) cin >> M[i][j];
	memset(dp1, -1, sizeof dp1);
	int maxi = solve1(0, 0, 0);
	for(int i=maxi/k*k; i+1; i-=k){
		memset(dp, -1, sizeof dp);
		if(solve(0, 0, 0, i))
			return cout << i << endl, 0;
	}
	exit(0);
}
