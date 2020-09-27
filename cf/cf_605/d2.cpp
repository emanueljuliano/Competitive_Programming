#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define inf 0x3f3f3f3f
typedef long long ll;
 
vector<ll> v;
int n;
int dp[100100];
int rec(ll x, bool flag, int acumulado){ // flag  true = ja removeu
	if(x>n-1) return acumulado;
	if(dp[x]!= -1) return dp[x];
	if(v[x+1]>v[x]) return dp[x] = rec(x+1, flag, acumulado+1);
	
	if(flag) return dp[x] = max(acumulado, rec(x+1, flag, 1));

	if(v[x+2] > v[x] and x>0 and v[x+1]>v[x-1])
	 return dp[x] = max(rec(x+1, flag, 0), max(rec(x+2, true, acumulado), max( acumulado, rec(x+1, true, acumulado))));
	
	return dp[x] = max(acumulado, rec(x+1, flag, 1));
}
 
int main(){ _
	memset(dp, -1, sizeof(dp));
	ll a;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a;
		v.pb(a);
	}
	v.pb(inf);
	v.pb(inf);
 
	int ans = rec(0, false, 1);
	for(int i=0; i<n; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
	exit(0);
}
