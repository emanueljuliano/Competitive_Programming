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
	ll n, k; cin >> n>> k;
	vector<ii> v;
	ll r=0, b=0;
	for(int i=0;i <n; i++){
		int x, y; cin >> x >> y;
		r+=x;b+=y;
		v.pb({x, y});
	}
	ll R = r/k;
	ll B = b/k;
	ll ans = R + B;
	ll fb = b - B*k;
	ll fr = r - R*k;
	if(fr+fb >= k) for(int i=0;i <n; i++) if(v[i].f + v[i].s >= k){
		if(k-v[i].f <= fb){
			ans++; break;
		}
		if(k-v[i].s <= fr){
			ans++; break;
		}

	}
	cout << ans << endl;

	
	exit(0);
}
