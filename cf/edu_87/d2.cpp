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

const int MAX = (int)1e6+100;
int n = MAX-10;
int t[4*MAX];
int v[MAX];

void build(int i=1, int l=0, int r=n) {
	if (l == r) {
		t[i] = v[l];
	} else {
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		t[i] = t[2*i] + t[2*i+1];
	}
}

int query(int ql, int qr, int i=1, int l=0, int r=n) {
	if (ql <= l && r <= qr) return t[i];
	if (qr < l || r < ql) return 0;
	int m = (l+r)/2;
	return query(ql, qr, 2*i, l, m)
		+ query(ql, qr, 2*i+1, m+1, r);
}

void update(int p, int x, int i=1, int l=0, int r=n) {
	if (l == r) {
		t[i] += x;
	} else {
		int m = (l+r)/2;
		if (p <= m) update(p, x, 2*i, l, m);
		else update(p, x, 2*i+1, m+1, r);
		t[i] = t[2*i] + t[2*i+1];
	}
}

int q2(int x, int i=1, int l=0, int r=n){
	if(l==r) return l;
	int m = (l+r)/2;
	int q = t[2*i];
	if(q < x){
		return q2(x-q, 2*i+1, m+1, r);
	}
	else{
		return q2(x, 2*i, l, m);
	}
}

int main(){ _
	build();
	int x, m; cin >> x >> m;
	for(int i=0;i <x; i++){
		int a; cin >> a;
		v[a]++;
	}
	build();
	for(int i=0;i <m; i++){
		int k; cin >> k;
		if(k<0){
			k = q2(-k);
			update(k, -1);
		}
		else{
			update(k, 1);
		}
	}
	if(query(0, n)==0){
		cout << 0 << endl;
	}
	else{
		cout << q2(1) << endl;
	}


	exit(0);
}
