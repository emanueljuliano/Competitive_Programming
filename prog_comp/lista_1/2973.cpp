#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;

int n, c, t;
vector<int> v;

bool val(int m){
	ll at = ll(t)*m;
	int ret = 1;
	for(int i=0; i<n; i++){
		if((ll)v[i]>ll(t)*m) return false;
		if(at>=v[i]) at -=v[i];
		else{
			ret++;
			at = (ll)t*m;
			i--;
		}
	}
	return ret<=c;
}

int bb(int l, int r){
	if(l==r) return l;
	int m = (l+r)/2;
	if(val(m)) r = m;
	else l = m+1;
	return bb(l, r);
}

int main(){ _
	cin >> n >> c >> t;
	for(int i=0; i<n; i++){
		int a; cin >> a; v.pb(a);	
	}

	int ans = bb(0, (int)1e9 + 10);
	
	cout << ans << endl;

	exit(0);
}
