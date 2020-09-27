#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
const int MOD = 1e9+7;

ll n, m;
ll pd[1010][12];
ll rec(ll val, ll pos){
	if(pd[val][pos]>0) return pd[val][pos];
	
	ll ans = 0;
	if(pos==m){
		ans = n-val+1;
		return (ans)*(ans+1)/2 %MOD;
	}
	for(int i=val; i<=n; i++){
		ans = (ans)%MOD + ((i-val+1)*rec(i, pos+1))%MOD;
		ans %= MOD;
	}
	pd[val][pos] = ans%MOD;
	return ans%MOD;
}	

int main(){ _
	memset(pd, -1, sizeof(pd));
	
	cin >> n>>m;

	cout << rec(1, 1)%MOD << endl;

	exit(0);
}
