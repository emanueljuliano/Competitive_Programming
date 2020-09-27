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
		int n, k, z; cin >> n >> k >> z;
		vector<int> v(n);
		for(auto &i:v) cin >> i;
		if(k==0){
			cout << v[0] << endl;
			continue;
		}

		ll ans = 0;
		ll at = v[0];
		vector<int> pref;
		pref.pb(0);
		for(int i=0;i <n; i++) pref.pb(pref[i]+v[i]);
	//	for(auto x : pref) cout << x << " "; cout << endl;
		for(int i=0;i <n-1; i++){
			int a = v[i], b = v[i+1];
			k--; at+=b;
			if(!k){ans = max(ans, at); break;}
			if(z<(k+1)/2){
				ll curr = z*a+z*b + pref[i+k-2*z+2]-pref[i+2];
			//	cout << i << ": at " << at << " " << curr << endl;;
			//	cout << z*a+z*b << " " << pref[i+k-2*z+1] << endl;
				ans = max(ans, at+curr);
			}
			else{
				ll curr = (k+1)/2*a + (k/2)*b;
			//	cout << i << ": " << k << " val: " << curr << endl;;
				ans = max(ans, at+curr);
			}
		}
		cout << ans << endl;
	
	}
	
	
	
	exit(0);
}
