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

const int MAX = 110;

int n, m;
char M[MAX][MAX];
bool vis[MAX][MAX];

// cima, baixo, esquerda e direita
vector<pair<int, int>> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool val(pair<int, int> u){
	return u.f>=0 and u.s>=0 and u.f<n and u.s<m
		and M[u.f][u.s]=='H' and !vis[u.f][u.s];
}

pair<int, int> bfs(pair<int, int> s){
	queue<pair<int, int>> q;
	q.push(s), vis[s.f][s.s]=1;
	
	pair<int, int> v;
	while(!q.empty()){
		v = q.front(); q.pop();
		for(auto u : mov){
			u.f += v.f, u.s+=v.s; // new_i = u.f+v.f;
			if(val(u)){
				q.push(u), vis[u.f][u.s]=1;
			}
		}
	}
	return v;
}

int main(){ _
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++) for(int j=0; j<m; j++)
		cin >> M[i][j];
	
	pair<int, int> s;

	for(int i=0;i <n; i++) for(int j=0; j<m; j++)
		if(M[i][j]=='o') s = {i, j};

	pair<int, int> ans = bfs(s);
	
	cout << ans.f+1 << " " << ans.s+1 << endl;

	exit(0);
}
