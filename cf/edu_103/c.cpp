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
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<ll> c(n), a(n), b(n);
		for(auto &i : c) cin >> i;
		for(auto &i : a) cin >> i;
		for(auto &i : b) cin >> i;
		vector<ll> v, w;

		v.pb(abs(a[1]-b[1])+1);
		for(int i=1; i<n-1; i++){
			v.pb(c[i]);
			if(a[i+1]==b[i+1]) v.pb(-LINF), v.pb(1);
			else v.pb(-abs(a[i+1]-b[i+1])+1);
		}
		v.pb(c[n-1]);

		ll ans = 0;
		ll cur = 0;
		for(auto u : v){
			//cout << u << " ";
			if(cur+u>=0) cur+=u;
			else cur = 0;
			ans = max(ans, cur);
		}
		
		cur = c[n-1];
		for(int i=n-1; i>1; i--){
			ans = max(ans, cur+abs(a[i]-b[i])+1);
			if(a[i]==b[i]) cur = c[i-1];
			else cur = max(cur+c[i-1]-abs(a[i]-b[i])+1, c[i-1]);
		}
		ans = max(ans, cur+abs(a[1]-b[1])+1);
		
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
