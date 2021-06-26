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
		ll w, h, n; cin >> w >> h >> n;
		ll p2 = 0;
		while(w>0 and w%2==0) w/=2, p2++;
		while(h>0 and h%2==0) h/=2, p2++;
		if((1LL<<p2) >= n) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	exit(0);
}
