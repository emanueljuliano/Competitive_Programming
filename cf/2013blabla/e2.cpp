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
vector<vector<int>>ma(550, vector<int>(550, 0));

int bfs(ii p){
	queue<pair<ii, int>> s;
	s.push({p, 1});
	while(!s.empty()){
		pair<ii, int> aux = s.front();
		p = aux.f;
		int d = aux.s;
		//cout << p.f << " " << p.s << " " << d << endl;
		s.pop();

		
		if(p.f==n-1 and p.s==m-1) return d;
		vis[p.f][p.s] = 1;
		if(p.f>0 and ma[p.f-1][p.s]==0 and !vis[p.f-1][p.s]) s.push({{p.f-1, p.s}, d+1});
		if(p.s>0 and  ma[p.f][p.s-1]==0 and !vis[p.f][p.s-1]) s.push({{p.f, p.s-1}, d+1});
		if(p.f<n-1 and  ma[p.f+1][p.s]==0 and !vis[p.f+1][p.s]) s.push({{p.f+1, p.s}, d+1});
		if(p.s<m-1 and  ma[p.f][p.s+1]==0 and !vis[p.f][p.s+1]) s.push({{p.f, p.s+1}, d+1});
	}
	return -1;
}

int main(){ _
	cin >> n >> m;
	memset(vis, 0, sizeof(vis));
	for(int i=0; i<n; i++){
		string s; cin >> s;
		for(int j=0; j<m; j++){
			if(s[j]=='#') ma[i][j] = 1;
		}
	}

	int d1 = bfs({0, 0});
	memset(vis, 0, sizeof(vis));
	vector<vector<int>>mm = ma;
	vector<vector<int>>maux(550, vector<int>(550, 0));
	ma = maux;
	for(int i=0; i<n; i++){
		string s; cin >> s;
		for(int j=0; j<m; j++){
			if(s[j]=='#') ma[i][j] = 1, mm[i][j]=1;
		}
	}
	int d2 = bfs({0, 0});
	memset(vis, 0, sizeof(vis));
	ma = mm;
	/*for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cout << ma[i][j] << " ";
		cout << endl;
	}*/
	int ans = bfs({0, 0});
	if(d1==-1 or d2==-1) cout << "NO" << endl;
	else if(ans==d2 and ans==d1) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	
	exit(0);
}

