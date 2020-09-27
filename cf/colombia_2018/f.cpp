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
const int MAX = 105;
const int sig = 26;
const int MAX2 = sig*MAX+5;

int n;
vector<vector<int>> g(MAX);
int vis[MAX2];
int mb[MAX2];

bool dfs(int v){
	for(int i=0;i <g[v].size(); i++){
		int u = g[v][i]; 
		if(vis[u]) continue; 
		vis[u]=1;

		if(mb[u]==-1 or dfs(mb[u])){
			mb[u] = v;
			return true;
		}
	}
	return false;
}

int kuhn(){
	int ret = 0;
	for(int j=0; j<MAX2; j++) vis[j] = 0;
	for(int j=0; j<MAX2; j++) mb[j] = -1;
	for(int i=0;i <n; i++){
		if(dfs(i)){
			for(int j=0; j<MAX2; j++) vis[j] = 0;
			ret++;
		}
	}
	return ret;
}

int main(){ _
	cin >> n;
	vector<int> alp(sig);
	vector<vector<int>> v(n);

	for(int i=0;i <n; i++){
		for(int j=0; j<sig; j++) alp[j]=0;
		int maxi = 0;

		for(int j=0;j <3; j++){
			string s; cin >> s;
			for(auto c : s){
				alp[c-'A']++; maxi = max(maxi, alp[c-'A']);
			}
		}

		for(int j=0; j<sig; j++) if(alp[j]==maxi) v[i].pb(j);
	}

	int k; cin >> k;
	for(int i=0;i <n; i++) for(auto c : v[i]) for(int j=0; j<k; j++) g[i].pb(k*c+j);
//	for(int i=0;i <n; i++){
//		cout << i << "-> ";
//		for(auto u : g[i]) cout << u << " ";
//		cout << endl;
//	}

	int ans = kuhn();
	cout << ans << endl;;

	exit(0);
}
