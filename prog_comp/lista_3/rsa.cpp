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

ll fexp(ll a, ll b, ll m){
	if(!b) return 1;
	if(b%2) return (a*fexp(a, b-1, m)%m);
	return (fexp(a*a%m, b/2, m)%m);
}
tuple<ll, ll> euler(ll a, ll b){
	if(!b) return {1, 0};
	auto [x, y] = euler(b, a%b);
	return {y, x-a/b*y};
}

int main(){ _
	ll n, e, c; cin >> n >> e >> c;
	int phi=0;
	for(int i=2; i*i<=n; i++) if(n%i==0) {phi = (i-1)*(n/i-1); break;}
	
	auto [x, y] = euler(e, phi);
	ll ans =  fexp(c, (x+phi)%phi, n);
	cout << ans << endl;
	exit(0);
}
