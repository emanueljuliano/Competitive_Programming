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
		int n; cin >> n;
		vector<int> v(n);
		
		vector<vector<int>> pos(n+1);
		for(int i=0;i <n; i++) cin >> v[i], pos[v[i]].pb(i);
		
		set<int> st;
		vector<int> ap(n+1);
		for(int i=1;i<=n; i++){
			int mx = 0;
			if(st.size()) for(auto u : pos[i]){
				auto it = st.lower_bound(u);
				if(it==st.begin() and it!=st.end()) mx = max(mx, *it);
				else if(it==st.end() and it!=st.begin()) {
					it--;
					mx = max(mx, n-1-*it);
				}
				else {
					int at = *it; it--;
					mx = max(mx, at-*it-1);
				}
			}
			if(!st.size() and pos[i].size()) mx = n; 
			for(auto u : pos[i]) st.insert(u);
			ap[i] = mx;
		}

		vector<int> ans(n);
		int time = 0;
		for(int i=1; i<=n; i++){
			time = max(time, n+1-ap[i]);
			ans[n-i] = time<=i;
		}
		for(auto u : ans) cout <<u;
		cout << endl;
	}
	
	
	
	exit(0);
}
