#include<bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define read(x) for(auto& qw : (x)) cin >> qw;

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll a, b, n, k;
ll memo [5002][5002];
ll pref [5002];
const int MOD = 1e9+7;

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>a>>b>>k;

	for(ll y=1; y<=n; y++) if(y!=b) memo[k][y] = 1;
	for(ll x = k-1; x>=0; x--){
		for(ll y=1; y<=n; y++) pref[y] = (pref[y-1]+memo[x+1][y])%MOD;
		
		for(ll y=1; y<=n; y++){
			int l = max(1LL, y-abs(b-y)+1);
			int r = min(n, y+abs(b-y)-1);
			memo[x][y] = pref[r]-pref[l-1] - memo[x+1][y];
			memo[x][y] = (memo[x][y]%MOD+MOD)%MOD;
		}
	}

	cout<< memo[0][a] <<endl;
	return 0;
}
