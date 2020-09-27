#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

	int n, m; cin >> n >> m;
	vector<int> in(n), out(m);
	for(int i=0; i<n; i++) cin >> in[i];
	for(int i=0; i<m; i++) cin >> out[i];

	map<int,int> mp;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) if(out[j] >= in[i]) {
			int dif = out[j] - in[i];
			mp[dif]++;
		}
	}

	int ans = 0, maxi=-1;
	for(auto u : mp) {
		if(u.s > maxi or (u.s == maxi and u.f < ans)) {
			maxi = u.s;
			ans = u.f;
		}
	}

	cout << ans << endl;

	return 0;
}

