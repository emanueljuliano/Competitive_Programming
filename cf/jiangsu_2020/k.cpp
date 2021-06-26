#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e6+10;
const int MOD = 1e9+7;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}


int main(){ _
	int n; cin >> n;
	vector<string> v(n);
	vector<int> q(MAX);
	for (auto &i : v) {
		cin >> i;
		for (int j=0; j<i.size(); j++) if (i[j] == '1') q[j]^=1;
	}
	
	vector<ll> P(MAX);
	ll h = 0, at = 1, p = uniform(MAX, MOD-1);
	
	for (int i=0; i<MAX; i++) {
		if (q[i]) h = (h + at) % MOD;
		P[i] = at;
		at = at * p % MOD;
	}

	int ans = 0;
	for (int i=0; i<n; i++) {
		ll h2 = 0, rem = 0;
		for (int j=v[i].size()-1; j; j--) {
			h2 = h2 * p % MOD;
			if (v[i][j] == '1') {
				h2 = (h2+1)%MOD;
				if (q[j] == 1) rem = (rem + P[j]) % MOD;
				else rem = (rem - P[j] + MOD) % MOD;
			}
			if (h2 == (h - rem + MOD) % MOD) {
				//cout << i << " " << j << endl;
				ans++;
			}
		}
	}

	cout << ans << endl;

	exit(0);
}
