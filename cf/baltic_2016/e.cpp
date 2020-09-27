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

const int MAX = 1e5+10;

int seg[2 * MAX];
int n;

int query(int a, int b) {
	int ret = 0;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret += seg[a];
		if (b % 2 == 0) ret += seg[b];
	}
	return ret;
}

void update(int p, int x) {
	seg[p += n] += x;
	while (p /= 2) seg[p] = seg[2*p] + seg[2*p+1];
}

int main(){ _
	cin >> n;
	vector<vector<int>> g(n);
	for(int i=0;i <n; i++){
		int c; cin >> c; c--;
		g[i].pb(c);
		g[c].pb(i);
	}
	ll ans = 0;
	for(int i=0;i <n; i++){
		int q1=0, q2=0;
		if(g[i][0]>i+1) q1 = query(i+1, g[i][0]-1);
		if(g[i][1]>i+1) q2 = query(i+1, g[i][1]-1);
		ans += q1+q2;
		if(g[i][0]>i+1) update(g[i][0], 1);
		if(g[i][1]>i+1) update(g[i][1], 1);
	}
	cout << ans << endl;


	exit(0);
}
