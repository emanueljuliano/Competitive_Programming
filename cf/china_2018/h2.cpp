#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(v) v.begin(), v.end()

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _

	int n; cin >> n;

	vector<int> vatk;
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

	ll ans = LINF, cans;
	
	vector<int> order(n);
	iota(all(order), 0);

	vector<int> good_order;

	do {
		cans = 0, cur = 0;
		for(int id : order) {
			auto [hp, atk] = v[id];
			cur += hp;
			cans += cur * atk;
		}
		if(cans < ans) 
			good_order = order;
		ans = min(ans, cans);
	} while(next_permutation(all(order)));

	/*cout << "order: " << endl;
	for(int i : good_order) 
		cout << v[i].first << ' ' << v[i].second << endl;
	cout << endl;
	*/
	cout << ans << endl;

	return 0;
}

/*
* RECADOS PRA MIM

- Prove ideias e complexidade
- Fique tranquilo e tente várias abordagens
- Entenda bem o statement e os samples
*/
