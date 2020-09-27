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
	ll l, r, x, y, k; cin >> l >> r >> x >> y >> k;

	ll a1 = ((k+l-1)/k*k);
	if(a1>r) return cout << "NO" << endl, 0;

	// k = a/x
	if(k*x>=l and k*x<=r) return cout << "YES" << endl, 0;
	// k = a1/b
	if(a1/k>=x and a1/k<=y) return cout << "YES" << endl, 0;

	cout << "NO" << endl;
	exit(0);
}
