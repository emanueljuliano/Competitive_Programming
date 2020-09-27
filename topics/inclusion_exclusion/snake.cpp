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

vector<ii> v;
ll n, m , k;

ll qua(int x1, int x2, int y1, int y2){
	ll ret = 0;
		ll p1 = n-x2+1;
		ll p2 = m-y2+1;
		ll p3 = y1;
		ret = x1*p1*p2*p3;
	return ret;
}

ll solve(int x){
	int x1=n, x2=0, y1=m, y2=0;
	int at = 0;
	for(int i=0; i<k; i++){
		if(1<<i & x){
			at++;
			x1 = min(v[i].f, x1);
			x2 = max(v[i].f, x2);
			y1 = min(v[i].s, y1);
			y2 = max(v[i].s, y2);
		}
	}
	if(at%2) return -qua(x1, x2, y1, y2);
	else return qua(x1, x2, y1, y2);
}

int main(){ _
	int t; cin >> t;
	while(t--){
		v.resize(0);
		cin >> n >> m>>k;
		for(int i=0; i<k; i++){
			int a, b; cin >> a >> b;
			v.pb({a, b});
		}
		ll ans = 0;
		ans += (n+1)*n/2 * m*(m+1)/2;
		for(int i=1; i<1<<k; i++){
			ans += solve(i);
		}

		cout << ans << endl;

	}
	
	exit(0);
}
