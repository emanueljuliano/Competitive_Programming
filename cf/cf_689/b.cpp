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
		int n, m; cin >> n>> m;
		vector M(n, vector(m, char()));
		vector dp(n, vector(m, int()));
		vector l(n, vector(m, int()));
		vector r(n, vector(m, int()));
		for(int i=0;i <n; i++) for(int j=0; j<m; j++) cin >> M[i][j];
		for(int i=0; i<n; i++){
			int it = 0;
			for(int j=0; j<m; j++){
				if(M[i][j]=='.') it = j+1;
				else l[i][j] = it;
			}
			it = m-1;
			for(int j=m-1; j+1; j--){
				if(M[i][j]=='.') it = j-1;
				else r[i][j] = it;
			}
		}
		ll ans = 0;
		for(int i=0;i <m; i++) dp[0][i] = M[0][i]=='*', ans +=dp[0][i];
		//for(int i=0;i <n; i++) dp[i][0] = M[i][0]=='*', ans +=dp[i][0];
		//for(int i=0;i <n; i++) dp[i][m-1] = M[i][m-1]=='*', ans +=dp[i][m-1];

		for(int i=1; i<n; i++) for(int j=0; j<m; j++) if(M[i][j]=='*')
			dp[i][j] = min({dp[i-1][j], j-l[i][j], r[i][j]-j}) + 1,
			ans += dp[i][j];
		cout << ans << endl;

	}
	
	
	
	exit(0);
}
