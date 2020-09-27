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
	vector<ll> v;
	for(int i=0;i <n; i++) {
		ll a; cin >> a;
		v.pb(a);
	}
	ll ans = 0;
	if(n==1) ans = v[0];
	if(n==2) ans = v[0]|v[1];
	for(int i=0;i <n; i++){
		for(int j=i+1; j<n; j++){
			for(int k=j+1; k<n; k++){
				ans = max(ans, v[i]|v[j]|v[k]);	
			}
		}
	}
	cout << ans << endl;
	
	
	
	exit(0);
}
