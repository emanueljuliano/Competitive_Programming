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
		
	int a, b, c; cin >> a >> b >> c;
	int ans = gcd(a, b);
	ans = gcd(ans, c);
	cout << ans << endl;
	
	
	exit(0);
}