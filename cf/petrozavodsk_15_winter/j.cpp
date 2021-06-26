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
	int n; cin >> n;
	vector<int> v(n);
	int sum =0;
	for(auto &i : v) cin >> i, sum+=i;
	if(sum!=2*n-2) return cout << 0 << endl, 0;
	
	ll ans = 1;
	const int MOD = 1e9+7;
	for(int i=1; i<=n-2; i++) ans = (ans*i)%MOD;

	for(auto u : v) if(u>2) ans = ans*((MOD+1)/2)%MOD;

	cout << ans << endl;
	
	
	
	
	exit(0);
}
