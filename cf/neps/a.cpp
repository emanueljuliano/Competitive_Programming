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
	vector<ll> v;
	for(int i=0;i <n; i++){
		ll a; cin >> a;
		v.pb(a);
	}
	sort(v.begin(), v.end());
	n = v.size();
	ll ans = -LINF;
	ll at = v[0]*v[1];
	for(int i=2; i<n; i++){
		ans = max(ans, at*v[i]);
	}
	at = v[n-1]*v[n-2];
	for(int i=0;i <n-2; i++){
		ans = max(ans, v[i]*at);
	}
	for(int i=0;i <n-2; i++){
		ans = max(ans, v[i]*v[i+1]*v[i+2]);
	}
	ans = max(ans, v[n-3]*v[n-2]*v[n-1]);
	ans = max(ans, v[0]*v[1]*v[n-1]);
	cout << ans << endl;
	
	
	
	exit(0);
}
