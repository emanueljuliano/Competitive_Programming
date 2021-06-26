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
		unordered_map<int, int> mp;
		vector<vector<int>> w(n);
		int pt = 0;
		for(int i=0;i <n; i++){
			cin >> v[i];
			if(!mp.count(v[i])) mp[v[i]] = pt++;
			w[mp[v[i]]].pb(i);
		}

		ll ans = 0;
		for(int i=0;i <n; i++) for(int j=i+1; j<n; j++){
			int dif = v[j]-v[i];
			int at = v[j]+dif;
			if(mp.count(at)){
				int id = mp[at];
				int up = upper_bound(w[id].begin(), w[id].end(), j) - w[id].begin();
				ans += w[id].size() - up;
			}
		}
		cout << ans << endl;
	}
		
	
	
	exit(0);
}
