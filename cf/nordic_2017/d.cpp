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

const int MAX = 1e6 + 1e5;
vector<vector<int>> g(MAX);
vector<int> v;
int D[MAX];

int bfs(){
	int x;
	queue<int> q;
	for(auto i : v){
		D[i] = 0;
		q.push(i);
	}
	while(!q.empty()){
		x = q.front(); q.pop();
		for(auto u : g[x]){
			if(D[u]==-1){
				D[u] = D[x]+1;
				q.push(u);
			}
		}
	}
	return x;
}

int main(){ _
	int n, m; cin >> n >> m;
	for(int i=0;i <n; i++){
		string s; cin >> s;
		int at = 0;
		for(int j=0; j<m; j++){
			if(s[j]=='1') at += 1<<j;
		} 
		v.pb(at);
	}
	
	for(int i=0;i <1<<m; i++){
		D[i] = -1;
		for(int j=0; j<m; j++){
			int x = i^(1<<j);
			g[i].pb(x);
		}
	}

	int ans = bfs();
	for(int i=0;i <m; i++)
		cout << !(!(ans&1<<i));
	cout << endl;
	
	exit(0);
}
