#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e5+10;
const int MOD = 1e9 + 7;
ll inv[MAX];

int main(){ _
	#warning FILE IN 
    freopen("lcm.in", "r", stdin);	

	inv[1] = 1;
	for (int i = 2; i < MAX; i++) inv[i] = MOD - MOD/i*inv[MOD%i]%MOD;

	vector<vector<int>> divisores(MAX);
	for (int i=1; i<MAX; i++) for (int j=2*i; j<MAX; j+=i)
		divisores[j].push_back(i);

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(n);
		vector<vector<int>>div(MAX);
		vector<map<int, ll>> mp(n);

		for (int i=0; i<n; i++) {
			cin >> v[i];
			for (int j=1; j*j<=v[i]; j++) if (v[i]%j == 0){
				div[j].push_back(i);
				if (j != v[i]/j) div[v[i]/j].push_back(i);
			}
		}
		for (int i=1; i<MAX; i++) if (div[i].size()) {
			ll sum = 0;
			for (auto u : div[i]) sum += v[u];
			for (auto u : div[i]) mp[u][i] = sum;
		}
		
		ll ans = 0;
		for (int i=MAX-5; i>=1; i--) if (div[i].size()) {
			ll at = 0;
			for (auto u : div[i]) {
				ll sum = mp[u][i];
				at = (at + sum * v[u] % MOD) % MOD;
				if(sum) for (auto p : divisores[i]) mp[u][p] -= sum;
			}
			ans = (ans + at*inv[i]  % MOD) % MOD ;	
		}

		cout << ans << endl;
	}
	
	
	exit(0);
}
