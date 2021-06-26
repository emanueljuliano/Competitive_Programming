#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

const int INF = 0x3f3f3f3f;
const int MAX = 3.5e4 + 10;

int n;

struct Seg {
	int seg[4*MAX], lazy[4*MAX];
	int *v;
	Seg () {}
	int build(int p, int l, int r) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build(1, 0, n-1);
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p];
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	int query(int a, int b, int p, int l, int r) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return INF;
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
	int update(int a, int b, int x, int p=1, int l=0, int r=n) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = min(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}
};

Seg S[105];
int dp[105][MAX];


int main(){ _
	int n, k; cin >> n >> k;
	
	vector<int> v(n), nxt(n), last(n, -1), first(n, -1);
	for (auto &i : v) cin >> i, i--;
	
	for (int i=n-1; i+1; i--) {
		if (last[v[i]] != -1) nxt[i] = last[v[i]];
		else nxt[i] = i;
		last[v[i]] = i;
	}
	
	for (int i = n-1; i+1; i--) {
		dp[1][i] = dp[1][i+1] + (nxt[i]-i);
		S[1].update(i, i, dp[1][i], 1, 0, n);
	}
	
	for (int i=n-1; i+1; i--) {
		for (int j = 2; j<=k; j++) {
			S[j-1].update(nxt[i]+1, n, nxt[i]-i, 1, 0, n);
			dp[j][i] = S[j-1].query(i+1, n, 1, 0, n);
			S[j].update(i, i, dp[j][i], 1, 0, n);
		}
	}
	
	cout << dp[k][0] << endl;
	
	exit(0);
}
