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
const int MAX = 4e5+10;
ll seg[4*MAX], lazy[4*MAX];
int n;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = 0;
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void prop(int p, int l, int r) {
		if (!lazy[p]) return;
		int m = (l+r)/2;
		seg[2*p] += lazy[p]*(m-l+1);
		seg[2*p+1] += lazy[p]*(r-(m+1)+1);
		lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		prop(p, l, r);
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (b < l or r < a) return seg[p];
		if (a <= l and r <= b) {
			seg[p] += (ll)x*(r-l+1);
			lazy[p] += x;
			return seg[p];
		}
		prop(p, l, r);
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}

int main(){ _
	int t; cin>> t;
	while(t--){
		int m, k; cin >> m>> k;
		n = 2*k+10;
		vector<int> v;
		for(int i=0;i <m; i++){
			int a; cin >> a;
			v.pb(a);
		}
		build();
		for(int i=0;i <m/2; i++){
			int s = v[i] + v[m-i-1];
			int ma = max(v[i]+k, v[m-i-1]+k);
			int mi = min(v[i]+1, v[m-i-1]+1);
			update(s+1, ma, -1);
			update(mi, s-1, -1);
			update(ma+1, n, -2);
			update(2, mi-1, -2);
		}
		int ans = -INF;
		for(int i=2; i<=2*k; i++){
			int q = query(i, i);
			ans = max(ans, q);
		}
		cout << -ans << endl;
	}
	
	
	
	exit(0);
}
