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

char M[MAX][MAX];
int vis[MAX][MAX];
int row[MAX], col[MAX];
int n,m;
int vx[4] = {1, -1, 0, 0};
int vy[4] = {0, 0, 1, -1};
void haverow(){
	bool ret = true;
	for(int i=0;i <n; i++){
		bool have = false;
		for(int j=0; j<m; j++){
			if(M[i][j]=='#') have = true;
		}
		row[i] = have;
	}
}
void havecol(){
	bool ret = true;
	for(int j=0;j <m; j++){
		bool have = false;
		for(int i=0; i<n; i++){
			if(M[i][j]=='#') have = true;
		}
		col[j] = have;
	}
}
bool fill(){
	bool ret = true;
	for(int i=0; i<n; i++){
		if(row[i]) continue;
		bool show = false;
		for(int j=0;j <m; j++) if(!col[j]) show = true;
		ret &= show;
	}
	for(int j=0; j<m; j++){
		if(col[j]) continue;
		bool show = false;
		for(int i=0;i <n; i++) if(!row[i]) show = true;
		ret &= show;
	}
	return ret;
}
bool rowclose(){
	for(int i=0;i <n; i++){
		bool black = false;
		bool visto = false;
		for(int j=0; j<m; j++){
			if(M[i][j]=='#'){
				if(!black and visto) return false;
				black = true;
				visto = true;
			}
			else black = false;
		}
	}
	return true;
}
bool colclose(){
	for(int j=0;j <m; j++){
		bool black = false;
		bool visto = false;
		for(int i=0; i<n; i++){
			if(M[i][j]=='#'){
				if(!black and visto) return false;
				black = true;
				visto = true;
			}
			else black = false;
		}
	}
	return true;
}

bool val(int x, int y){
	if(x<0 or x>=n) return false;
	if(y<0 or y>=m) return false;
	if(vis[x][y]) return false;
	return true;
}

int bfs(int x, int y){
	vis[x][y] = 1;
	queue<ii> q;
	q.push({x, y});
	while(!q.empty()){
		ii p = q.front(); q.pop();
		for(int i=0;i <4; i++){
			x = p.f+vx[i];
			y = p.s + vy[i];
			if(val(x, y)){
				vis[x][y] = 1;
				q.push({x, y});
			}
		}
	}
}

int main(){ _
	memset(vis, 0, sizeof(vis));
	cin >> n >> m;
	for(int i=0;i <n; i++){
		for(int j=0;j <m; j++){
			cin >> M[i][j];
			if(M[i][j]=='.') vis[i][j] = 1;
		}
	}
	bool ans;
	haverow(); havecol();

	ans = fill() and colclose() and rowclose();
	if(!ans) return cout << -1 << endl, 0;
		
	int comp = 0;
	for(int i=0;i <n; i++){
		for(int j=0;j <m; j++){
			if(!vis[i][j]){
				comp++;
				bfs(i, j);
			}
		}
	}
	cout << comp << endl;

	exit(0);
}
