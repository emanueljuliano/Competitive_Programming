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

const int MAX = 2e5+10;
int n;
struct segtr {
	vector<ii> seg;
	vector<int>v;
	void build(int p=1, int l=0, int r=n-1) {
		if (l == r) {seg[p] = {v[l], 0}; return;}
		int m = (l+r)/2;
		build(2*p, l, m); build(2*p+1, m+1, r);
		seg[p] = {0, 0};
	}
	int query(int a, int p=1, int l=0, int r=n-1) {
		if (a == l and a == r) return seg[p].f + seg[p].s;
		if (a < l or r < a) return 0;
		int m = (l+r)/2;
		if(a<=m) return seg[p].f + (a-l+1)*seg[p].s + query(a, 2*p, l, m);
		else return seg[p].f + (a-l+1)*seg[p].s + query(a, 2*p+1, m+1, r);
	}
	void update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) {seg[p].s += x, seg[p].f+=max(0, l-a)*x; return;}
		if (b < l or r < a) return;
		int m = (l+r)/2;
		update(a, b, x, 2*p, l, m);
		update(a, b, x, 2*p+1, m+1, r);
	}
};

int main(){ _
	int m; cin >> n>> m;

	segtr sx, sy;
	sx.seg.resize(4*n), sy.seg.resize(4*n);
	sx.v.resize(n), sy.v.resize(n);

	for(int i=0; i<n; i++) sx.v[i]=i+1;
	for(int i=0; i<n; i++) sy.v[i]=0;
	sx.build(), sy.build();

	while(m--){
		int f; cin >> f;
		if(f==1){
			int l, r; cin >> l >> r; l--, r--;
			if(l==r) continue;
			int x1 = sx.query(l);
			int x2 = sx.query(r);
			if(x1!=x2){ // hor
				sy.update(l+1, r, 1);
				sx.update(l+1, r, -1);
			}
			else{ // vert
				sy.update(l+1, r, -1);
				sx.update(l+1, r, 1);
			}
		}
		else{
			int a; cin >> a; a--;
			int x = sx.query(a);
			int y = sy.query(a);
			cout << x << " " << y << endl;
		}
	}	
	
	exit(0);
}
