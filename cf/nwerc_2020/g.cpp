#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 5e3+10; 
ld dp[MAX][55];

int n, r, m, mx=0;
vector<tuple<int, ld, int>> ev;

ld solve(int T, int i) {
	if (T >= r-n) return LINF;
	if (i >= ev.size()) return 0;
	if ((T != 0 or i != 0) and dp[T][i] > -1) 
		return dp[T][i];

	auto [t, p, d] = ev[i];
	ld ret = p * (t + solve(T, i + 1));
	ret += (1-p) * (t + min(dp[0][0], d + solve(T + d, i + 1)));
	
	return dp[T][i] = ret;
}

int main(){ _
	cin >> n >> r >> m;
	
	int cur = 0;
	for (int i=0; i<m; i++) {
		int t, d; ld p;
		cin >> t >> p >> d;
		ev.emplace_back(t-cur, p, d);
		cur = t;
	}
	ev.emplace_back(n-cur, 1, 0);
	
	ld L = 0, R = 1e9;
	for (int i=0; i<70; i++) {
		for (int j=0; j<MAX; j++) for (int k=1; k<55; k++)
			dp[j][k] = -5;
		ld M = (L+R)/2;
		dp[0][0] = M;
		solve(0, 0);
		if (dp[0][0] > M) L = M;
		else R = M;
	}
	cout << setprecision(9) << fixed;
	cout << dp[0][0] << endl;	
	
	exit(0);
}
