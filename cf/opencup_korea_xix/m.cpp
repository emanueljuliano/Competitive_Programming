#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 1e6*3e5;

const int MAX = 3e5+10;

pair<ll, ll> dp[MAX][2];
vector<pair<ll, ll>> g[MAX];

pair<ll, ll> solve(int i, ll cost, bool peguei = false, int p=0) {
	auto &[a1, a2] = dp[i][peguei];
	if(a2 != -1) return {a1, a2};
	a1 = 0, a2 = 0;
	if(peguei) {
		for (auto [u, c] : g[i]) if(u != p) {
			auto [b1, b2] = solve(u, cost, 0, i);
			a1 += b1, a2 += b2;
		}
		return {a1, a2};
	}

	vector v(2, vector<pair<ll, ll>>());

	ll at1=0, at2=0;
	for (auto [u, c] : g[i]) if(u != p) {
		{
			auto [b1, b2] = solve(u, cost, 0, i);
			v[0].push_back({b1, b2});
			at1+=b1, at2+=b2;
		}
		{
			auto [b1, b2] = solve(u, cost, 1, i);
			b2++, b1 += c-cost;
			v[1].push_back({b1, b2});
		}
	}
	if(at1>a1 or (at1==a1 and at2<a2)) 
		a1 = at1, a2 = at2;
	
	for (int j=0;j <v[0].size(); j++) {
		auto [b1, b2] = v[1][j];
		b1 -= v[0][j].first, b2 -= v[0][j].second;
		b1 += at1, b2 += at2;
		if(b1>a1 or (b1==a1 and b2<a2)) a1 = b1, a2 = b2;
	}

	return {a1, a2};
}

int n;
ll solve2(int m) {
	ll l = -LINF, r = LINF;
	ll ans = LINF;
	while (l <= r) {
		for(int i=0;i <n; i++) for(int j=0; j<2; j++) dp[i][j] = {-LINF, -1};

		ll lambda = (l+r)/2;
		auto [q, cnt] = solve(0, lambda);
		if (cnt <= m) {
			r = lambda-1;
			ans = q + m*lambda;
		}
		else {
			l = lambda+1;
		}
	}
	return ans;
}

int dp2[MAX][2];
int check(int i, int p, bool peguei) {
	int &ret = dp2[i][peguei];
	if(ret != -1) return ret;
	if(peguei){
		ret = 0;
		for(auto [u, c] : g[i]) if(u != p) 
			ret += check(u, i, 0);
		return ret;	
	}

	int tot = 0;
	for(auto [u, c] : g[i]) if(u != p) tot += check(u, i, 0);
	ret = tot;

	for(auto [u, c] : g[i]) if(u != p) {
		int a = 1+check(u, i, 1);
		int b = check(u, i, 0);
		int at = tot-b+a;
		ret = max(ret, at);
	}
	return ret;
}


int main(){ _
	int m; cin >> n >> m;
	
	for (int i=0; i<n-1; i++) {
		int a, b, c; cin >> a >> b >> c; a--, b--;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}

	for (int i=0; i<n; i++) for (int j=0; j<2; j++) dp2[i][j] = -1;
	auto a1 = check(0, 0, 0);
	if(a1<m) return cout << "Impossible" << endl, 0;

	ll ans = solve2(m);	
	cout << ans << endl;

	exit(0);
}
