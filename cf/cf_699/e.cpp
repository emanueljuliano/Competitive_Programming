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


vector<int> v;
vector<vector<int>> pos;
vector<int> sz;
int n = 0;
int dp[(int)5e5+10];

int solve(int at){
	int &ret = dp[at];
	if(ret != -1) return ret;
	if(at==n) return ret = 0;
	ret = solve(at+1);
	int lo = lower_bound(pos[v[at]].begin(), pos[v[at]].end(), at) - pos[v[at]].begin();
	ret = max(ret, sz[v[at]]-lo);
	if(at == pos[v[at]][0]) ret = max(ret, sz[v[at]] + solve(pos[v[at]].back()+1));
	return ret;
}

int main(){ _
	memset(dp, -1, sizeof dp);
	cin >> n;
	v.resize(n), pos.resize(n+10), sz.resize(n+10);
	for(auto &i : v) cin >> i, sz[i]++;
	for(int i=0;i <n; i++) pos[v[i]].pb(i);

	int ans = 0;
	ans = solve(0);
	
	cout << n-ans << endl;
		
	
	exit(0);
}
