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


int main(){ _
	int n; cin >> n;
	vector<ii> v(n);
	for(auto &[a, b] : v) cin >> a >> b;

	sort(v.begin(), v.end(), [](ii a, ii b){
		if(a.s != b.s) return a.s<b.s;
		return a.f>b.f;
	});
	
	ll ans = 0, at = 0;
	for(auto [a, b] : v){
		if(at < a) ans += a-at, at = a-b;
		else at -= b;
	}
	
	cout << ans << endl;

	exit(0);
}
