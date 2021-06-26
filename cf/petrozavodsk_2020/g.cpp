#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

ll sarea2(pair<int, int> p, pair<int, int> q, pair<int, int> r){
	pair<int, int> p1 = {q.first-p.first, q.second-p.second};
	pair<int, int> p2 = {r.first-q.first, r.second-q.second};
	return p1.first*(ll)p2.second - p1.second*(ll)p2.first;
}

bool ccw(pair<int, int> p, pair<int, int> q, pair<int, int> r){
	return sarea2(p, q, r) > 0;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<pair<int, int>> v(n), w(n);
		for(int i=0;i <n; i++) cin >> v[i].first >> v[i].second;
		for(int i=0;i <n; i++) cin >> w[i].first >> w[i].second;

		sort(v.begin(), v.end());
		vector<vector<pair<int, int>>> ans(n);
		do{
			for(int i=0;i <n; i++) ans[i].clear();
			for(int i=0;i <n; i++){
				ans[i].push_back(w[i]);
				ans[i].push_back({w[i].first, v[i].second});
				ans[i].push_back({v[i].first, v[i].second});
			}

			bool show = true;
			for(int i=0; i<n; i++) for(int j=i+1; j <n; j++){
				if(ccw(ans[i][0], ans[i][1], ans[j][1]) != ccw(ans[i][0], ans[i][1], ans[j][2])
				and ccw(ans[j][1], ans[j][2], ans[i][0]) != ccw(ans[j][1], ans[j][2], ans[i][1]))
					show = false;
				if(ccw(ans[i][1], ans[i][2], ans[j][0]) != ccw(ans[i][1], ans[i][2], ans[j][1])
				and ccw(ans[j][0], ans[j][1], ans[i][1]) != ccw(ans[j][0], ans[j][1], ans[i][2]))
					show = false;
			}
			if(show) break;
		}while(next_permutation(v.begin(), v.end()));
		for(int i=0;i <n; i++){
			cout << ans[i].size() << endl;
			for(auto [x, y] : ans[i]) cout << x << " " << y << endl;
		}
	}
	
	
	
	exit(0);
}
