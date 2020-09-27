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

ll g(ll x){
	if(x%2==0) return x/2;
	return g(x/2);
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		ll ans = 0;
		for(int i=0;i <n; i++){
			ll x; cin >> x;
			ans ^= g(x);
		}
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	exit(0);
}
