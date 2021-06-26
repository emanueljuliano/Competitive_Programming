#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		vector<int> v(n);
		for(auto &i : v) cin >> i;
		sort(v.begin(), v.end());
		ll ans = 0;
		if(k) ans = v.back();
		ll at = 0;
		for(int i=0;i <n-k; i++) at += v[i];
		ans = max(ans, at);
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
