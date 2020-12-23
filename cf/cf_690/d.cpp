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
		vector<int> pref;
		pref.pb(0);
		for(auto &i:v) cin >> i, pref.pb(pref.back()+i);

		int ans = -1;
		for(int i=1; i<pref.size(); i++){
			int at = pref[i];
			if(pref.back()%at) continue;
			bool show = true;
			for(int j=2; j<=pref.back()/at; j++){
				int lo = lower_bound(pref.begin(), pref.end(), j*at) - pref.begin();
				if(pref[lo] != j*at) {show = false; break;}
			}
			if(show) {ans = n-pref.back()/at; break;}
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
