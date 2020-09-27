#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
set <ll> se;
ll n, k;
ll val(ll x){
	if(se.count(x)) return 0;
	se.insert(x);
	if(x>n) return 0;
	if(x==n) return 1;
	if(x%2==1) return 1 + val(2*x);
	return 2 + val(2*x) + val(2*x + 2);
}

ll bbp(ll i, ll j){
	ll m = (i+j)/2;
	//cout << i << " " << j << " " << val(m) << endl;
	if(j<=i+3){
		se.clear();
		if(val(j+2)>=k)
			return j+2;
		se.clear();
		if(val(j+1)>=k)
			return j+1;
		se.clear();
		if(val(j)>=k)
			return j;
		se.clear();
		if(val(j-1)>=k)
			return j-1;
		se.clear();
		if(val(j-2)>=k)
			return j-2;
		se.clear();
		if(val(j-3)>=k)
			return j-3;
		se.clear();
		if(val(j-4)>=k) return j-4;
	}
	se.clear();
	bool flag=false;
	if(m%2!=0) flag = true;
	if(flag) m--;		
	if(val(m) <k) return bbp(i, m);
	se.clear();
	if(flag) m+=2;
	ll a = val(m);
	se.clear();
	ll b = val(m+2);
	se.clear();
	if (a > k) return bbp(m, j);
	if(a == b) return bbp(m+2, j);
	return m;
}
ll bbi(ll i, ll j){
	if(j<=i+3){
		se.clear();
		if(val(j+2)>=k)
			return j+2;
		se.clear();
		if(val(j+1)>=k)
			return j+1;
		se.clear();
		if(val(j)>=k)
			return j;
		se.clear();
		if(val(j-1)>=k)
			return j-1;
		se.clear();
		if(val(j-2)>=k)
			return j-2;
		se.clear();
		if(val(j-3)>=k)
			return j-3;
		se.clear();
		if(val(j-4)>=k) return j-4;
	}
	se.clear();
	ll m = (i+j)/2;
	bool flag=false;
	if(m%2!=0) flag = true;
	if(flag) m--;		
	if(val(m) <k) return bbi(i, m);
	se.clear();
	if(flag) m+=2;
	ll a = val(m);
	se.clear();
	ll b = val(m+2);
	se.clear();
	if (a > k) return bbi(m, j);
	if(a == b) return bbi(m, j);
	return m;
}

int main(){ _

	cin >> n >> k;
	if (k==n){cout << 1 << endl; exit(0);}
	cout << max(bbp(1, n), bbi(1, n)) << endl;

	exit(0);
}
