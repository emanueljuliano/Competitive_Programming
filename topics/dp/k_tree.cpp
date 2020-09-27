#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
const int MOD = 1e9+7;

int pd[110];
int pd2[110];
int n, k, d;
ll rec(int n2){
	if(n2==0) return 1;
	if(n2<0) return 0;
	if(pd[n2] !=-1) return pd[n2];
	ll ret=0;
	for(int i=1; i<=k; i++){
		ret = (ret+rec(n2-i))%MOD;
	}
	return pd[n2] = ret%MOD;
}

ll rec2(int n2){
	if(n2==0) return 1;
	if(n2<0) return 0;
	if(pd2[n2] !=-1) return pd2[n2];
	ll ret=0;
	for(int i=1; i<d; i++){
		ret = (ret+rec2(n2-i))%MOD;
	}
	return pd2[n2]= ret;
}


int main(){ _
	
	memset(pd, -1, sizeof(pd));
	memset(pd2, -1, sizeof(pd2));
	cin >> n >> k >> d;
	ll ans = rec(n);
	ans = (ans-rec2(n)+MOD)%MOD;
	cout << ans << endl;
	
	exit(0);
}
