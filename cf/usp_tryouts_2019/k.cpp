#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;
	vector<ll> v(n);
	for (auto &i : v) cin >> i;
	v.push_back(LINF);
	sort(v.begin(), v.end());
	ll at = 0;
	for (auto u : v) {
		if (u > at + 1) return cout << at + 1 << endl, 0;
		at += u;
	}
	
	
	exit(0);
}
