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


int main(){ _
	int t; cin >> t;
	while(t--){
		ll n, w; cin >> n >> w;
		vector<pair<ll, int>> v;
		for(int i=0;i <n; i++){
			ll a; cin >> a; if(a>w) continue;
			v.pb({a, i});
		}
		n = v.size();
		ll sum = 0;
		for(auto a : v) sum+=a.f;
		if(sum<(w+1)/2){cout << -1 << endl; continue;}

		sort(v.begin(), v.end(), greater<>());

		vector<int> ans;
		ll at = 0;
		for(int i=0; i<n; i++){
			if(at + v[i].f > w) continue;
			at += v[i].f, ans.pb(v[i].s+1);
		}
		cout << ans.size() << endl;
		for(auto u : ans) cout << u << " ";
		cout << endl;
	}
	
	
	
	exit(0);
}
