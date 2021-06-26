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

const int MAX = 1100;
ll dp[2][MAX][MAX];
int x[MAX], y[MAX];
ll t[MAX], r[MAX];

/*
 f(i, s1, s2) = min(f(i-1, s1, s2), f(i-1, s1-x[i], s2)), f(i-1, s1, s2-y[i])
*/

int main(){ _
	int n, S1, S2; cin >> n >> S1 >> S2;
	
	vector<int> ord(n);
	for(int i=0;i <n; i++){
		cin >> x[i] >> t[i] >> y[i] >> r[i];
		ord[i] = i;
	}	
	memset(dp, INF, sizeof dp);
	sort(ord.begin(), ord.end(), [&](int a, int b){
		if(x[a]!=x[b]) return x[a]<x[b];
		return y[a]<y[b];
	});

	dp[n&1][0][0] = 0;
	for(int i=n-1;i+1; i--){
		for(int s1 = S1; s1+1; s1--){
			for(int s2 = S2; s2+1; s2--){
				auto &ret = dp[i%2][s1][s2];
				ret = dp[~i&1][s1][s2];
				ret = min(ret, dp[~i&1][s1][s2]);
				ret = min(ret, dp[~i&1][s1][max(0, s2-y[ord[i]])] + r[ord[i]]);
				
				ret = min(ret, dp[~i&1][max(0, s1-x[ord[i]])][s2] + t[ord[i]]);
				if(s1 != 0){
					int res = max(0, x[ord[i]]-s1);
					ret = min(ret, dp[~i&1][max(0, s1-x[ord[i]])][max(0, s2-res)] + t[ord[i]]);
				}
				//cout << "i: " << i << " s1: " << s1 << " s2: " << s2 << " ret: " << ret << endl;
			}
		}
	}
	
	ll ans = dp[0][S1][S2];
	if(ans>=LINF) cout << -1 << endl;
	else cout << ans << endl;
	
	exit(0);
}
