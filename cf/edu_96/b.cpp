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
		int n, k; cin >> n >> k;
		vector<int> v(n);
		for(auto &i:v) cin >> i;
		sort(v.begin(), v.end(), greater<>());

		ll ans = v[0];
		for(int i=1; i<=k; i++) ans += v[i];
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
