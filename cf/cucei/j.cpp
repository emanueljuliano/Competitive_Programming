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
int dp[MAX][12][12];
int n, k, m;

int solve(int sz, int color, int used){
	if(used>m) return 0;
	if(sz==n) return 1;
	int &ret = dp[sz][color][used];
	if(ret != -1) return ret;
	ret = 0;
	for(int i=1; i<=k; i++){
		if(i==color) ret = (ret + solve(sz+1, color, used+1))%MOD;
		else ret = (ret + solve(sz+1, i, 1))%MOD;
	}
	return ret;
}

int main(){ _
	memset(dp, -1, sizeof dp);

	cin >> n >> k >> m;
	cout << solve(0, 0, 0) << endl;	
	
	
	exit(0);
}
