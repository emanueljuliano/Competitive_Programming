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
	int t; cin >>t ;
	vector<ll> v;
	v.pb(0);
	v.pb(1);
	for(ll i=2; i<=(ll)2e5; i++){
		v.pb(v[i-1] + i);
	}
	while(t--){
		ll n, k; cin >> n>> k;
		int  at = lower_bound(v.begin(), v.end(), k) - v.begin();
		ll x = v[at]-k;
		string ans;
		ans.pb('b');
		for(int i=at+1; i<n; i++){
			ans.pb('a');
		}
		string ans2;
		for(int j=0; j<at; j++){
			if(j==x) ans2.pb('b');
			else ans2.pb('a');
		}
		reverse(ans.begin(), ans.end());
		ans += ans2;
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
