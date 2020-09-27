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
		int x, n, m; cin >> x >> n >> m;
		bool flag = false;
		while(n){
			if(x>=20){
				n--;
				x/=2;
				x+=10;
			}
			else break;
		}
		x -= 10*m;
		if(x>0) cout << "NO" << endl;
		else cout << "YES" << endl;
	
	}
	
	
	
	exit(0);
}
