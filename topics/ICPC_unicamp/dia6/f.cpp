#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back

typedef long long ll;

double dp[440][440];
int n;

double rec(int m, int k){
	if(k==0.0) return dp[m][k] = n-m;
	if(m==0.0) return dp[m][k] = (n-1.0) + 0.5;
	if(dp[m][k]!=-1.0) return dp[m][k];
	return dp[m][k] =  0.5*rec(m-1, k-1) + 0.5*rec(m, k-1);
}

int main(){ _
	int k;
	for(int i=0; i<440; i++)for(int j=0; j<440; j++) dp[i][j] = -1.0;
	cin >> n >> k;
	cout << setprecision(6) << fixed;
	cout << rec(n, k) << endl;
	exit(0);
}
