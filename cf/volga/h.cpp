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
	
	int n; cin >> n;
	vector<ll> v(n);
	for(auto & i : v) cin >> i;
	int ans = 2;
	for(int i=0;i <n-1; i++){
		vector<ll> dis;
		if(i)for(int j=i-1; j>=0; j--) dis.pb(v[i]-v[j]);
		for(int j=i+1; j<n; j++){
			int curr = 2;
			ll d = v[j]-v[i];
			
			if(i){
				int loo = lower_bound(dis.begin(), dis.end(), d) - dis.begin();
				if(loo<dis.size() and dis[loo]==d) continue;
			}
			
			ll at = v[j];
			while(true){
				int lo = lower_bound(v.begin(), v.end(), d+at) - v.begin();
				if(lo>=n) break;
				if(v[lo]!=at+d) break;
				curr++;
				at = v[lo];
			}
			ans = max(ans, curr);
		}
	}
	cout << ans << endl;
	
	
	exit(0);
}
