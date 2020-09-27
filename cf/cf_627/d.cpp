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
		vector<int> v, w;
		ll n; cin >> n;
		for(int i=0; i<n; i++){
			int a; cin >> a;v.pb(a);
		}
		for(int i=0; i<n; i++){
			int a; cin >> a;w.pb(a);
		}
		vector<int> dif;
		for(int i=0;i <n; i++){
			dif.pb(v[i]-w[i]);
		}
		sort(dif.begin(), dif.end());

		ll ans = 0;
		for(int i=0; i<n; i++){
			ll up= upper_bound(dif.begin(), dif.end(), -dif[i]) - dif.begin();
			ans += n-up;
			if(dif[i]>0) ans--;
		}
		
		
		cout << ans/2 << endl;

	
	
	
	exit(0);
}
