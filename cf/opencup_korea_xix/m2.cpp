#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2.5e5+10;

vector<pair<int, ll>> g[MAX];
pair<ll, int> dp[MAX][2];

pair<ll, int> soma(pair<ll, int> a, pair<ll, int> b) {
	return {a.first+b.first, a.second+b.second};
}

pair<ll, int> sub(pair<ll, int> a, pair<ll, int> b) {
	return {a.first-b.first, a.second-b.second};
}

void dfs(ll lambda, int i=0, int p=-1) {
	dp[i][0] = {0, 0};
	for (auto [j, c] : g[i]) if (j != p) {
		dfs(lambda, j, i);
		dp[i][0] = soma(dp[i][0], dp[j][1]);
	}
	dp[i][1] = dp[i][0];
	for (auto [j, c] : g[i]) if (j != p) {
		auto atual = sub(dp[i][0], dp[j][1]);
		atual = soma(atual, dp[j][0]);
		dp[i][1] = max(dp[i][1], soma({c - lambda, -1}, atual));
	}
}

int main() { _
	int n, k; cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int a, b, c; cin >> a >> b >> c; a--, b--;
		g[a].emplace_back(b, c), g[b].emplace_back(a, c);
	}
	ll l = 0, r = (ll) n * (1e6+10);
	dfs(-r);
	if (-dp[0][1].second < k) return cout << "Impossible" << endl, 0;
	l = -r;
	ll ans = r;
	while (l <= r) {
		ll lambda = (l+r)/2;
		ll m = lambda;
		dfs(lambda);
		auto [val, at] = dp[0][1];
		at *= -1;
		if (at > k) l = m+1;
		else {
			ans = val + lambda*k;
			r = m-1;
		}
	}
	cout << ans << endl;
	exit(0);
}

