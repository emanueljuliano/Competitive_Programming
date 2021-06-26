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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		ll n, m; cin >> n >> m;
		ll tot =0;
		vector<int> a(n), b(n);
		for(auto &i : a) cin >> i, tot+=i;
		for(auto &i : b) cin >> i;
		
		if(tot<m) {cout << -1 << endl; continue;}
		vector<int> v, w;
		for(int i=0;i <n; i++){
			if(b[i]==2) w.pb(a[i]);
			else v.pb(a[i]);
		}

		sort(v.begin(), v.end(), greater<>());
		sort(w.begin(), w.end(), greater<>());

		vector<ll> prefv; prefv.pb(0);
		for(auto u : v) prefv.pb(prefv.back() + u);
		vector<ll> prefw; prefw.pb(0);
		for(auto u : w) prefw.pb(prefw.back() + u);

		int ans =INF;
		for(int i=0;i <prefw.size(); i++){
			ll need = m-prefw[i];
			int lo = lower_bound(prefv.begin(), prefv.end(), need) - prefv.begin();
			if(lo==prefv.size()) continue;

			ans = min(ans, 2*i+lo);
		}
		cout << ans << endl;
	}	
	exit(0);
}
