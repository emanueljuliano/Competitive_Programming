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

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<ii> v;
		ll tot = 0;
		for(int i=0;i <n; i++){
			ll a, b; cin >> a >> b;
			tot+=a;
			v.pb({a, b});
		}
		for(int i=0;i <n; i++){
			v[i].s = min(v[i].s, v[(i+1)%n].f);
		}
		ll mini = LINF, ind=0;
		for(int i=0;i <n; i++){
			if(v[i].s<mini) mini = v[i].s, ind=(i+1)%n;
		}	
		ll ans = 0;
		for(int j=0;j <n; j++){
			int it = (ind+j)%n;
			ans += v[it].f;
			v[it].f = 0;
			v[(it+1)%n].f -= v[it].s;
		}
//		for(int i=0;i <n;i ++){
	//		cout << v[i].f << " " << v[i].s << endl;
	//	}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
