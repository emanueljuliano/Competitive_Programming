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


char M[11][11][11];
bool vis[11][11][11];
vector<tuple<int, int, int>> mov = {{1, 0, 0}, {-1, 0, 0}, 
	{0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int k, n, m;

bool val(int x, int y, int z){
	return x>=0 and y>=0 and z>=0 and x<k and y<n and z<m 
		and M[x][y][z]=='.';
}

int main(){ _
	cin >> k >> n >> m;

	for(int i=0;i <k; i++) for(int j=0; j<n; j++)
		for(int t=0; t<m; t++) cin >> M[i][j][t];

	int a, b; cin >> a >> b; a--, b--;
	tuple ini(0, a, b);
	queue<tuple<int, int, int>> q;
	q.push(ini);
	vis[0][a][b] = 1;
	while(!q.empty()){
		auto [x, y, z] = q.front(); q.pop();
		
		for(auto [nx, ny, nz] : mov){
			nx+=x, ny+=y, nz+=z;
			if(val(nx, ny, nz) and !vis[nx][ny][nz])
				vis[nx][ny][nz] = true, q.push(tuple(nx, ny, nz));
		}
	}
	
	int ans = 0;
	for(int i=0;i <k; i++) for(int j=0; j<n; j++)
		for(int t=0; t<m; t++) ans += vis[i][j][t];
	cout << ans << endl;
	
	exit(0);
}
