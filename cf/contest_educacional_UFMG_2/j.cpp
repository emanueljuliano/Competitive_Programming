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

const int MAX = 440;
int M[MAX][MAX];

int main(){ _
	int n, m; cin >> n >> m;
	
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b; a--, b--;
		M[a][b] = 1, M[b][a] = 1;
	}
	
	vector<vector<int>> g(n);
	if(M[0][n-1]){
		for(int i=0;i <n; i++) for(int j=0; j<n; j++)
			if(i!=j and M[i][j]==0) g[i].pb(j);
	}
	else{
		for(int i=0;i <n; i++) for(int j=0; j<n; j++)
			if(i!=j and M[i][j]==1) g[i].pb(j);
	}

	vector<int> d(n, -1);	
	queue<int> q;
	q.push(0); d[0] = 0;

	while(!q.empty()){
		int x = q.front(); q.pop();
		for(auto u : g[x]) if(d[u]==-1) d[u]=d[x]+1, q.push(u);
	}

	cout << d[n-1] << endl;
	
	exit(0);
}
