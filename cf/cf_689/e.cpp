#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
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
	if(k/x >= t) return cout << "YES" << endl, 0;
	if(y>r) return cout << "NO" << endl, 0;
	if(y<=x){
		if(__int128(k) -__int128(x)*t + __int128(y)*(t-1) < __int128(0)) 
			return cout << "NO" << endl, 0;	
		return cout << "YES" << endl, 0;	
	}
	r = min(r, k+2LL*y);

	// k-x*c <= r-y
	// k+y-r <= x*c
	set<ll> st;
	ll it = 0;
	while(it<t){
		ll c = (k+y-r+x-1)/x;
		c = min(max(c, 1LL), t-it);
		if(__int128(k) - __int128(x)*c < __int128(0)) 
			return cout << "NO" << endl, 0;
		k -= x*c;
		it+=c;
		if(st.count(k)) break;
		st.insert(k);
		if(k+y<=r) k += y;
	}
	
	cout << "YES" << endl;	
	
	exit(0);
}
