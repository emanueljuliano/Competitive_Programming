#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(n);
		map<int, vector<ll>> mp;
		for (int i=0; i<n; i++) cin >> v[i], mp[v[i]].push_back(0);
		for (int i=n-1; i+1; i--) mp[v[i]].push_back(n-i + mp[v[i]].back());
		
		ll ans = 0;
		for (int i=0;i <n; i++) {
			mp[v[i]].pop_back();
			ans += ll(i+1)*mp[v[i]].back();
		}

		cout << ans << endl;
	}
	
	
	
	exit(0);
}
