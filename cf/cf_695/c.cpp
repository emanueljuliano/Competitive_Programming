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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n1, n2, n3; cin >> n1 >> n2 >> n3;
	vector<vector<int>> v;
	vector<int> w1(n1), w2(n2), w3(n3);
	for(auto &i : w1) cin >> i;	
	for(auto &i : w2) cin >> i;	
	for(auto &i : w3) cin >> i;	
	v.pb(w1), v.pb(w2), v.pb(w3);
	for(int i=0;i <3; i++) sort(v[i].begin(), v[i].end());

	ll tot = 0;
	vector<ll> mini(3), sum(3);
	for(int i=0;i <3; i++) mini[i] = v[i][0];
	for(int i=0;i <3; i++) for(auto u : v[i]) sum[i]+=u, tot+=u;

	sort(mini.begin(), mini.end());
	sort(sum.begin(), sum.end());

	ll ans = tot - 2*min(mini[0]+mini[1], sum[0]);

	cout << ans << endl;

	
	exit(0);
}
