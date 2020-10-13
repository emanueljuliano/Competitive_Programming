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
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n;
		n--;
		ll x = sqrt(n);
		ll ans = INF;
		if(!n){cout << 0 << endl; continue;}
		for(int i=-1; i<4; i++){
			ll y = x+i;
			if(!y) continue;
			ans = min(ans, y + (n-y)/y);
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
