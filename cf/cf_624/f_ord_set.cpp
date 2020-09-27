#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

int main(){ _
	//ord_set		
	int n; cin >> n;
	vector<ll> x(n), v(n);
	for(int i=0;i <n; i++) cin >> x[i];
	for(int i=0;i <n; i++) cin >> v[i];
		
	vector<pair<ll, ll>> p;
	for(int i=0; i<n; i++) p.pb({x[i], v[i]});

	sort(p.begin(), p.end());
	ll ans = 0;
	ord_set<pair<ll, ll>> s;

	for(int i=0; i<n; i++){
		ll cnt = s.order_of_key({p[i].s, p[i].f});
		ans+= p[i].f * cnt;
		s.insert({p[i].s, p[i].f});
	}
	s.clear();
	for(int i=n-1; i>=0; i--){
		ll cnt = s.order_of_key({-p[i].s, -p[i].f});
		ans -= p[i].f * cnt;
		s.insert({-p[i].s, -p[i].f});
	}

	cout << ans << endl;

	exit(0);
}
