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
	int n, m; cin >> n >> m;
	ll ans = 0;
	n-=3; m--;
	int at =0;
	if(n<=2*m) at = min(2*m+1-n, n+1);
	// n-i <= m from 0 to m
	// 2m >= n
	ans += at;
	for(int i=1; i<=m; i++){
		n--;
		if(n<=2*m) ans+= min(2*m+1-n, n+1);
	}
	cout << ans << endl;
	
	
	
	exit(0);
}
