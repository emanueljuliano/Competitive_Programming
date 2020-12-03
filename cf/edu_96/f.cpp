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

map<ii, ll> mp;

vector<ll> v;
vector<ii> w;
ll n, k;
ll solve(int pos, int bul){
	if(pos==n) return 0;
	if((w[pos].s-w[pos].f)*k+bul < v[pos]) return LINF;
	
	ii est = {pos, bul};
	if(mp.count(est)) return mp[est];
	
	ll sobra =  ((bul-v[pos])%k+k)%k;
	ll res = v[pos] + solve(pos+1, sobra);
	if(pos != n-1 and w[pos+1].f > w[pos].s) 
		res = min(res, v[pos] + sobra + solve(pos+1, k));
	else if(pos!=n-1 and bul + (w[pos].s-w[pos].f-1)*k >=v[pos]) 
		res = min(res, v[pos] + sobra + solve(pos+1, k));
		
	mp[est] = res;
	return res;
}

int main(){ _
	cin >> n >> k;
	for(int i=0;i <n; i++){
		int a, b, c; cin >> a >> b >> c;
		w.pb({a, b}), v.pb(c);
	}

	ll ans = solve(0, k);
	if(ans >= LINF) cout << -1 << endl;
	else cout << ans << endl;
	
	
	exit(0);
}
