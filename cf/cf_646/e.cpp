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
const int MAX = 2e5+10;

int A[MAX], B[MAX], C[MAX], E[MAX], Z[MAX];
vector<vector<int>> g(MAX);

int dfs1(int x, int p){
	if(A[x]>A[p]) A[x] = A[p];
	int sz = B[x]!=C[x];
	Z[x] = (B[x]==0 and B[x]!=C[x]);
	for(int i=0;i <g[x].size(); i++){
		int u = g[x][i]; if(u==p) continue;
		sz += dfs1(u, x);
		Z[x] += Z[u];
	}
	return E[x] = sz;
}

ll ans = 0;
void dfs2(int x, int p){
	if(x==0){
		int z = Z[x];
		int u = E[x]-z;
		ans = 2*min(z, u);
		ans = ans*(ll)A[x];
	}
	else{
		int z = Z[x];
		int u = E[x]-z;
		ll change = 2*min(z, u);
		ans -= change*(ll)A[p];
		ans += change*(ll)A[x];
	}
	for(int i=0;i <g[x].size(); i++){
		int u = g[x][i]; if(u==p) continue;
		dfs2(u, x);
	}
}

int main(){ _
	int n; cin >> n;
	int a1=0, a2=0;
	for(int i=0;i <n; i++){
		cin >> A[i] >> B[i] >> C[i];
		if(B[i]!=C[i])a1 += B[i], a2 += C[i];
	}
	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b; a--; b--;
	//	cout << a << " "<< b << endl;
		g[a].pb(b);
		g[b].pb(a);
	}
	if(a1!=a2){cout << -1 << endl; exit(0); }
	dfs1(0, 0);
	
	dfs2(0, 0);
	cout << ans << endl;
	exit(0);
}
