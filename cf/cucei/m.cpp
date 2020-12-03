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
	ll n, m; cin >> n >> m;
	vector<pair<ll, ll>> div;
	for(ll i=2; i*i<=m; i++) if(m%i==0){
		div.pb({i, 0});
		while(m%i==0) m/=i, div.back().s++;
	}
	if(m!=1) div.pb({m, 1});	
	ll ans = 1;
	for(auto [a, b] : div) if(b>=n) ans*=pow(a, b/n);
	cout << ans << endl;
	
	exit(0);
}
