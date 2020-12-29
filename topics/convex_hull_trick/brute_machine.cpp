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

struct machine{
	ll d, p, r, g;
	ll prev=0;
	bool operator < (const machine m) const{
		return g<m.g;
	}
	ll cost (ll x){
		return  prev + g*(x-d);
	}
};

int main(){ _
	
	int tc = 1;
	ll n, c, d;
	while(true){
		cin >> n >> c >> d;
		if(!n) return 0;

		vector<machine> v(n);
		for(auto &i : v) cin >> i.d >> i.p >> i.r >> i.g;

		sort(v.begin(), v.end(), [](machine a, machine b){return a.d<b.d;});
		
		vector<machine> w;
		ll ans = c;
		for(int i=0;i <n; i++){
			//cout << "IT " << i << " ans " << ans << endl;
			//for(auto u : w) cout<< u.d << " " << u.g << " " << u.prev << endl;	
			//cout << endl;
			for(auto m : w) ans = max(ans, m.cost(v[i].d-1));
			v[i].prev = ans - v[i].p + v[i].r;


			//cout << ans << " bigger?" << endl;
			//cout << endl;
			if(v[i].p > ans) continue;
			w.pb(v[i]);
		}
		for(auto m : w){
			//cout << m.d << " " << m.cost(d) << endl;
			ans = max(ans, m.cost(d));
		}
		cout << "Case " << tc++ << ": " << ans << endl;
	}
	
	
	
	exit(0);
}
