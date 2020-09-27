#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back

typedef long long ll;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int MAX = 200200;

ll soma[MAX];
int n;

ll seg[4*MAX], lazy[4*MAX];
ll build(int p=1, int l=0, int r=n-1){
	lazy[p] = 0;
	if(l==r) return seg[p] = soma[l];
	int m = (l+r)/2;
	return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
}

void prop(int p, int l, int r){
	if(!lazy[p]) return;
	int m = (l+r)/2;
	seg[2*p] += lazy[p];
	seg[2*p+1] += lazy[p];
	lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
	lazy[p] = 0;
}

ll query(int a, int b, int p=1, int l=0, int r=n-1){
	if(b<l or r<a) return linf;
	if(a<=l and r<=b) return seg[p];
	prop(p, l, r);
	int m = (l+r)/2;
	return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}

ll update(int a, int b, ll x, int p=1, int l=0, int r=n-1){
	if(b<l or r<a) return seg[p];
	if (a<=l and r<=b){
		seg[p] += (ll)x;
		lazy[p] += x;
		return seg[p];
	}
	prop(p, l, r);
	int m = (l+r)/2;
	return seg[p] = min(update(a, b, x, 2*p, l, m)
			, update(a, b, x, 2*p+1, m+1, r));
}

int main(){ _
	vector<ll> a(MAX);
	vector<int> ind(MAX);
	
	cin>>n;
	for(int i=1; i<=n; i++){
		int a; cin >> a;
		ind[a] = i;
	}
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}

	soma[0] = a[1];
	for(int i=1; i<n; i++){
		soma[i] = a[i+1] + soma[i-1];
	}
	build();

	ll ans = min(a[1], a[n]);
	for(int i=1; i<n+1; i++){
		update(1, ind[i]-1, a[ind[i]], 1, 1, n);
		update(ind[i], n, -a[ind[i]], 1, 1, n);
		ll q = query(1, n-1, 1, 1, n);
		ans = min(ans, q);
	}

	cout << ans << endl;
	
	exit(0);
}
