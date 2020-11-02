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


int main(){ _
	ll n, m, a, d; cin >> n >> m>> a >> d;
	vector<ll> ev;
	for(ll i=1;i <=n; i++) ev.pb(i*a);
	for(int i=0;i <m; i++){
		ll as; cin >> as;
		ev.pb(as);
	}
	sort(ev.begin(), ev.end());
//	for(auto u : ev) cout << u << " ";
//	cout <<endl;
	ll last = ev[0]+d;
	ll ans = 1;
	
	for(auto u : ev){
		if(u<=last) continue;
		last = u+d, ans++;
	}

	cout << ans << endl;
	
	
	
	exit(0);
}
