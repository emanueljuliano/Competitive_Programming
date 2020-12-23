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

int E[11], D[110], S[110];
int dp[1<<(11)][110][110];
int t, p;

int solve(int msk, int pos, int cap){
	if(cap<0) return -INF;
	if(pos == p) return 0;

	int &ret = dp[msk][pos][cap];
	if(ret != -1) return ret;
	ret = 0;

	// skip currently problem
	ret = max(ret, solve(msk, pos+1, cap));

	// do the problem
	ret = max(ret, S[pos] + solve(msk, pos+1, cap-D[pos]));

	// skip currently person
	for(int i=0;i <t; i++) if(!(msk & (1<<i))) 
		ret = max(ret, solve(msk|(1<<i), pos, E[i]));

	return ret;
}

int main(){ _
	cin >> t >> p;
	for(int i=0;i <t; i++) cin >> E[i];
	for(int i=0;i <p; i++) cin >> D[i];
	for(int i=0;i <p; i++) cin >> S[i];
	
	memset(dp, -1, sizeof dp);

	cout << solve(0, 0, 0) << endl;
	
	exit(0);
}
