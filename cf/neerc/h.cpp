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
	ll n, m; cin >> n >> m;
	ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	ll ans = 0;
	ans += (x1-1)*(m%2);
	ans += ((y1-1)%2)*(x2-x1+1);
	ans += ((m-y2)%2)*(x2-x1+1);
	ans += (n-x2)*(m%2);
	cout << (ans+1)/2 << endl;
	
	
	exit(0);
}
