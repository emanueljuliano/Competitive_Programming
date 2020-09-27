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

const int N = 302345;

int t[4*N];
int a[N];

void build(int i, int l, int r) {
	if (l == r) {
		t[i] = a[l];
	} else {
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		t[i] = max(t[2*i], t[2*i+1]);
	}
}

int query(int i, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return t[i];
	if (qr < l || r < ql) return 0;
	int m = (l+r)/2;
	return max(query(2*i, l, m, ql, qr), query(2*i+1, m+1, r, ql, qr));
}

void update(int i, int l, int r, int p, int x) {
	if (l == r) {
		t[i] = x;
	} else {
		int m = (l+r)/2;
		if (p <= m) update(2*i, l, m, p, x);
		else update(2*i+1, m+1, r, p, x);
		t[i] = max(t[2*i], t[2*i+1]);
	}
}

int main(){ _
	int n; cin >> n;
	vector<int> w, v(300010);
	for(int i=1; i<=n; i++){
		cin >> a[i];
		v[a[i]] = i;
	}
	for(int i=0; i<n; i++){
		int x; cin >> x; w.pb(x);
	}
	
	build(1, 1, n);
	cout << n << " ";
	for(int i=0; i<n-1; i++){
		int q1 = query(1, 1, n, 1, w[i]);
		int pos = v[q1];
		update(1, 1, n, pos, 0);
		int ans = query(1, 1, n, 1, n);
		cout << ans << " ";
	}
	cout << endl;
	exit(0);
}
