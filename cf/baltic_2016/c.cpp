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

const int MAX = 1e5+10;
int n, k;
int val[MAX], D[MAX], v[MAX];
vector<int> g[MAX];
bool is_max = 0;


void dfs(int x, int pai){
	val[x] = -1;

	for(auto u : g[x]){
		if(u==pai) continue;

		if(g[x].size()==2 and x!=0) D[u] = D[x];
		else if(g[x].size()==1 and x==0) D[u] = D[x];
		else D[u]=D[x]+1;

		dfs(u, x);

		if((D[u]<=k and !is_max) or (D[u]>k and is_max)){
			if(val[x]==-1) val[x] = val[u];
			else val[x] = min(val[x], val[u]);
		}
		if((D[u]>k and !is_max) or (D[u]<=k and is_max)){
			if(val[x]==-1) val[x] = val[u];
			else val[x] = max(val[x], val[u]);
		}	
	}

	if(g[x].size()==1 and x!=0) val[x] = v[x];
	//cout << x+1 << " dist= " << D[x] << " val= " << val[x] << endl;
}

int main(){ _
	cin >> n >> k;	
	int l = 0;
	for(int i=1; i<n; i++){
		int a; cin >> a; a--;
		g[i].pb(a);
		g[a].pb(i);
	}
	for(int i=0;i <n; i++) {cin >> v[i]; l+=(v[i]!=0);}

	ii ans;
	D[0]=0;
	dfs(0, 0);
	ans.f = val[0];
	
	k = n-l-k;
	is_max = !is_max;
	dfs(0, 0);
	ans.s = val[0];
	cout << ans.f << " " << ans.s << endl;

	exit(0);
}
