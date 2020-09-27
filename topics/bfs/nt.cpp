#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAX = 2e5;
const int MAX2 = 1e6+10;

vector<vector<int>>g(MAX);
vector<int> vis(MAX, 0), dis(MAX);

void limpa(int x){
	for(auto u : g[x]) if(vis[u]) vis[u]=0, dis[u]=0, limpa(u);
}

int bfs(int x){
	queue<ii> q;
	q.push({x, x});
	vis[x] = 1;
	dis[x] = 1;
	int ret=INF;

	while(ret==INF and q.size()){
		ii at = q.front(); q.pop();
		int v = at.f, pai = at.s;

		for(auto u : g[v]){
			if(!vis[u]) vis[u] = 1, dis[u]=dis[v]+1, q.push({u, v});
			else if(u!=pai){
				ret = (dis[u]+dis[v])/2;
				break;
			}
		}
	}

	vis[x] = 0, dis[x]=0;
	limpa(x);

	return ret;
}

int pri[MAX2];
vector<int> source;
void crivo(){
	for(int i=2;i <MAX2; i++) pri[i] = 1;
	pri[1] = 0;
	int ptr = 1;
	source.pb(0);

	for(int i=2; i<MAX2; i++) if(pri[i]){
		if(i<=sqrt(MAX)) source.pb(ptr);
		pri[i] = ptr++;
		for(int j=i+i; j<MAX2; j+=i) pri[j] = 0;
	}
}

int main(){ _

	int n; cin >> n;
	crivo();	
	set<int> st;
	st.insert(1);
	int ans = INF;

	vector<int> v;
	for(int i=0;i <n; i++){
		int a; cin >> a;
		vector<int> pp;
		
		for(int j=2; j*j<=a; j++) if(a%j==0){
			int pot = 0;
			while(a%j==0) pot++, a/=j;
			if(pot%2) pp.pb(j);
		}
		if(a!=1) pp.pb(a);
		if(pp.size()==1) pp.pb(1);

		ll mul = 1; for(auto u : pp) mul*=u;
		if(mul==1) return cout << 1 << endl, 0;	
		if(st.count(mul)) ans=2;
		else st.insert(mul);
		
		for(auto u : pp){
			g[n+pri[u]].pb(i), g[i].pb(n+pri[u]);
		}
	}
	if(ans==2) return cout << ans << endl, 0;

	for(auto i : source){
		ans = min(ans, bfs(i+n));
	}

	if(ans==INF) cout << -1 << endl;
	else cout << ans << endl;

	exit(0);
}
