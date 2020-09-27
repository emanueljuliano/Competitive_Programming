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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5+10;

vector<int> v;
int n, m;
int dp[MAX];

int solve(int p){
	if(p>=n) return 0;
	
	int &ret = dp[p];
	if(ret!=-1) return ret;
	ret = max(v[p]+solve(p+m), solve(p+1));
	return ret;
}

int main(){ _
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	v.resize(n);
	for(auto &i: v) cin >> i;
	
	cout << solve(m) << endl;
	
	
	
	exit(0);
}
