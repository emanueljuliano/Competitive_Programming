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
	ll k, l, r, t, x, y; cin >> k >> l >> r >> t >> x >> y;
	k-=l, r-=l, l-=l;

	if(k+y<=r) k += y;
	// burro
	for(int i=0;i <t; i++){
		k -= x;
		if(k<0) return cout << "NO" << endl, 0;
		if(k+y<=r) k += y;
	}
	
	cout << "YES" << endl;	
	
	exit(0);
}
