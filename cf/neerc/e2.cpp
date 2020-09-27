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

int t[4*MAX];

void update(int i, int l, int r, int ql, int qr, int x) {
	if (ql <= l && r <= qr) {
		t[i] = x;
		return;
	}
	if (qr < l || r < ql) return;
	int m = (l+r)/2;
	update(2*i, l, m, ql, qr, x);
	update(2*i+1, m+1, r, ql, qr, x);
}

int query(int i, int l, int r, int p) {
	if (l == r) return t[i];
	int m = (l+r)/2;
	if(t[i]!=0) return t[i];
	if (p <= m) {
		return query(2*i, l, m, p);
	} else {
		return query(2*i+1, m+1, r, p);
	}
}

int main(){ _
	memset(t, 0, sizeof(t));
	int n; cin >> n;
	vector<int> v;
	vector<vector<int>> g(MAX);
	for(int i=0;i <n; i++){
		int a; cin >> a;
		v.pb(a);
		g[a].pb(i+1);
	}
	
	int m; cin >> m;
	vector<int> q;
	for(int i=0;i <m; i++){
		int a; cin >> a; q.pb(a);
	}
	
	for(int i=0;i <m; i++){
		int mini = -1, maxi = -1;
		for(int j=0;j <g[q[i]].size(); j++){
			int pos = g[q[i]][j];
			if(query(1, 1, n, pos)==0){
				if(mini==-1) mini = pos;
				maxi = pos;
			}
		}
		if(mini!=-1 and maxi!=-1) update(1, 1, n, mini, maxi, q[i]);
	}
	for(int i=0;i <n; i++){
		ll x = query(1, 1, n, i+1);
		if(x==0) cout << v[i] << " ";
		else cout << x << " ";
	}
	cout << endl;
	
	exit(0);
}

