#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

const int INF = 0x3f3f3f3f;
const int MAX = 3.5e4 + 10;

namespace Seg {
	pair<int, int> seg[4*MAX], lazy[4*MAX];
	int n;
	pair<int, int> *v;
	pair<int, int> build(int p, int l, int r) {
		lazy[p] = {0, 0};
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, pair<int, int>* v2) {
		n = n2, v = v2;
		build(1, 0, n-1);
	}
	void prop(int p, int l, int r) {
		auto [x, cnt] = lazy[p];
		seg[p].first += x, seg[p].second += cnt;
		if (l != r) {
			lazy[2*p].first += x, lazy[2*p+1].first += x;
			lazy[2*p].second += cnt, lazy[2*p+1].second += cnt;
		}
		lazy[p] = {0, 0};
	}
	pair<int, int> query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return {INF, INF};
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	pair<int, int> update(int a, int b, pair<int, int> x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p].first += x.first;
			lazy[p].second += x.second;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = min(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}
};

pair<int, int> dp[MAX];
int nxt[MAX];

int solve(int n, int k) {
	int l = 0, r = 4e8;
	int ans = INF;
	while (l <= r) {	
		int lambda = (l+r)/2;
		//cout << lambda << endl;
		for (int i=0; i<=n; i++) dp[i] = {0, 0};
		Seg::build(n+1, dp);

		for (int i=n-1; i+1; i--) {
			Seg::update(nxt[i]+1, n, {nxt[i]-i, 0});
			dp[i] = Seg::query(i+1, n);
			dp[i].first += lambda, dp[i].second++;
			Seg::update(i, i, dp[i]);
		}
		
		auto [res, cnt] = dp[0];
		//cout << res << " " << cnt << endl;	
		if (cnt <= k) {
			ans = res - k*lambda;
			r = lambda-1;
		}
		else l = lambda+1;
	}
	return ans;
}

int main(){ _
	int n, k; cin >> n >> k;
	
	vector<int> v(n), last(n, -1), first(n, -1);
	for (auto &i : v) cin >> i, i--;
	
	for (int i=n-1; i+1; i--) {
		if (last[v[i]] != -1) nxt[i] = last[v[i]];
		else nxt[i] = i;
		last[v[i]] = i;
	}
	
	int ans = solve(n, k);
	cout << ans << endl;
	
	exit(0);
}
