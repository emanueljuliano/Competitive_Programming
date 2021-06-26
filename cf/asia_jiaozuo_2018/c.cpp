#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 3e5+10;

int X[MAX], Y[MAX];
int ID[MAX], sz[16], add[16];
vector<int> vx, vy;

ll dx[4]; // L, R
ll dy[4]; // D, U
int lx, rx, ly, ry;
ll n;

int px(int id) {
	int i = ID[id];
	bool l = false, r = false;
	if (i & 1) l = true;
	if (i & 2) r = true;
	if (!l and !r) return X[id] + dx[0];
	else return dx[l + 2*r];
}

int py(int id) {
	int i = ID[id];
	bool u = false, d = false;
	if (i & 4) d = true;
	if (i & 8) u = true;
	if (!d and !u) return Y[id] + dy[0];
	else return dy[d + 2*u];
}

void right(int x);
void left(int x) {
	for (int i=0; i<4; i++) {
		if (i) dx[i] = max(dx[i]-x, 1ll);
		else dx[i] -= x;
	}
	while (lx < n) {
		int u = vx[lx];
		if (lx <= rx+1 and px(u) > 1) break;
		sz[ID[u]] -= 1;
		ID[u] |= 1;
		sz[ID[u]]++;
		lx++;
	}
	if (lx > rx+1 and rx != 0) right(0);
}

void right(int x) {
	for (int i=0; i<4; i++) {
		if (i) dx[i] = min(dx[i]+x, n);
		else dx[i] += x;
	}
	while (rx >= 0) {
		int u = vx[rx];
		if (lx <= rx+1 and px(u) < n) break;
		sz[ID[u]] -= 1;
		ID[u] |= 2;
		sz[ID[u]]++;
		rx--;
	}
	if (lx > rx+1 and lx != n) left(0);
}

void down(int x);
void up(int y) {
	for (int i=0; i<4; i++) {
		if (i) dy[i] = max(dy[i]-y, 1ll);
		else dy[i] -= y;
	}
	while (ly < n) {
		int u = vy[ly];
		if (ly <= ry+1 and py(u) > 1) break;
		sz[ID[u]] -= 1;
		ID[u] |= 4;
		sz[ID[u]]++;
		ly++;
	}
	if (ly > ry+1 and ry != 0) down(0);
}

void down(int y) {
	for (int i=0; i<4; i++) {
		if (i) dy[i] = min(dy[i]+y, n);
		else dy[i] += y;
	}
	while (ry >= 0) {
		int u = vy[ry];
		if (ly <= ry+1 and py(u) < n) break;
		sz[ID[u]] -= 1;
		ID[u] |= 8;
		sz[ID[u]]++;
		ry--;
	}
	if (ly > ry+1 and ly != n) up(0);
}

ll query() {
	ll ret = 0;
	for (int i=0; i<16; i++) if(add[i]) ret += (sz[i]*ll(sz[i]-1))/2;
	return ret;
}

int main(){ _
	int t; cin >> t;
	
	for (int i=0; i<16; i++) if((i&1 or i&2) and (i&4 or i&8)) add[i] = 1;
	while (t--) {
		vx.clear(), vy.clear();
		for(int i=0; i<16; i++) sz[i] = 0;

		int m; cin >> n >> m;
		
		dx[0] = 0, dx[1] = 1, dx[2] = n, dx[3] = 1;
		dy[0] = 0, dy[1] = 1, dy[2] = n, dy[3] = 1;
		lx = 0, rx = n-1, ly = 0, ry = n-1;
		
		for (int i=0; i<n; i++) {
			int x, y; cin >> y >> x;
			X[i] = x, Y[i] = y;
			vx.push_back(i), vy.push_back(i);
			ID[i] = 0, sz[0]++;
		}
		sort (vx.begin(), vx.end(), [&](int a, int b){return X[a]<X[b];});
		sort (vy.begin(), vy.end(), [&](int a, int b){return Y[a]<Y[b];});

		while (m--) {
			char c; cin >> c;
			int a;
			if (c == '!') {
				cout << query() << endl;
			}
			if (c == '?') {
				cin >> a; a--;
				cout << py(a) << " " << px(a) << endl;
			}
			if (c == 'L') cin >> a, left(a);
			if (c == 'R') cin >> a, right(a);
			if (c == 'D') cin >> a, down(a);
			if (c == 'U') cin >> a, up(a);
	
/*			cout << endl << "TODOS" << endl;
			for (int i=0; i<n; i++) {
				cout << i+1 << " " << px(i) << " " << py(i) << " " << bitset<4>(ID[i]) << endl;
			}
*/		}
	}
	
	exit(0);
}
