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
		ll n, k; cin >> n >> k;
		ll sum = 0;
		ll ans = 0;
		vector<ll> v(n);
		for(int i=0;i <n; i++){
			cin >> v[i];

			if(i!=0){	
				ll cur = (v[i]*100 + k -1)/k;
				ans = max(ans, cur-sum);
			}
			sum += v[i];
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
