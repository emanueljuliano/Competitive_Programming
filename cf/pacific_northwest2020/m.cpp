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

const int MAX = 1e3+10;
vector<string> v;
int vis[MAX][MAX];
ii vx[4] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int n, m;

bool val(int i, int j){
	if(i<0 or i>=n or j<0 or j>=m or vis[i][j]) return false;
	return true;
}

void dfs(int i, int j){
	if(v[i][j]!='.') return;

	vis[i][j] = 1;
	// ponto
	for(int k=0; k<4; k++){
		int x = i+vx[k].f, y = j+vx[k].s;
		if(val(x, y)) dfs(x, y);
	}

	// slide
	if(val(i-1, j) and v[i-1][j]=='\\' and val(i-1, j-1)) dfs(i-1, j-1);
	if(val(i-1, j) and v[i-1][j]=='/' and val(i-1, j+1)) dfs(i-1, j+1);
	if(val(i+1, j) and v[i+1][j]=='\\' and val(i+1, j+1)) dfs(i+1, j+1);
	if(val(i+1, j) and v[i+1][j]=='/' and val(i+1, j-1)) dfs(i+1, j-1);
	
}

int main(){ _
	cin >> n >> m;
	v.resize(n);
	memset(vis, 0, sizeof vis);

	for(int i=0;i <n; i++){
		cin >> v[i];
	}

	// . na estremidade
	for(int i=0;i <n; i++) if(v[i][0]=='.' and !vis[i][0]) dfs(i, 0);
	for(int i=0;i <n; i++) if(v[i][m-1]=='.' and !vis[i][m-1]) dfs(i, m-1);
	for(int i=0;i <m; i++) if(v[0][i]=='.' and !vis[0][i]) dfs(0, i);
	for(int i=0;i <m; i++) if(v[n-1][i]=='.' and !vis[n-1][i]) dfs(n-1, i);
	
	int ans = 0;
	// quadrado
	for(int i=0;i <n; i++) for(int j=0; j<m; j++){
		if(v[i][j]=='/'){
			if(!val(i, j+1) or !val(i+1, j) or !val(i+1, j+1)) continue;
			if(v[i][j+1]== '\\' and v[i+1][j] == '\\' and v[i+1][j+1]=='/') ans++;
		}
	}
	// ponto
	for(int i=0;i <n; i++) for(int j=0; j<m; j++) if(!vis[i][j] and v[i][j]=='.'){
		dfs(i, j); ans++;
	}
	
	cout << ans << endl;	
	
	exit(0);
}
