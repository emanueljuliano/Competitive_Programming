#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int tc; cin >> tc;
	while(tc--){
		int n, m; cin >> n >> m;
		vector<pair<int, int>> v, w;
		for(int i=0;i <n; i++){
			int t, h; cin >> t >> h;
			h = min(h, m);
			if(h>=t) v.push_back({t, h});
			else w.push_back({t, h});
		}

		sort(v.begin(), v.end());
		sort(w.begin(), w.end(), [&](pair<int, int> a, pair<int, int> b){
			if(a.second != b.second) return a.second > b.second;
			return a.first < b.first;
		});
		
		bool show = true;
		ll H = m;
		for(auto [a, b] : v) {
			if(H<a) show = false;
			else H-=a-b;
		}
		for(auto [a, b] : w) {
			if(H<a) show = false;
			else H-=a-b;
		}
		
		if(show) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	exit(0);
}
