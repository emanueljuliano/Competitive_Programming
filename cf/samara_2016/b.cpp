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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool ord(ii a, ii b){
	return (a.f-a.s) < (b.f-b.s);
}

int main(){ _
	int n; cin >> n;
	vector<ii> v(n);
	for(auto &i : v) {
		ll a, b; cin >> a >> b;
		i = {a, b};
	}
	sort(v.begin(), v.end(), ord);
	ll x = v[0].f;
	for(int i=1; i<n; i++){
		x+= v[i].s;
		x = max(v[i].f, x);
	}
	cout << x << endl;	
	
	exit(0);
}
