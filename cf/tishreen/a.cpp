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
		ll n, x; cin >> n >> x;
		vector<ll> p10(17);
		p10[0] = 1; for(int i=1; i<=16; i++) p10[i] = 10LL*p10[i-1];
		ll ans = 0;
		for(int i=0; i<=15; i++){
			if(p10[i] < x/10) continue;
			else {
				if((p10[i+1]-x)*(i+1) > n){
					if(n%(i+1)!=0) ans = -1;
					else ans += n/(i+1);
					break;
				}
				ans += p10[i+1]-x;
				n -= (p10[i+1]-x)*(i+1);
				x = p10[i+1];
			}
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
