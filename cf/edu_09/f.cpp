#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 3e3+10;
const int MOD = 1e9+7;

int l[MAX], r[MAX];
ll dp[MAX][MAX];
int n;
ll solve(int i, int j) {
	if (i == n) return 1;
	if (j == n) return 0;

	ll &ret = dp[i][j];
	if (ret != -1) return ret;

	ret = solve(i, j+1);
	if (l[j] < i and i < r[j]) ret = (ret + solve(i+1, j))%MOD;

	return ret;
}


int main(){ _
	memset(dp, -1, sizeof dp);

	cin >> n;
	vector<int> h(n);
	for (auto &i : h) cin >> i;
		
	stack<pair<int, int>> stk;
	stk.push({-INF, -1});
	for (int i=0; i<h.size(); i++) {
		while(stk.top().first > h[i]) stk.pop();
		l[i]=stk.top().second;
		stk.push({h[i], i});
	}
	while(stk.size()) stk.pop();
	stk.push({-INF, n});
	for (int i=h.size()-1; i+1; i--) {
		while(stk.top().first > h[i]) stk.pop();
		r[i]=stk.top().second;
		stk.push({h[i], i});
	}

//	for (int i=0;i <n; i++) cout << i << " " << l[i] << " " << r[i] << endl;

	cout << solve(0, 0) << endl;
	
	exit(0);
}
