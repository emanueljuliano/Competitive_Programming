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

ll dp[100][100];

ll rec(int x, int maxi){
	//if(dp[x]!=-1) return dp[x];
	if(x<0) return 0;
	if(x==0 or x==1 or maxi==1) return 1;
	return rec(x, maxi-1) + rec(x-maxi, maxi);
}

int main(){ _
	memset(dp, -1, sizeof(dp));
	ll n; cin >> n;	
	ll ans = 1;
	for(ll i=2; i*i<=n; i++) if(n%i==0){
		int at = 0;
		while(n%i==0) n/=i, at++; 
		ans *= rec(at, at);
	}
	cout << ans << endl;	
	
	exit(0);
}
