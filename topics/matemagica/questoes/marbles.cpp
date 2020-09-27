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
	while(true){
		ll n; cin >> n;
		if(n==0) break;
		ll c1, n1; cin >> c1 >> n1;
		ll c2, n2; cin >> c2 >> n2;
		
		bool flag = false;
		if(c1*n2 > c2*n1) {swap(c1, c2), swap(n2, n1); flag=true;}

		ll ans1 = n/n1;
		ll at = n - ans1*n1;
		if(ans1*n1!= n and at%n2!=0 and at%__gcd((int)n1, (int)n2)==0){
			while(ans1--){
				at+=n1;
				if(at%n2==0) break;
			}	
		}
		if(at%n2==0){
			if(!flag) cout << ans1 << " " << at/n2 << endl;	
			else cout  << at/n2 << " " << ans1 <<endl;	
		}
		else cout << "failed" << endl;
	}	
	
	
	
	exit(0);
}
