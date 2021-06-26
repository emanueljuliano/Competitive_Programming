#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e4+10, MAX_CAP = 1e4+10;

int V[MAX], w[MAX]; // valor e peso
int dp[2][MAX_CAP];

// DP usando os itens [l, r], com capacidade = cap
void get_dp(int x, int l, int r, int cap) {
	memset(dp[x], 0, (cap+1)*sizeof(dp[x][0]));
	for (int i = l; i <= r; i++) for (int j = cap; j >= 0; j--)
		if (j - w[i] >= 0) dp[x][j] = max(dp[x][j], V[i] + dp[x][j - w[i]]);
}

void solve(vector<int>& ans, int l, int r, int cap) {
	if (l == r) {
		if (w[l] <= cap) ans.push_back(l);
		return;
	}
	int m = (l+r)/2;
	get_dp(0, l, m, cap), get_dp(1, m+1, r, cap);
	int left_cap = -1, opt = -INF;
	for (int j = 0; j <= cap; j++)
		if (int at = dp[0][j] + dp[1][cap - j]; at > opt)
			opt = at, left_cap = j;
	solve(ans, l, m, left_cap), solve(ans, m+1, r, cap - left_cap);
}

vector<int> knapsack(int n, int cap) {
	vector<int> ans;
	solve(ans, 0, n-1, cap);
	return ans;
}


int main() { _
	int n, x, y; cin >> n >> x >> y;
	vector<pair<int, int>> v(n);
	int ma = -1, soma = 0;
	for (auto& [a, b] : v) {
		cin >> a >> b;
		ma = max(ma, b);
		if (a > x or b > y) return cout << "impossible" << endl, 0;
		soma += a;
	}
	if (soma <= x) return cout << -1 << endl, 0;
	int sobra = y - ma;
	int baixo = 0;
	vector<pair<int, int>> vv;
	for (auto [a, b] : v) {
		if (b > sobra) { // tem que ficar em baixo
			//cout << a << " " << b << " tem que ficar em baixo" << endl;
			baixo += a;
		} else vv.emplace_back(a, b);
	}

	v = vv;
	n = v.size();
	int tot = 0;
	for (int i = 0; i < n; i++) {
		V[i] = w[i] = v[i].first;
		tot += V[i];
	}

	auto ans = knapsack(n, x - baixo);
	for (int i : ans) tot -= V[i];

	if (tot > x) return cout << "impossible" << endl, 0;
	cout << ma << endl;

	exit(0);
}
