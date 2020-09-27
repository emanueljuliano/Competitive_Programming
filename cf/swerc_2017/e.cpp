#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int b, n;

const int MAX = 1e6+10;

vector<vector<pair<pair<int,int>,int>>> g(MAX);
vector<pair<int,int>> d(MAX,{INF,-INF}); // cost - prest

// [which] {cost,prest}

pair<int,int> dfs(int v) {
	if(d[v].f != INF) return d[v];

	pair<int,int> pnow = {INF,-INF};
	for(auto u : g[v]) {
		auto pu = dfs(u.f.f);
		pu = {pu.f + u.f.s, pu.s + u.s};

		if(pu.f < pnow.f or (pu.f == pnow.f and pu.s > pnow.s)) 
			pnow = pu;
	}

	return d[v] = pnow;
}

const int MAX2 = 1e4+10;

int memo[MAX2][MAX2]; //[MAX2][MAX2];
int valid;

void dp() { 
	for (int i = 0; i <= valid; i++) for (int w = 0; w <= b; w++) { 
		if (i == 0 || w == 0) 
			memo[i][w] = 0; 
		else if (d[i-1].f <= w) 
			memo[i][w] = max(d[i-1].s + memo[i-1][w - d[i-1].f], memo[i-1][w]); 
		else
			memo[i][w] = memo[i - 1][w]; 
	} 
} 

ii rec() {
	int pres = 0, cost=INF;
	for(int i=0; i<=valid; i++) for(int j=0; j<=b; j++)
		if(memo[i][j]>pres) pres = memo[i][j];
	for(int i=0; i<=valid; i++) for(int j=0; j<=b; j++)
		if(memo[i][j]==pres and j<cost) cost=j;
	if(cost==INF) cost = 0;
	return {pres, cost};
}


int main(){ _

	cin >> b >> n;
	map<string,int> mp;
	int cnt = 0;
	for(int i=0; i<n; i++) {
		string sa, sb, sc; cin >> sa >> sb >> sc;	
		int c, p; cin >> c >> p;

		if(mp.find(sa) == mp.end()) {
			mp[sa] = cnt++;
			//cout << sa << " = " << cnt-1 << endl;
		}
		if(mp.find(sb) == mp.end()) {
			//cout << sb << " = " << cnt << endl;
			mp[sb] = cnt++;
		}
		g[mp[sa]].push_back({{mp[sb],c},p}); // transposto
	}

	valid = cnt;

	/*cout << "g" << endl;
	  for(int i=0; i<cnt; i++) {
	  for(auto u : g[i]) cout << u.f.f << " ";
	  cout << endl;
	  }
	  cout << endl;*/

	for(int i=0; i < cnt; i++) if(g[i].empty()) d[i] = {0,0};

	for(int i=0; i < cnt; i++) dfs(i);

	/*for(int i=0; i<cnt; i++) {
	  cout << d[i].f << " " << d[i].s << endl;	
	  }
	  cout << endl;*/

	memset(memo,-1,sizeof memo);

	//for(int i=0; i < MAX2; i++)
	//	for(int j=0; j < MAX2; j++) 
	//		memo[i][j].f = -1;
	dp();
	ii ans = rec();

	cout << ans.f << endl;
	cout << ans.s << endl;

	return 0;
}


