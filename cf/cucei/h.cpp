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

const int MOD = 1e9+7;
const int MAX = 1e4+10;
int dp[MAX][MAX];
int pref[MAX][MAX];

int main(){ _
	for(int i=0; i<MAX; i++) dp[i][0] = 1;
	for(int i=1;i<MAX; i++) for(int j=1; j<=i; j++)
		dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
	for(int i=1; i<MAX; i++) for(int j=1; j<=i; j++)
		pref[i][j] = (pref[i][j-1] + dp[i][j])%MOD;
	
	int t; cin >> t;
	while(t--){
		int n, a, b;
		cin >> n >> a >> b;
		if(a>n) {cout << 0 << endl; continue;}
		b = min(b, n);
		cout << (pref[n][b] - pref[n][a-1] + MOD)%MOD << endl;
	}
	
	
	exit(0);
}
