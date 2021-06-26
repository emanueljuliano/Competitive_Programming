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
		int n, p, k; cin >> n >> p >> k;
		string s; cin >> s;
		ll x, y; cin >> x >> y;
		ll ans = LINF;
		vector<ll> pref(n);
		for(int i=0; i<k; i++){
			pref[n-1-i] = (s[n-1-i]=='0')*x;
			for(int j=n-1-i-k; j>=0; j-=k) pref[j] = pref[j+k] + (s[j]=='0')*x;
		}

		ll acum = 0;
		for(int i=p-1;i <n; i++){
			ans = min(ans, acum+pref[i]);
			acum+=y;
		}

		cout << ans << endl;
	}
	
	
	
	exit(0);
}
