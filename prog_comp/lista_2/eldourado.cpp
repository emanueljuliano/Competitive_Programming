#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;

const int MAX = 1e2+10;
ll dp[MAX][MAX][MAX];
vector<int> v;
int n, k;

ll solve(int p, int at, int tam){
	if(tam==0) return 1;
	if(p==n-1){
		if(tam!=1) return 0;
		if(at>=v[p]) return 0;
		return 1;
	}
	ll &ret = dp[p][at][tam];
	if(ret!=-1) return ret;
	ret = solve(p+1, at, tam);
	if(v[p]>at) ret += solve(p+1,v[p], tam-1);
	return ret;
}

int main(){ _
	while(true){
		cin >> n >> k;
		if(n==0) break;
		
		v.resize(n);
		for(auto &u:v) cin >> u;
		
		vector<int> aux = v;
		sort(aux.begin(), aux.end());
		map<int, int> mp;
		int ptr = 1;
		for(auto u : aux) if(!mp.count(u)) mp[u]=ptr++;
		for(auto &u:v) u = mp[u];
		
		for(int i=0;i <=n; i++) for(int j=0; j<=n; j++) for(int l=0; l<=n; l++)
			dp[i][j][l]=-1;
		
		cout << solve(0, 0, k) << endl;
	}

	exit(0);
}
