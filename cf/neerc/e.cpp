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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 3e5+10;
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
		seg[2*p] = lazy[p];
		seg[2*p+1] = lazy[p];
		lazy[2*p] = lazy[p], lazy[2*p+1] = lazy[p];
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
			seg[p] = (ll)x;
			lazy[p] = x;
			return seg[p];
		}
		prop(p, l, r);
		int m = (l+r)/2;
		seg[p] = 0;
			update(a, b, x, 2*p, l, m);
			update(a, b, x, 2*p+1, m+1, r);
	}
int main(){ _
	n; cin >> n;
	vector<int> v;
	vector<vector<int>> g(MAX);
	for(int i=0;i <n; i++){
		int a; cin >> a;
		v.pb(a);
		g[a].pb(i);
	}
	
	int m; cin >> m;
	vector<int> q;
	for(int i=0;i <m; i++){
		int a; cin >> a; q.pb(a);
	}
	build();	
	for(int i=0;i <m; i++){
		int mini = -1, maxi = -1;
		for(int j=0;j <g[q[i]].size(); j++){
			int pos = g[q[i]][j];
			if(query(pos, pos)==0){
				if(mini==-1) mini = pos;
				maxi = pos;
			}
		}
		if(mini!=-1 and maxi!=-1) update(mini, maxi, q[i]);
	}
	for(int i=0;i <n; i++){
		ll x = query(i, i);
		if(x==0) cout << v[i] << " ";
		else cout << x << " ";
	}
	cout << endl;
	
	exit(0);
}
