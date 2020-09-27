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
int M[MAX][MAX];
int ans[MAX][MAX];
int n, m;
int vx[4] = {1, -1, 0, 0};
int vy[4] = {0, 0, 1, -1};

bool val(int i, int j){
	if(i>=n or i<0) return false;
	if(j>=m or j<0) return false;
	return true;
}

void bfs(){
	queue<ii> q;
	for(int i=0;i <n; i++){
		for(int j=0;j <m; j++){
			if(ans[i][j]==1) q.push({i, j});
		}
	}
	while(!q.empty()){
		ii at = q.front(); q.pop();
		for(int j=0; j<4; j++){
			int x = at.f+vx[j]; int y = at.s+vy[j];
			if(val(x, y) and ans[x][y]==-1){
				ans[x][y] = ans[at.f][at.s]+1;
				q.push({x, y});
			}
		}
	}
}
int main(){ _
	memset(ans, -1, sizeof(ans));
	int  t; cin >> n >> m >> t;
	for(int i=0; i<n; i++){
		string s; cin >> s;
		for(int j=0; j<m; j++) M[i][j] = s[j]-'0';
	}
	for(int i=0;i <n; i++){
		for(int j=0; j<m; j++){
			for(int k=0; k<4; k++){
				int x=i+vx[k], y = j+vy[k];
				if(val(x, y) and M[x][y]==M[i][j]) ans[i][j]=1, ans[x][y]=1;
			}
		}
	}
	bfs();
//	for(int i=0; i<n; i++){
//		for(int j=0; j<m; j++){
//			cout << ans[i][j] << " ";
//		}
//		cout << endl;
//	}
	while(t--){
		int i, j; ll p; cin >> i>> j >>p;i--; j--;
		
		if(ans[i][j]==-1 or ans[i][j]>p) cout << M[i][j] << endl;
		else if((p-ans[i][j])%2==0) cout << !M[i][j] << endl;
		else cout << M[i][j] << endl;
	}


	exit(0);
}
