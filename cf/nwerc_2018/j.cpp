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


int main(){ _
	int n; cin >> n;

	ll tot; cin >> tot;
	vector<ll> v(n-1);
	for(auto &u : v) cin >> u;

	ll at = 0, maxi = 0, ans =0;
	for(auto u : v) at = max(at, u);
	if(tot < maxi) return cout << 0 << endl, 0;

	map<ll, int> mp;
	for(auto u : v){
		mp[tot-u]++;
	}
	vector<pair<ll, int>> dist;
	for(auto u : mp) dist.pb(u);

	tot = dist[0].f;
	int it = 0;
	while(true){
		ll t = dist[it].s;
		ll passos = (int)log2(t) + 1;
		if(it!=dist.size()-1){
			ll d = dist[it+1].f - dist[it].f;
			ll perc = passos*d;
			
			if(perc - d > tot){
				ll ds = tot/(passos-1);
				ans += passos*ds;
				tot -= (passos -1) * ds;
				ans += tot;
				break;
			}

			ans += perc;
			dist[it+1].s += dist[it].s;
			tot -= perc - d; 
			it++;
		}
		else{
			ll ds = tot/(passos-1);
			ans += passos*ds;
			tot -= (passos -1) * ds;
			ans += tot;
			break;
		}
	}
	cout << ans << endl;
	
	
	exit(0);
}
