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
		int n, x, y, d; cin >> n >> x >> y >> d;
		if(abs(y-x)%d==0) cout << abs(y-x)/d << endl;
		else if((y-1)%d==0 or (n-y)%d==0){
			int a1 = (x-1+d-1)/d + y/d;
			int a2 = (n-x+d-1)/d + (n-y)/d;
			if((n-y)%d) cout << a1 << endl;
			else if((y-1)%d) cout << a2 << endl;
			else cout << min(a1, a2) << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
	
	
	
	exit(0);
}
