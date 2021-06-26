#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back
#define sq(x) ll(x)*ll(x)

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		ll n, m; cin >> n >> m;
		double ans = 1e15;
		if(gcd(n, m)==1) ans = sqrt(sq(n) + sq(m));
		for(int i=1;i <n; i++){
			for(auto shift : {-1, 1}){
				int nx = double(m)/n*i+shift+1e-7;
				if(gcd(i, nx)==1 and gcd(n-i, m-nx)==1){
					double d = sqrt(sq(i) + sq(nx)) + sqrt(sq(n-i) + sq(m-nx)); 
					ans = min(ans, d);
				}
			}
		}
		cout << setprecision(9) << fixed;
		cout << ans << endl;
	}
		
	exit(0);
}
