#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10;

ll T[MAX], A[MAX], dp[MAX], seg[2*MAX];
int n;

void build() {
	for (int i = 0; i < 2*n; i++) seg[i] = LINF;
}

ll query(int a, int b) {
	ll ret = LINF;
	for (a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret = min(ret, seg[a]);
		if (b % 2 == 0) ret = min(ret, seg[b]);
	}
	return ret;
}

void update(int p, ll x) {
	seg[p += n] = x;
	while (p /= 2) seg[p] = min(seg[2*p], seg[2*p+1]);
}

int main(){ _
	while (cin >> n) {
		vector<pair<int, int>> v(n);
		for (auto &[t, a] : v) cin >> t >> a;
		
		vector<pair<int, int>> stk;
		for (auto [t, a] : v) {
			while(stk.size() and stk.back().second <= a) stk.pop_back();
			T[stk.size()] = t, A[stk.size()] = a;
			stk.push_back({t, a});
		}
		
		n = stk.size();
		build();
	
		// dp[i] = tempo que terminou o prefixo 0...i
		// dp[i] = min (para j < i) de {max(dp[j], T[i]) + 2*A[j+1]}
	
		dp[0] = T[0] + 2*A[0];
		update(0, dp[0]);
		int it = 0;
		for (int i = 1; i < n; i++) {
			update(i-1, dp[i-1] + 2*A[i]);
			
			dp[i] = T[i] + 2*A[0];
			while (dp[it] < T[i]) it++;
			if (it) dp[i] = min(dp[i], T[i] + 2*A[it]);
			if (it >= i) dp[i] = min(dp[i], T[i]+2*A[i]);
			else dp[i] = min(dp[i], query(it, i-1));
		}
		
		cout << dp[n-1] << endl;	
	}	
	
	exit(0);
}
