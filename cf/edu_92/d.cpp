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
		ll n, k; cin >> n >> k;
		ll l1, r1; cin >> l1 >> r1;
		ll l2, r2; cin >> l2 >> r2;
		ll at = n*(min(r1, r2) - max(l1, l2));
		if(k<=at){cout << 0 << endl; continue;}
		ll ans = LINF;
		if(at>=0){ // intersecta
//			cout << "inter"  << endl;
			ll inter = at/n;
			ll range = (max(r1, r2)-min(l1, l2)); 
			if((ll)n*range >=k){
				cout << k-at << endl;
			}
			else{
				cout << 2*(k-n*range)+n*(range-inter) << endl;
			}
			continue;
		}
		at =0;
		for(int i=0;i <n; i++){
//			cout << "not inter"  << endl;
			ll dist = max(l1, l2) - min(r1, r2);
			ll range = (max(r1, r2)-min(l1, l2)); 
			if(k<=range){
				ans = min(ans, dist+at+k);
				break;
			}
			k -= range;
			at += dist+range;
			ans = min(ans, at+2*k);
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
