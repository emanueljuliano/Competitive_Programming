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

const int MAX = 505;
int dp[2][MAX][MAX];

int main(){ _
	int n, m, b, MOD;
	vector<int> v;
	cin >> n >> m >> b >> MOD;
	v.resize(n);
	for(auto &i : v) cin >> i;

	for(int k=0; k<=b; k++)   dp[1][0][k] = 1;
	for(int i=0;i <n; i++) for(int j=0; j<=m; j++) for(int k=0; k<=b; k++){
		dp[i%2][j][k] = dp[(i%2)^1][j][k];
		if(j and v[i]<=k) dp[i%2][j][k] += dp[i%2][j-1][k-v[i]];
		dp[i%2][j][k]%=MOD;
	}

	cout << dp[(n-1)%2][m][b] << endl;
	
	
	exit(0);
}
