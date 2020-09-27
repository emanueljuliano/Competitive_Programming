#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define FOR(i,a,n) for(int i=a;i<n;i++)

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int t; cin >> t;
	while(t--) {
		multiset<ll> meuset;
		vector<ll> somas;
		int n, k; cin >> n >> k;

		vector<int> v(n);
		FOR(i,0,n) cin >> v[i];

		
		vector<pair<ll, bool> > minmax(n);

		for(int i = 0; i < n; i+=2) {
			ll a1 = v[i], a2 = v[n-1-i];
			somas.pb(a1 + a2);
			meuset.insert(a1+a2);
			minmax[i] = {min(a1, a2) + 1, 0};
			minmax[i+1] = {max(a1, a2) + k, 1};
		}

		sort(minmax.begin(), minmax.end());
		sort(somas.begin(), somas.end());

		ll counter = 0;
		ll mx = 0, mn = 0;
		ll res = LINF;
		for(int i = 0; i < n; i++) {
			if(minmax[i].s == 0) {
				mn = minmax[i].f;
				counter++;
			}	else {
				mx = minmax[i].f;

				ll mudar = counter + (((n/2) - counter) * 2);

				ll maior_numero = 0;
				auto pos_min = lower_bound(somas.begin(), somas.end(), mn);
				auto pos_max = upper_bound(somas.begin(), somas.end(), mx);
				for(int j = pos_min - somas.begin(); j < (pos_max - somas.begin()); j++) {
					maior_numero = max(maior_numero, (ll)meuset.count(somas[j]));
				}
				mudar -= maior_numero;
				res = min(res, mudar);

				counter--;
			}
		}

		cout << res << endl;
	}

	return 0;
}
