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

const int MAX = 1e5+10;
int ig[MAX];
vector<vector<int>> g(MAX);

ii dfs(int x){
	ii ret = {0, 0};
	for(auto u : g[x]){
		ii at = dfs(u);
		ret.f |= at.f;
		ret.s += at.s;
	}
	if(x==0) return ret;

	ret.f |= (ig[x]==2);
	if(!ret.f and ret.s) ret.s=1;
	else if(!ret.f and ig[x]==1) ret.s=1;
	return ret;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		map<pair<string, int>, int> mp;
		int pai = 0, pt = 1;
		
		int n, m; cin >> n >> m;
		vector<int> w = {n, m};
		for(int k=0; k<2; k++) for(int i=0;i <w[k]; i++){
			string s; cin >> s; s+="/";
			string at;
			pai = 0;
			for(int j=0; j<s.size(); j++){
				char u = s[j];
				if(u=='/'){
					pair<string, int> p = {at, pai};
					if(!mp.count({at, pai})){
						mp[p] = pt;
						//cout << pt << " " << at << " " << pai << endl;
						g[pai].pb(pt);
						if(j==s.size()-1) ig[pt] = k+1;
						pai = pt++;
					}
					pai = mp[p];
					at.clear();
				}
				else at+=u;
			}
		}

		ii ans = dfs(0);
		cout << ans.s << endl;
		for(int i=0;i <=pt; i++) g[i].clear(), ig[i] = 0;
	}
	
	
	
	exit(0);
}
