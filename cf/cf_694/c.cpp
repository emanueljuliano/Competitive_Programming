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
ll n;
int cnt = 0;
ll query(int x){
	cnt++;
	assert(cnt<1000);
	x = (x%n);
	if(x==0) x = n;
	cout << "? " << x << endl;
	ll ret; cin >> ret;
	return ret;
}

int main(){ _
	ll k; cin >> n >> k;
	ll x;
	int it = 0;
	int l = -1, r=-1;
	for(int i=1;i <=3*n; i+=it){
		x = query(i+it);
		it++;
		if(x>k) {l = i, r=i+it; break;}
	}

	while(l<r){
		int m = (l+r)/2;
		ll q = query(m);
		if(q<k) l = m+1;
		else r = m;
	}
	l%=n;
	if(l==0) l = n;
	cout << "! " << l << endl;
	
	
	
	exit(0);
}
