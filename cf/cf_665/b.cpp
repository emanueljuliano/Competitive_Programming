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
		vector<int> v(3), w(3);
		for(auto &u: v) cin >> u;
		for(auto &u: w) cin >> u;
	
		int at = min(w[1], v[2]);
		
		ll ans = 2*at;
		v[2] -= at;
		w[1] -= at;

		at = min(w[2], v[2]);
		w[2] -= at;
		v[2] -= at;
		
		at = min(w[2], v[0]);
		w[2] -= at;
		v[0] -= at;

		at = min(w[2], v[1]);
		ans -= 2*at;
		cout << ans << endl;


	}
	
	
	
	exit(0);
}
