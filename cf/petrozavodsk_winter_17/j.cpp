#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MOD = 1e9+7;
const int MAX = 2e5+10;

ll pref[MAX][22], suf[MAX][22];
vector<ll> ans, v;
int M;

void solve(vector<tuple<int, int, int>> &q, int l, int r) {
	if (l == r) {
		for (auto [li, ri, id] : q)
			ans[id] = v[l] == 0;
		return;
	}

	int m = (l+r)/2;
	vector<tuple<int, int, int>> ql, qr;
	for (auto [li, ri, id] : q) {
		if (ri <= m)
			ql.emplace_back(li, ri, id);
		else if (li >= m+1)
			qr.emplace_back(li, ri, id);
	}
	solve(ql, l, m), solve(qr, m+1, r);

	for (int i=0; i<M; i++) {
		pref[m+1][i] = v[m+1] == i;
		suf[m][i] = v[m] == i;
	}
	for (int i=m+2; i<=r; i++) {
		for (int j=0; j<M; j++) {
			pref[i][j] = (pref[i-1][j] + pref[i-1][(j-v[i]+M)%M])%MOD;
		}
		pref[i][v[i]] = (pref[i][v[i]] + 1)%MOD;
	}
	for (int i=m-1; i>=l; i--) {
		for (int j=0; j<M; j++) {
			suf[i][j] = (suf[i+1][j] + suf[i+1][(j-v[i]+M)%M])%MOD;
		}
		suf[i][v[i]] = (suf[i][v[i]] + 1)%MOD;
	}
	for (auto [li, ri, id] : q) {
		if (li <= m and m+1 <= ri) {
			ans[id] = (suf[li][0] + pref[ri][0])%MOD;
			for (int i=0; i<M; i++) {
				ans[id] = (ans[id] + suf[li][i]*pref[ri][(M-i)%M])%MOD;
			}
		}
	}
}

int main(){ _
	int n; cin >> n >> M;	
	v.resize(n);
	for (auto &i : v) cin >> i, i%=M;
	
	int q; cin >> q;
	vector<tuple<int, int, int>> query(q);
	for (int i=0; i<q; i++) {
		int l, r; cin >> l >> r; l--, r--;
		query[i] = {l, r, i};
	}
	
	ans.resize(q);
	solve(query, 0, n-1);

	for (int i=0; i<q; i++)
		cout << ans[i]+1 << endl;

	exit(0);
}
