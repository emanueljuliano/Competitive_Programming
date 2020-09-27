#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 1e7;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+10;
ll n, m, x, y;
vector<ll> v;
ll dp[MAX][5];

ll solve(int at, int p){
	if(at >= v.size()-1) return 0;
	if(v[at]+x>=m) return 1;
	if(!p and v[at]+y>=m) return 1;

	ll &ret = dp[at][p];
	if(ret != -1) return ret;
	ret = INF;

	int x1;
	x1 = upper_bound(v.begin(), v.end(), v[at]+x) - v.begin();
	x1--;
	if(x1>at) ret = min(ret, solve(x1, 0)+1);
	if(p) return ret;

	int y1, y2;
	y1 = upper_bound(v.begin(), v.end(), v[at]+y) - v.begin();
	y1--;
	y2 = y1-1;

	if(y1>at) ret = min(ret, solve(y1, 1)+1);
	if(y2>at) ret = min(ret, solve(y2, 1)+1);
	return ret;
}

int main(){ _
	cin >> n >> m;	
	for(int i=0;i <=n+5; i++)
		dp[i][0] = -1, dp[i][1] = -1;

	v.pb(1);
	for(int i=0;i <n; i++){
		ll a; cin >> a;
		v.pb(a);
	}
	v.pb(m);
	cin >> x >> y;
	
	ll ans = solve(0, 0);
	if(ans < INF) cout << ans << endl;
	else cout << -1 << endl;
	
	exit(0);
}
