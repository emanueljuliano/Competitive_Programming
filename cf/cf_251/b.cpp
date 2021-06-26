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
	ll n, x; cin >> n >> x;	
	vector<ll> v(n);
	for(auto &i : v) cin >> i;
	sort(v.begin(), v.end());

	ll ans = 0;
	for(int i=0;i <n; i++){
		ans += v[i]*x;
		x = max(1LL, x-1);
	}

	cout << ans << endl;
	
	
	exit(0);
}
