#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back
#define ss second
#define ff first

typedef pair<int, int> pii;
typedef long long ll;

int lis(vector<pair<ll, int>> &v){
	vector<int> ans;
	for(auto t : v){
		auto it = lower_bound(ans.begin(), ans.end(), t.ss);
		if(it==ans.end()) ans.pb(t.ss);
		else *it = t.ss;
	}
	return ans.size();
}

int main(){ _
	ll x, y;
	int c;
	cin >> x >> y;
	pii tv = {x, y};

	map<pii, vector<pair<ll, int>>> curvas;

	int n; cin>>n;
	for(int i=0; i<n; i++){
		int sin = -1;
		pii ind;
		ll dist;
		cin >> x >> y >> c;
		x-= tv.ff;
		y -= tv.ss;

		if(!x){
			if(y>0) sin = 1;
			ind = {0, sin};
		}
		else if(!y){
			if(x>0) sin = 1;
			ind = {sin, 0};
		}
		else{
			int g = __gcd(x, y);
			ind = {x/abs(g), y/abs(g)};
		}
		
		dist = x*x + y*y;
		curvas[ind].pb({dist, c});
	}

	int ans = 0;
	for(auto it : curvas){
		sort(it.ss.begin(), it.ss.end());
		ans += lis(it.ss);
	}

	cout << ans << endl;

	exit(0);
}
