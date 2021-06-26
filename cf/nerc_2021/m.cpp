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

void radix(vector<ii> &v){
	int n = v.size();
	vector<int> pos, cnt;
	int maxi = 0;
	for(int i=0; i<n; i++) maxi = max({maxi, v[i].f, v[i].s});
	pos.resize(maxi+1), cnt.resize(maxi+1);
	vector<ii> aux(v.size());
	
	// Sort by second coordinate
	for(int i=0;i <=maxi; i++) cnt[i] = 0;
	for(int i=0;i <n; i++) cnt[v[i].s]++;
	pos[maxi] = 0;
	for(int i=maxi-1;i+1; i--) pos[i] = pos[i+1] + cnt[i+1];
	for(int i=0;i <n; i++) aux[pos[v[i].s]++] = v[i];
	for(int i=0;i <n; i++) v[i] = aux[i];

	// Sort by first coordinate
	for(int i=0;i <maxi; i++) cnt[i] = 0;
	for(int i=0;i <n; i++) cnt[v[i].f]++;
	pos[0] = 0;
	for(int i=1;i <maxi; i++) pos[i] = pos[i-1] + cnt[i-1];
	for(int i=0;i <n; i++) aux[pos[v[i].f]++] = v[i];
	for(int i=0;i <n; i++) v[i] = aux[i];
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<vector<int>> v(n);
		map<int, int> mp;
		int pt = 0, tot=0;
		for(int i=0;i <n; i++){
			int k; cin >> k; tot += k;
			v[i].resize(k);
			for(auto &j : v[i]) {
				cin >> j;
				if(!mp.count(j)) mp[j] = pt++;
				j = mp[j];
			}
			sort(v[i].begin(), v[i].end());
		}

		int sq = sqrt(tot)/6+1;
		vector<int> vis(pt);
		ii ans = {-1, -1};
		vector<ii> small;

		for(int i=0; i<n and ans.f==-1; i++){
			if(v[i].size() >= sq){
				for(auto u : v[i]) vis[u] = 1;
				for(int j=0; j<n and ans.f==-1; j++) if(i!=j and (i<j or v[j].size()<sq)){
					ii at = {-1, -1};
					for(auto u : v[j]) {
						if(vis[u] and at.f==-1) at.f = u;
						else if(vis[u] and at.s==-1) {at.s = u; break;}
					}
					if(at.s!=-1) ans = {i, j};
				}
				for(auto u : v[i]) vis[u] = 0;
			}
			else{
				for(int j=0; j<v[i].size(); j++)
					for(int k=j+1; k<v[i].size(); k++)
						small.pb({v[i][j], v[i][k]});
			}
		}
		if(ans.f!=-1) cout << ans.f+1 << " " << ans.s+1 << endl;
		else{
			radix(small);
			ii has = {-1, -1};
			for(int i=0; i<(int)small.size()-1; i++)
				if(small[i]==small[i+1]) {has = small[i]; break;}
			for(int i=0; i<n; i++) if(v[i].size()<sq){
				int sum = 0;
				for(auto u : v[i]) if(u==has.f or u==has.s) sum++;
				if(sum==2 and ans.f==-1) ans.f=i;
				else if(sum==2 and ans.s==-1) ans.s=i;
			}
			if(ans.f!=-1) cout << ans.f+1 << " " << ans.s+1 << endl;
			else cout << -1 << endl;
		}
	}
	
	
	
	exit(0);
}
