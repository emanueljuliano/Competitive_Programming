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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<ll> v(n);
		for(auto &i : v) cin >> i;
		vector<ll> dp(n);

		for(int i=n-1; i+1; i--){
			if(i+v[i]>=n) dp[i]=v[i];
			else dp[i]=v[i]+dp[i+v[i]];
		}

		ll ans = 0;
		for(int i=0;i <n; i++) ans = max(ans, dp[i]);
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
