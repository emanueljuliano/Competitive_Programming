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
		int x, y, z; cin >> x >>y >> z;
		if(x!=y and x!=z and z!=y){
			cout << "NO" << endl;
		}
		else if(x > y and x>z){
			cout << "NO" << endl;
		}
		else if(y > x and y>z) cout << "NO" << endl;
		else if(z>x and z>y) cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			cout << max({x, y, z}) << " " << min({x, y, z}) << " " << min({x, y, z}) << endl;
		}
	}
	
	
	
	exit(0);
}
