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

ll dp[50][2];
int n;
ll f(int pos, int ant){
	if(pos==n) return 0;
	ll &ret = dp[pos][ant];
	if(ret!=-1) return ret;

	ret = f(pos+1, 0);
	if(ant) ret += (1LL<<(n-pos-1));
	else ret += f(pos+1, 1);
	return ret;
};
	

int main(){ _
	while(cin >> n){
		ll tot = 1LL<<n;
		for(int i=0;i <=n; i++) dp[i][0]=-1, dp[i][1]=-1;
		ll num = tot-f(0, 0);
		ll g = __gcd(num, tot);
		cout << num/g << "/" << tot/g << endl;
	}
	
	exit(0);
}
