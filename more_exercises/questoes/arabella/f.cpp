#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define pb push_back
#define s second
#define f first

typedef pair<int, int> ii;
typedef long long ll;

int ma[(int)1e5+10];
int main(){ _
	int t; cin >> t;
	memset(ma, 0, sizeof(ma));
	while(t--){
		int n, m; cin >> n >> m;
		
		vector<int> jo;
		vector<vector<pair<int, int>>> ev(n+10);
		for(int i=0; i<m; i++){
			int x, l, k;
			cin >> x >> l >> k;
			jo.pb(l);
			ev[max(1, x-k)].pb({0, i});
			ev[min(n, x+k)].pb({1, i});
		}
		for(int i=1; i<=n;i++)if(ev[i].size()>1) sort(ev[i].begin(), ev[i].end());
		
		int ans = 0;
		set<int> se;
		for(int i=1; i<=n; i++){
			bool flag = true;
			if(ev[i].empty()){
				if(se.empty()) ans++;
				else if(ma[jo[*se.rbegin()]]>1) ans++;
				continue;
			}

			for(auto p : ev[i]){
				if(p.f==0){
					ma[jo[p.s]]++;
					se.insert(p.s);
				}
				else{
					if(flag){
						if(ma[jo[*se.rbegin()]]>1) ans++;
						flag = false;
					}
					se.erase(p.s);
					ma[jo[p.s]]--;
				}
			}
			if(ev[i].back().f==0){
				if(ma[jo[*se.rbegin()]]>1) ans++;
			}
		}
		cout << ans << endl;
		
		for(auto it : jo)
			ma[it] = 0;
	}

	exit(0);
}

