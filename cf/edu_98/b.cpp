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


int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		ll sum=0, mx=-1;
		for(auto &i:v) cin >> i, sum+=i, mx=max(mx, (ll)i);

		ll ans = max((sum+n-2)/(n-1), mx);
		cout << ans*(n-1)-sum << endl;
	}
	
	
	
	exit(0);
}