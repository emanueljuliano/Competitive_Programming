#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(v) v.begin(), v.end()

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
	int t; cin >> t;
	int cs = 0;
	while(t--){
		cs++;
		cout << "Case #" << cs << ": ";
		int n; cin >> n;

		vector<ll> vatk;
		ll cur = 0;
		for(int i = 0; i < 1e5; i++) {
			cur += i;
			vatk.push_back(cur);
			if(cur > 1e5) break;
		}

		vector<pair<ll,ll>> v(n);
		for(auto& [hp, atk] : v) {
			cin >> hp >> atk;
			hp = lower_bound(all(vatk), hp) - vatk.begin();
		}

		sort(all(v), [&] (pair<ll,ll> a, pair<ll,ll> b) {
				auto [hpa, atka] = a;
				auto [hpb, atkb] = b;
				return atka*hpb > atkb*hpa;
				});

		/*cout << "v" << endl;
		  for(auto [hp, atk] : v) 
		  cout << hp << ' ' << atk << endl;
		 */
		ll ans = 0;
		cur = 0;
		for(auto [hp, atk] : v) {
			cur += hp;
			ans += cur * atk;
		}

		cout << ans << endl;
	}
	return 0;
}

/*
* RECADOS PRA MIM

- Prove ideias e complexidade
- Fique tranquilo e tente várias abordagens
- Entenda bem o statement e os samples
*/
