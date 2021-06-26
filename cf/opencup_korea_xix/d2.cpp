#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n, m; cin >> n >> m;

	map<int, pair<int, int>> mp;
	for (int i=0; i<n; i++) {
		int l, r; cin >> l >> r; l--, r--;
		mp[i] = {l, r};
	}
	vector<pair<int, int>> w;
	for (int i=0; i<m; i++) {
		int a, b; cin >> a >> b; a--, b--;
		w.push_back({a, b});
	}

	vector<int> v(n);
	iota(v.begin(), v.end(), 0);

	do{
		bool show = true;
		vector<int> pos(n);
		for(int i=0; i<n; i++){
			pos[v[i]] = i;
			auto [l, r] = mp[v[i]];
			if(l <= i and i <= r) {}
			else show = false;
		}
		for(auto [a, b] : w){
			if(pos[a]>pos[b]) show = false;
		}
		if(show){
			//for(auto u : v) cout << u+1 << endl;
			cout <<1  << endl;
			exit(0);
		}
	}while(next_permutation(v.begin(), v.end()));

	cout << -1 << endl;
	
	exit(0);
}
