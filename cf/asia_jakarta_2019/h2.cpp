#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;
typedef double ld;

const ll INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ld eps = 1e-4;
int main(){ _
	ll n; cin >> n;
	ld ans = 0;
	vector<ii> v(n);
	for(auto &i : v) cin >> i.f >> i.s, ans=max(ans, (ld)i.f/2.0*i.s);
	for(ll i=0;i <n; i++) for(ll j=i+1; j<n; j++){
		ans = max(ans, (ld)min(v[i].f, v[j].f)*min(v[i].s, v[j].s));
		ans = max(ans, (ld)min(v[i].f, v[j].s)*min(v[i].s, v[j].f));
	}
	cout << setprecision(1) << fixed;
	cout << ans << endl;
	
	exit(0);
}
