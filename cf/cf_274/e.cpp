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

const int MAX = 5e3+10;
ll dp[MAX][MAX];
ll pref[MAX];

int main(){ _
	
	int n, a, b, k; cin >> n >> a >> b >> k;

	for(int i=1;i <=n; i++) if(i!=b) dp[i][0] = 1;
	
	for(int j=1; j<=k; j++){
		for(int i=1; i<=n; i++) pref[i] = (pref[i-1]+dp[i][j-1])%MOD;

		for(int i=1; i<=n; i++) if(i!=b){
			int r = min(i+abs(i-b)-1, n);
			int l = max(i-abs(i-b)+1, 1);
			dp[i][j] = pref[r] - pref[l-1] - dp[i][j-1];
			dp[i][j] = (dp[i][j]%MOD+MOD)%MOD;
		}
	}

/*	for(int i=0; i<=k; i++) {
		for(int j=1; j<=n; j++) cout << dp[j][i] << " ";
		cout << endl;
	}
*/	
	cout << dp[a][k] << endl;
		
	
	
	exit(0);
}
