#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		set<pair<int, int>> st;
		map<int, int> mp;
		for(int i=0;i <n; i++){
			int a; cin >> a;
			if(!st.count({mp[a], a}))
				st.insert({++mp[a], a});
			else st.erase({mp[a], a}), st.insert({++mp[a], a});
		}
		int ans = n;
		while(st.size()>1){
			auto [c, a] = *st.rbegin(); st.erase({c, a});
			mp[a]--;
			auto [c2, a2] = *st.rbegin(); st.erase({c2, a2});
			mp[a2]--;
			ans -= 2;
			if(mp[a]) st.insert({mp[a], a});
			if(mp[a2]) st.insert({mp[a2], a2});
		}
		
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
