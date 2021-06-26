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

int main(){ _
	int n, k; cin >> n >> k;

	vector<vector<int>> g(n);
	vector<int> dg(n);
	for(int i=0; i<n-1; i++){
		int a, b, c; cin >> a >> b >> c; a--, b--;
		g[a].pb(b);
		g[b].pb(a);
		dg[a]++, dg[b]++;
	}

	set<int> st;
	for(int i=0;i <k; i++){
		int a; cin >> a; a--;
		st.insert(a);
	}
	vector<int> vis(n);
	queue<int> q;
	for(int i=0;i <n; i++) if(dg[i]==1 and !st.count(i)) q.push(i), vis[i]=1;
	
	while(!q.empty()){
		int x = q.front(); q.pop();
		for(auto u : g[x]) {
			dg[u]--;
			if(dg[u]==1 and !st.count(u)) q.push(u), vis[u]=1;
		}
	}

	int ans = 0;
	for(int i=0;i <n; i++) if(!vis[i]) ans++;
	cout << ans << endl;
	
	
	exit(0);
}
