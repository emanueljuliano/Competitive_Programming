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

const int MOD = 998244353;
int n; vector<int> v;
ll fat[1020];
ll dp[1020];

ll fexp(ll a, ll b){
	if(b==0) return 1;
	if(b%2) return a*fexp(a, b-1)%MOD;
	return fexp(a*a%MOD, b/2);
}

ll inv(ll x){
	return fexp(x, MOD-2);
}

ll esc(ll a, ll b){
	return fat[a]*inv(fat[b])%MOD*inv(fat[a-b])%MOD;
}

ll rec(int p){
	if(p< 0 or p+v[p]>n) return 0;
	if(dp[p]!=-1) return dp[p];
	ll &ret = dp[p] = 1;
	
	for(int i=p+v[p]+1;i<n; i++){
		ret += esc(i-(p+1), v[p])*rec(i)%MOD; 
	}
	return ret%MOD;
}

void fato(){
	fat[0] = 1;
	for(int i=1;i <1010; i++){
		fat[i] = fat[i-1]*i%MOD;
	}
}

int main(){ _
	fato();
	cin >> n;
	for(int i=0;i <n; i++){
		int a; cin >> a; v.pb(a);
	}
	ll ans = 0;
	for(int i=0;i <n; i++){
	//	for(int j=i; j<n; j++) dp[j] = -1;
		ans = (ans+rec(i))%MOD;
	}
	cout << max(ans-1, 0ll) << endl;
	
	
	exit(0);
}
