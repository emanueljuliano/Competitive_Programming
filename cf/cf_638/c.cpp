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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		string s; cin >> s;
		sort(s.begin(), s.end());
		int it = 0;
		vector<string> ans(k);
		char mini = s[0];
		set<char> st;
		for(int i=0;i <n; i++){
			st.insert(s[i]);	
		}
		if(st.size()!=1 and (st.size()>2 or k==n or s[k-1]!=mini or s[k]==mini)){
			for(int i=0;i <n; i++){
				if(it<k and ans[it].empty()){
					ans[it].pb(s[i]);
					it++;
				}
				else{
					ans[0].pb(s[i]);
				}
			}
		}
		else{
			for(int i=0;i <n; i++){
				ans[i%k].pb(s[i]);
			}
		}
		if(ans[0]>ans[k-1]) cout << ans[0] << endl;
		else cout << ans[k-1] << endl;
	}
	
	
	
	exit(0);
}
