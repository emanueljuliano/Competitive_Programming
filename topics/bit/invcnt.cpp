#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

const int MAX = 1e5+10;

int n;
ll bit[MAX];
vector<int> v;

void build() {
	bit[0] = 0;
	for (int i = 1; i <= n; i++) bit[i] = v[i - 1];

	for (int i = 1; i <= n; i++) {
		int j = i + (i & -i);
		if (j <= n) bit[j] += bit[i];
	}
}

void update(int p, ll x) {
	for (; p <= n; p += p & -p) bit[p] += x;
}

ll pref(int p) {
	ll ret = 0;
	for (; p; p -= p & -p) ret += bit[p];
	return ret;
}

ll query(int a, int b) {
	return pref(b) - pref(a - 1);
}

int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> n;
		v.resize(n, 0);
		build();
		
		vector<int> w(n), hel(n);
		map<int, int> mp;
		int ptr = 1;
		
		for(auto &u:hel) cin >> u;
		w = hel;
		sort(hel.begin(), hel.end());
		for(auto u : hel) mp[u]=ptr++;

		ll ans = 0;
		for(auto u : w){
			ans += query(mp[u], n);
			update(mp[u], 1);
		}
		cout << ans << endl;
	
	}

	exit(0);
}
