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
		int n, q; cin >> n >> q;
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		sort(v.begin(), v.end());
		vector<ll> pref(1);
		for(int i=0;i <n; i++) pref.pb(pref.back()+v[i]);

		set<ll> ans;
		function<void(int, int)> solve = [&](int l, int r){
			if(l>r) return;	
			ans.insert(pref[r+1]-pref[l]);
			if(l==r) return;	
			
			int m = (v[r]+v[l])/2;
			int up = upper_bound(v.begin(), v.end(), m) - v.begin();

			if(up!=l) solve(up, r);
			if(up-1!=r) solve(l, up-1);
		};
		solve(0, n-1);
		while(q--){
			ll a; cin >> a;
			if(ans.count(a)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
	
	
	
	exit(0);
}
