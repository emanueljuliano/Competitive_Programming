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


int main(){ _
	int t; cin >> t;
	while(t--){
		ll a, b, x, y, n; cin >> a >> b >> x >> y >> n;
		if(a>b) swap(a, b), swap(x, y);
		if(a-x>=n) cout << (a-n)*b << endl;
		else{
			n -= (a-x);
			ll a1 = x*max(b-n, y);

			ll a2;
			n += (a-x);
			if(b-y>=n) a2 = ((b-n)*a);
			else {
				n -= (b-y);
				a2 = y*max(x, a-n);
			}
			cout << min(a1, a2) << endl;
		}
	}
	
	
	
	exit(0);
}
