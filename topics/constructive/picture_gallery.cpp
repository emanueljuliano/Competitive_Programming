#include <bits/stdc++.h>

using namespace std;

#define debbuging true
#define debug if(debbuging) cout
#define _ if(!debbuging) ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int n, m; cin >> n >> m;
	int tot = 0;
	vector<int> f(m);
	for(auto &i : f) cin >> i, i=min(i, n/2), tot+=i;
	
	if(tot<n) return cout << -1 << endl, 0;

	set<ii> st;
	for(int i=0;i <m; i++) st.insert({f[i], i});
	vector<int> ans;
	while(true){
		auto [a1, a] = *st.rbegin(); st.erase({a1, a});
		ans.pb(a+1), f[a]--;
		if(ans.size()==n) break;

		auto [b1, b] = *st.rbegin(); st.erase({b1, b});
		ans.pb(b+1), f[b]--;
		if(ans.size()==n) break;
		
		if(f[a]) st.insert({f[a], a});
		if(f[b]) st.insert({f[b], b});
	}
	//assert(ans.size()==n);
	if(ans.back()==ans[0]){
		for(int i=0; i<m; i++) if(f[i] and i+1!=ans[0] and i+1!=ans[n-2]){ans[n-1]=i+1; break;}
		if(ans.back() == ans[0]){
			for(int i=0;i <n-1; i++) if(ans[i]!=ans[0] and ans[i+1]!=ans[0]){
				vector<int> ans2;
				for(int j=0; j<=i; j++) ans2.pb(ans[j]);
				ans2.pb(ans[0]);
				for(int j=i+1; j<n-1; j++) ans2.pb(ans[j]);
				ans = ans2;
				break;
			}
		}
	}
	for(auto u : ans) cout << u << " ";
	cout << endl;


	exit(0);
}
