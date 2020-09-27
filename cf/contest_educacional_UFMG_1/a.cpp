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
	ll n, m, k, l; cin >> n >> m >>k >> l;
	if (n - (l+k+m-1)/m*m >= 0) cout << (l+k+m-1)/m << endl;
	else cout << -1 << endl;
	
	exit(0);
}
