#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 1e14;

vector<ll> v;
vector<ii> w;
ll n, k;
ll dp[(int)2e3+10];

ll solve(int pos){
	if(pos==n) return 0;
	ll &res = dp[pos];
	if(res != -1) return res;
	res = LINF;
	ll at = k, spent=0, at2=0;
	for(int i=pos; i<n; i++){
		if(v[i]>at+k*(w[i].s-w[i].f)) return res;
		spent+=v[i], at2 = (2*k-spent%k)%k;
		if(i==n-1) break; 
		else if(w[i+1].f==w[i].s and v[i]>at+k*(w[i].s-w[i].f-1)) at = at2;
		else res = min(res, spent+at2+solve(i+1)), at = at2 + (!at2)*k;
	}
	res = min(res, spent);
	return res;
}

int main(){ _
	memset(dp, -1, sizeof dp);
	cin >> n >> k;
	for(int i=0;i <n; i++){
		int a, b, c; cin >> a >> b >> c;
		w.pb({a, b}), v.pb(c);
	}

	ll ans = solve(0);
	if(ans >= LINF) cout << -1 << endl;
	else cout << ans << endl;
	
	
	exit(0);
}
