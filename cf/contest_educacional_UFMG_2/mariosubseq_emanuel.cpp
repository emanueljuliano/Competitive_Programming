#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

const int MAX = 1e5+10;

int seg[2 * MAX];
int n = 0;
const int MOD = 1e9+7;

int query(int a, int b) {
	int ret = 0;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret += seg[a], ret%=MOD;
		if (b % 2 == 0) ret += seg[b], ret%=MOD;
	}
	return ret;
}

void update(int p, int x) {
	seg[p += n] += x, seg[p]%=MOD;
	while (p /= 2) seg[p] = (seg[2*p] + seg[2*p+1])%MOD;
}

int main(){ _
	int n2;
	cin >> n2;
	vector<int> v(n2);
	for(auto &u : v) cin >> u, n = max(n, u+1);
	
	for(int i=n2-1; i+1; i--) {
		update(v[i], 1 + query(v[i], n-1));
	}

	int ans = 0;
	for(int i=0; i<n; i++) ans = (ans+seg[i+n])%MOD;
	cout << ans << endl;

	exit(0);
}
