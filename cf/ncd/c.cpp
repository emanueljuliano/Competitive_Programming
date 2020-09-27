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

const int MAX = 1e3+10;
const int MOD = 1e9+7;
int dp[MAX][MAX];
ll dp2[MAX][MAX];
vector<int> v;
int n;

int lis(int p, int ant){
	if(p==n+1) return 0;

	int &ret = dp[p][ant];
	if(ret!=-1) return ret;

	if(v[p]<=v[ant]) return ret = lis(p+1, ant);
	return ret = max(lis(p+1, ant), 1+lis(p+1, p));
}

ll rec(int p, int ant){
	if(p==n+1) return 1;

	ll &ret = dp2[p][ant];
	if(ret != -1) return ret;

	if(v[p]<=v[ant]) return ret = rec(p+1, ant);
	int l1 = lis(p+1, ant), l2 = 1+lis(p+1, p);
	
	if(l1<l2) return ret = rec(p+1, p);
	if(l1>l2) return ret = rec(p+1, ant);
	return ret = (rec(p+1, p) + rec(p+1, ant))%MOD;

}

int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i=0;i <=n+1; i++) for(int j=0; j<=n+1; j++)
			dp[i][j] = -1, dp2[i][j]=-1;
		
		v.clear();	
		v.pb(0);
		for(int i=0; i<n; i++){
			int a; cin >> a; v.pb(a);
		}
		int tam = lis(1, 0);
		
		int ans = rec(1, 0);
		cout << tam << " " << ans << endl;
	}
	
	exit(0);
}
