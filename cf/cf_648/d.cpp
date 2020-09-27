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

vector<string> M;
int vx[4] = {1, -1, 0, 0};
int vy[4] = {0, 0, 1, -1};
int n, m;
int id[(int)1e6];

bool val(int i, int j){
	if(i<0 or i>=n) return false;
	if(j<0 or j>=m) return false;
	if(M[i][j]=='#') return false;
	return true;
}

int find(int p){
	if(p==id[p]) return p;
	return id[p] = find(id[p]);
}
void une(int p, int q){
	p = find(p); q = find(q);
	id[p] = q;
}
void build(){
	for(int i=0; i<=n*m; i++) id[i] = i;
}

bool bfs(){
	queue<ii> q;
	build();
	for(int i=0;i <n; i++){
		for(int j=0; j<m; j++){
			if(M[i][j]=='G'){
				q.push({i, j});
			}
		}
	}
	while(!q.empty()){
		ii aux = q.front(); q.pop();
		int i = aux.f;
		int j = aux.s;
		for(int k=0; k<4; k++){
			int x=i+vx[k], y = j+vy[k];
			if(val(x, y)) if(find(i*m+j) != find(x*m+y)){
				une(i*m+j, x*m+y);
				q.push({x, y});
			}
		}
	}
	//for(int i=0;i <n; i++){
	//	for(int j=0; j<m; j++) cout << M[i][j] << " ";
	//	cout << endl;
	//}	
	
	for(int i=0;i <n; i++){
		for(int j=0; j<m; j++){
			if(M[i][j]=='G'){
				if(find(i*m+j) != find((n-1)*m+(m-1))) return false;
			}
		}
	}
	for(int i=0;i <n; i++){
		for(int j=0; j<m; j++){
			if(M[i][j]=='B'){
				if(find(i*m+j) == find((n-1)*m+(m-1))) return false;
			}
		}
	}

	return true;
	
}

int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> n >> m; M.resize(n);
		for(int i=0;i <n; i++) cin >> M[i];
		bool show = true;
		for(int i=0;i <n; i++) for(int j=0; j<m; j++){
			if(M[i][j]=='B'){
				for(int k=0; k<4; k++){
					int x = i+vx[k];
					int y = j+vy[k];
					if(val(x, y)){
						if(M[x][y]=='.') M[x][y] = '#';
					}
				}
					
			}
		}
		
		show &= bfs();
		if(show) cout << "Yes" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	exit(0);
}
