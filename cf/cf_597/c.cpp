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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9+7;
string s;
int n;
ll dp[(int)1e5+10];
ll solve(int i){
	if(i<n and (s[i]=='w' or s[i]=='m')) {cout << 0 << endl; exit(0);}
	if(i>=n-1) return dp[i] = 1;
	if(dp[i] != -1) return dp[i];
	if(s[i]=='u' and s[i+1]=='u') return dp[i] = (solve(i+1) + solve(i+2))%MOD;
	if(s[i]=='n' and s[i+1]=='n') return dp[i] = (solve(i+1) + solve(i+2))%MOD;
	return dp[i] = solve(i+1);
}

int main(){ _
	memset(dp, -1, sizeof dp);
	cin >> s;
	n = s.size();
	solve(0);
	cout << dp[0] << endl;
		
	exit(0);
}
