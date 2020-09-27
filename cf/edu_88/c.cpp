#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int c, h;
ld val(int m){
	ld ret = 0;
	int dif = m/2;
	ret = ((ld)c*dif + (ld)h*(dif+1))/(ld)m;
	return ret;
}

ld x;
int bb(int l, int r){
	if(abs(l-r)<4){
		int ret = l;
		ld at= INF; ld q=INF;
		for(int i=l; i<=r; i++){
			if(i%2) q = val(i);
			if(abs(q-x) < abs(at-x)) ret = i, at = q;
		}
		return ret;
	}

	int mid = (l+r)/2;
	if(mid%2==0) mid++;

	ld q = val(mid);
	if(q<x) r = mid;
	else l = mid;
//	cout << l << " " << r << " " << q << endl;
	return bb(l, r);
}

int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> h >> c >> x;
		if(2*x<=h+c){
			cout << 2 << endl;
			continue;
		}
		ld at = h;
		int ans = bb(1, (int)1e9+1);
		cout << ans << endl;	
	}
	
	
	
	exit(0);
}
