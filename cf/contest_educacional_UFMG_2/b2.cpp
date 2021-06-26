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

const int MAX = 1e5+10;
ll dp[MAX][3]; // indice, fileira
int n;
vector<int> v[2];

ll solve(int id, int fi){
	if(id==n) return 0;
	ll &ret = dp[id][fi];

	if(ret != -1) return ret;
	
	ret = v[!fi][id] + solve(id+1, !fi);
	ret = max(ret, solve(id+1, fi));
	return ret;
}

int main(){ _
	memset(dp, -1, sizeof dp);
	cin >> n;
	v[0].resize(n), v[1].resize(n);

	for(auto &i : v[0]) cin >> i;
	for(auto &i : v[1]) cin >> i;
	
	ll ans = 0;
	ans = max(ans, v[0][0] + solve(1, 0));
	ans = max(ans, v[1][0] + solve(1, 1));

	cout << ans << endl;
	
	exit(0);
}
