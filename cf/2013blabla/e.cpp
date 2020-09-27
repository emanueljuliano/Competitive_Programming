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
int n, m;
int vis[550][550];
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};

bool val(int i, int j){
	return(i>=0 and j>=0 and i<n and j<m);
}

int bfs(ii p, vector<vector<int>> M){
	memset(vis, -1, sizeof(vis));
	
	queue<ii> s;
	s.push(p);
	vis[p.f][p.s] = 0;

	while(!s.empty()){
		ii p = s.front();
		s.pop();

		for(int k=0; k<4; k++){
			int ii = p.f+di[k], jj=p.s+dj[k];
			if(!val(ii, jj) or M[ii][jj]==1 or vis[ii][jj]!=-1) continue;
			s.push({ii, jj});
			vis[ii][jj] = vis[p.f][p.s]+1;
		}
	}
	return vis[n-1][m-1];
}

int main(){ _
	cin >> n >> m;
	
	vector<vector<int>>m1(550, vector<int>(550, 0));
	vector<vector<int>>m2(550, vector<int>(550, 0));
	vector<vector<int>>m3(550, vector<int>(550, 0));
	
	for(int i=0; i<n; i++){
		string s; cin >> s;
		for(int j=0; j<m; j++){
			if(s[j]=='#') m1[i][j] = 1, m3[i][j]=1;
		}
	}

	for(int i=0; i<n; i++){
		string s; cin >> s;
		for(int j=0; j<m; j++){
			if(s[j]=='#') m2[i][j] = 1, m3[i][j]=1;
		}
	}
	int d1 = bfs({0, 0}, m1);
	int d2 = bfs({0, 0}, m2);
	int d3 = bfs({0, 0}, m3);
	
	if(d1==-1 or d2==-1) cout << "NO" << endl;
	else if(d1==d3 and d2==d3) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	
	exit(0);
}
