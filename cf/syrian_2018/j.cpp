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
	freopen("clar.in", "r", stdin);	
	
	int tt; cin >> tt;
	while(tt--){
		int m, n, k; cin >>m >> n >> k;
		vector<vector<ii>> ev(m+n+k+5);
		vector<vector<int>> times(k+2);
		int maxi = 0;
		for(int i=0;i <n; i++){
			int t, p; cin >> t >> p;
			ev[t].pb({p, i});
			times[p].pb(t);
			maxi = max(maxi, t);
		}
		
		vector<int> color(k+2);
		for(int i=0;i <=k; i++){
			if(times[i].size()==0) continue;
			sort(times[i].begin(), times[i].end());
			if(times[i].size()==1) color[i] = INF;
			if(times[i].size()>=2) color[i] = times[i][1];
		}

		set<ii> kan;
		vector<int> to_add(k+2);
		vector<int> vis(k+2), in_kan(k+2);
		int both = 0, ans = 0;
		for(int x=1; x<ev.size(); x++){
			for(auto [u, id] : ev[x]){ // add
				if(vis[u]) both++;
				else{
					if(in_kan[u]) to_add[u]++;
					else{
						to_add[u]++, in_kan[u] = 1;
						kan.insert({color[u], u});	
					}
				}
			}
			
			if(kan.size()){
				both = max(0, both-1);

				auto [time, u] = *kan.begin();	
				kan.erase({time, u});
				vis[u] = 1;
				both += to_add[u] -1;
				to_add[u] = 0;
			}
			else both = max(0, both-2);

			if(x>=maxi and !kan.size() and both==0) {ans = x; break;}
		}
		cout << ans << endl;
		

	}
	
	
	exit(0);
}
