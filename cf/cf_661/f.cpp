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

const int MAX = 6030;
map<pair<ii, int>, int> dp;
vector<vector<int>> ini;

int rec(int l, int r, int at){
	if(l>r) return 0;
	pair<ii, int> p = {{l, r}, at};
	if(dp.count(p)) return dp[p];
	int &ret = dp[p];
	if(at>=ini[l].size() or ini[l][at]>r) return ret= rec(l+1, r, 0);
	ret = max(rec(l, r, at+1), 1+rec(l, ini[l][at], at+1)+rec(ini[l][at]+1, r, 0));	
	return ret;
};


int main(){ _
	int t; cin >> t;
	while(t--){
		dp.clear();
		map<int, int> mp;
		vector<int> cor;
		int n; cin >> n;
		vector<ii> v(n);
		for(auto &i : v) {cin >> i.f >> i.s; cor.pb(i.f), cor.pb(i.s);}

		int pt = 0;
		sort(cor.begin(), cor.end());
		for(auto x : cor) if(!mp.count(x)) mp[x] = pt++;
		for(auto &i : v) i = {mp[i.f], mp[i.s]};
		ini.resize(pt+10);
		for(auto i : v) ini[i.f].pb(i.s);
		for(auto i : v) sort(ini[i.f].begin(), ini[i.f].end());

		//sort(v.begin(), v.end());
		//for(int i=0;i <=pt+10; i++) for(int j=0; j<=pt+10; j++) dp[i][j] = -1;
		cout << rec(0, pt+1, 0) << endl;
	
		for(int i=0;i<pt+10; i++) ini[i].clear();
	}

	exit(0);
}
