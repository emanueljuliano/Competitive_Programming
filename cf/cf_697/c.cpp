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
	int t; cin >> t;
	while(t--){
		int a, b, k; cin >> a >> b >> k;
		vector<int> v(k), w(k), fa(a+1), fb(b+1);
		for(auto &i : v) cin >> i, fa[i]++;
		for(auto &i : w) cin >> i, fb[i]++;
		
		ll ans = 0;
		for(int i=0; i<k; i++){
			ans += k-fa[v[i]] -fb[w[i]]+1;
		}

		cout << ans/2 << endl;
	}

	
	
	
	exit(0);
}
