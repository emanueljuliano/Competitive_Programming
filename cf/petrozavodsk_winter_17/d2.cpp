#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 2e5+10;

ll T[MAX], A[MAX], dp[MAX];
int n;

int main(){ _
	while (cin >> n) {
		vector<pair<int, int>> v(n);
		for (int i=0; i<n; i++){
			cin >> T[i] >> A[i];
		}	
	
		// dp[i] = tempo que terminou o prefixo 0...i
		// dp[i] = min (para j < i) de {max(dp[j], T[i]) + 2*A[j+1]}
	
		dp[0] = T[0] + 2*A[0];
		for (int i = 1; i < n; i++) {
			dp[i] = INF;
			ll at = A[i];
			for (int j=i-1; j>=0; j--) {
				dp[i] = min(dp[i], max(dp[j], T[i]) + 2*at);
				at = max(at, A[j]);
			}
			dp[i] = min(dp[i], T[i]+2*at);
		}

		cout << dp[n-1] << endl;	
	}	
	
	exit(0);
}
