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

const int MAX = 3e5+10;
vector<int> id(MAX), pai(MAX);
int pt;
vector<int> g[MAX];
vector<ii> ans;
int vis[MAX];
set<ii> st;

void bfs(int v){
	queue<int> q;
	q.push(v), vis[v]=1, id[v]=v;
	while(!q.empty()){
		v = q.front(); q.pop();
		for(auto w : g[v]){
			if(vis[w] and !(st.count({v, w}) or st.count({w, v})))
				id[pt]=w, ans.pb({v, pt}), st.insert({v, w}), pt++;
			else if(!vis[w]) 
				id[w]=w, ans.pb({v, w}), st.insert({v, w}), q.push(w), vis[w]=1;
		}
	}
}

int main(){ _
	int n, m; cin >> n >> m;
	pt = n;
	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	bfs(0);
	cout << pt << endl;
	for(int i=0;i <pt; i++) cout << id[i]+1 << " ";
	cout << endl;
	for(int i=0;i <pt-1; i++){
		cout << ans[i].f+1 << " " << ans[i].s+1 << endl;
	}
	
	
	
	exit(0);
}
