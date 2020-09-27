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
ll MOD;
ll pd[40][40];
ll d;
ll rec(int n, int b){
	ll &ans = pd[n][b];
	if(ans!=-1) return ans;
	
	ans = 0;
	if(n==0 and b==0) return ans = 1;
	if(n==0 and b!=0) return ans;
	if(b<n) return ans;
	for(int i=0; i<b; i++){
		ans = (ans + rec(n-1, i))%MOD;
	}
	rec(n-1, b);
	ll mul;
	if(1<<b > d){ mul = (d+1 - (1<<(b-1)))%MOD;}
	else mul = ((1<<b) - (1<<(b-1)))%MOD;
	//cout << n<< " " << b << " " << ans << " " << mul << endl;
	ans = ans*mul%MOD;
	return ans;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		memset(pd, -1, sizeof(pd));
		int at = -1;
		ll m; cin >> d >> m;
		MOD = m;
		for(int i=0;i <=d; i++){
			if(1<<i > d) at = i;
			if(at!=-1) break;
		}
		rec(at, at);


		ll ans = 0;
		for(int i=1;i<=at; i++){
			for(int j=1; j<=at; j++){
				if(pd[i][j]!=-1) ans = (ans+pd[i][j])%MOD;
			}
		}
	/*	for(int i=1; i<=at; i++){
			for(int j=1; j<=at; j++)
				cout << pd[i][j] << " ";
			cout << endl;
		}
*/

		cout << ans << endl;
	}
	
	
	exit(0);
}
