#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;

const int MAX = 330;
int dp[MAX][MAX];
char M[MAX][MAX];

int calc(ii p1, ii p2){
	p1.f++, p1.s++;
	return dp[p1.f][p1.s] - dp[p1.f][p2.s] - dp[p2.f][p1.s]+ dp[p2.f][p2.s];
}

int main(){ _
	while(true){
		int n, m, x;
		cin >> n >> m >> x;
		if(!n) break;
		for(int i=0;i <n; i++) for(int j=0; j<m; j++)
			cin >> M[i][j];

		for(int i=1; i<=n; i++) for(int j=1; j<=m; j++)
			dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + (M[i-1][j-1]=='.');

		int ans = n*m;
		for(int i=0;i <n; i++) for(int j=0; j<m; j++){
			for(int k=0; k<=j; k++){
				if(calc({i, j}, {0, k}) < x) break;
				int l = 0, r = i;
				while(l<r){
					int mm = (l+r+1)/2;
					if(calc({i, j}, {mm, k}) >= x) l = mm;
					else r = mm-1;
				}
				ans = min(ans, (i-l+1)*(j-k+1));
			}
		}
	
		cout << ans << endl;
	}
	exit(0);
}
