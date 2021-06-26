#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const ld DINF = 1e18;
ld pi = acos(-1.0);
const ld eps = 1e-7;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a-b) <= eps;
}

struct pt {
	ld x, y;
	pt () {}
	pt (ld x_, ld y_) : x(x_), y(y_) {}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c, y*c); }
	pt operator / (const ld c) const { return pt(x/c, y/c); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream & operator >> (istream& in, pt & p) {
		return in >> p.x >> p.y;
	}
};

ld dist(pt p, pt q) {
	return hypot(p.y - q.y, p.x - q.x);
}

ld angle(pt v) {
	ld ang = atan2(v.y, v.x);
	if (ang < 0) ang += 2*pi;
	return ang;
}

ld sarea(pt p, pt q, pt r) {
	return ((q-p)^(r-q))/2;
}

pt rotate(pt p, ld th) {
	return pt(p.x * cos(th) - p.y * sin(th), p.x * sin(th) + p.y * cos(th));
}

int main(){ _
	int n; cin >> n;
	vector elip(n, vector<pt>(4));
	vector rec(n, vector<vector<pt>>());
		
	for (int i=0;i <n; i++) {
		for (int j=0; j<4; j++) cin >> elip[i][j];
		int r; cin >> r;
		rec[i].resize(r);
		for (int j=0;j <r; j++) {
			rec[i][j].resize(4);
			for (auto &p : rec[i][j]) cin >> p;
		}
	}	
	
	vector<ld> val;
	
	for (int i=0; i<n; i++) {
		pt pc = (elip[i][0] + elip[i][1])/2;
		for (auto &p : elip[i]) p = p - pc;
		
		pt v = elip[i][1] - elip[i][0];
		ld ang = angle(v);
		for (auto &p : elip[i]) p = rotate(p, -ang);
		
		ld dx = dist(elip[i][1], elip[i][0])/2;
		ld dy = dist(elip[i][3], elip[i][2])/2;
		for (auto &p : elip[i]) {
			p.x = p.x/dx;
			p.y = p.y/dy;
		}

		ld area = 0;
		for (auto &r : rec[i]) {
			for (auto &p : r) {
				p = p - pc;
				p = rotate(p, -ang);
				p.x /= dx, p.y /= dy;
			}

			area += abs(sarea(r[0], r[1], r[2]));
			area += abs(sarea(r[0], r[3], r[2]));
		}
		val.push_back(area);	
	}

	vector<int> f(n);
	int sz = 0;
	for (int i=0; i<n; i++) if(!f[i]) {
		sz++;
		f[i] = sz;
		for (int j=i+1; j<n; j++) if(eq(val[i], val[j])) f[j] = sz;
	}

	for (auto u : f) cout << u << " ";
	cout << endl;
	
	exit(0);
}
