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

const int MAX = 505;
char M[MAX][MAX];
int n, m;
int w[MAX];
int vis[MAX*MAX];

int f(int i, int j){
	return i*m + j;
}

int dfs(int i, int j){
	if(i<0 or j<0 or j>=m) return 0;
	if(i==n) return w[j];
	int p = f(i, j);
	if(vis[p] != -1) return vis[p];
	vis[p] = 0;
	if(M[i][j] == '.') vis[p] = max(vis[p], dfs(i+1, j));
	else{
		vis[p] = max(vis[p], dfs(i+1, j));
		vis[p] = max(vis[p], dfs(i+1, j+1));
		vis[p] = max(vis[p], dfs(i+1, j-1));
	}
	return vis[p];
}

int main(){ _
	freopen("balls.in", "r", stdin);	
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		vector<int> v(m);
		for(auto &i : v) cin >> i;
		for(int i=0;i <n; i++) for(int j=0; j<m; j++) cin >> M[i][j];	
		for(int i=0;i <m; i++) cin >> w[i];
		
		memset(vis, -1, (n*m)*sizeof(vis[0]));
		ll ans = 0;
		for(int i=0;i <m; i++) {
			ans += ll(v[i])*dfs(0, i);
		}	
		cout << ans << endl;
	}
	
	
	exit(0);
}
