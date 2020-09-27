#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 1e9+7;
ll dp[(int)2e6+10];

// a = F(i-1) + 2*F(i-2)
// b = 4 + F(i-2) + 4*F(i-3) + 4*F(i-4)


int main(){ _
	for(int i=0; i<(int)2e6+5; i++) dp[i] = -1;
	dp[0] = 0; dp[1] = 0; dp[2] = 0; dp[3] = 4; dp[4] = 4; dp[5] = 12;
	for(int i=6; i<(int)2e6+5; i++){
		dp[i] = 2*dp[i-1]%MOD; i++;
		dp[i] = 2*dp[i-1]%MOD; i++;
		dp[i] = 2*dp[i-1]%MOD; i++;
		dp[i] = (2*dp[i-1]+4)%MOD; i++;
		dp[i] = (2*dp[i-1]-4)%MOD; i++;
		dp[i] = (2*dp[i-1]+4)%MOD;
	}
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cout << dp[n] << endl;
	}
	
	
	
	exit(0);
}
