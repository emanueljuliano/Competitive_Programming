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
int vis[11][11][11];
int n, m, k;
vector<vector<int>> mov = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
bool val(vector<int> v){
	return v[0]>=0 and v[1]>=0 and v[2]>=0 and v[0]<n and v[1]<m and v[2]<k and
		M[v[0]][v[1]][v[2]] == '.';
}
int main(){ _
	cin >> n >> m >> k;

	for(int i=0;i <n; i++) for(int j=0; j<m; j++) for(int x=0; x<k; x++)
		cin >> M[i][j][x];
	

	pair<ii, int> ini = {{0, 0}, 0};
	cin >> ini.f.s >> ini.s;
	ini.s--, ini.f.s--;
	queue<pair<ii, int>> q;
	
	q.push(ini);
	vis[ini.f.f][ini.f.s][ini.s] = true;

	while(!q.empty()){
		pair<ii, int> at = q.front(); q.pop();

		for(auto u : mov){
			u[0] += at.f.f, u[1]+=at.f.s, u[2]+=at.s;
			if(val(u) and !vis[u[0]][u[1]][u[2]]){
				vis[u[0]][u[1]][u[2]] = true;
				q.push({{u[0], u[1]}, u[2]});
			}
		}
	}
	int ans = 0;
	for(int i=0;i <n; i++) for(int j=0; j<m; j++) for(int x=0; x<k; x++){
		//if(vis[i][j][x]) cout << i << " " << j << " " << x << endl;
		ans+= vis[i][j][x];
	}
	cout << ans << endl;
	
	exit(0);
}
