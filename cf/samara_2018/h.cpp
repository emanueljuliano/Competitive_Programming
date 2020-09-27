#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 200010;
vector<string> M(MAX);
vector<vector<int>> dis(MAX);
int vx[4] = {1, -1, 0, 0};
int vy[4] = {0, 0, 1, -1};

int n, m, d;
bool val(int i, int j){
	if(i>=n or i<0) return false;
	if(j>=m or j<0) return false;
	if(dis[i][j]!=-1) return false;
	return true;
}

void color(){
	queue<ii> q;
	for(int i=0;i <n; i++){
		for(int j=0;j <m; j++){
			if(M[i][j]=='M'){
				q.push({i, j});
				dis[i][j] = 0;
			}
		}
	}
	while(!q.empty()){
		ii aux = q.front(); q.pop();
		if(dis[aux.f][aux.s] >=d) continue;
		for(int i=0;i <4; i++){
			ii at = aux;
			at.f += vx[i]; at.s+=vy[i];
			if(val(at.f, at.s)){
				dis[at.f][at.s] = dis[aux.f][aux.s]+1;	
				q.push(at);
			}
		}
	}
}

void bfs(int i, int j){
	queue<ii> q;
	q.push({i, j});
	dis[i][j] = 0;
	while(!q.empty()){
		ii aux = q.front(); q.pop();
		for(int i=0;i <4; i++){
			ii at = aux;
			at.f += vx[i]; at.s+=vy[i];
			if(val(at.f, at.s)){
				dis[at.f][at.s] = dis[aux.f][aux.s]+1;	
				q.push(at);
			}
		}
	}
}


int main(){ _
	cin >> n >> m >> d;
	ii ini, end;
	for(int i=0;i <n+5; i++){
		for(int j=0;j <m+5; j++){
			dis[i].pb(-1);
		}
	}
	for(int i=0;i<n; i++){
		string s; cin >> M[i];
		for(int j=0; j<m; j++){
			char a = M[i][j];
			if(a=='S') ini = {i, j};
			if(a=='F'){
				end = {i, j};
			}
		}
	}
	color();
	bool show = true;
	if(dis[ini.f][ini.s]!=-1) show = false;
	if(dis[end.f][end.s]!=-1) show = false;


	if(!show) cout << -1 << endl;
	else{
		bfs(ini.f, ini.s);	
		cout << dis[end.f][end.s] << endl;
	}
	exit(0);
}
