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

	ll at = 0; 
	for(auto u : v) at = max(at, u);
	
	ll ans = 0;
	while(at<=tot){
		ll maxi = 0;
		for(auto u : v) if(u==at) maxi++;
		maxi = maxi/2;
		for(auto &u : v){
			if(u != at) u++;
			else if(maxi) maxi--, u++;
		} 
		for(auto u : v) at = max(at, u);
		ans++;
	}
	cout << max(ans-1, 0LL) << endl;
	
	
	exit(0);
}
