#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

typedef long double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ld x, y;
	pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}
ld norm(pt v) { // norma do vetor
	return dist(pt(0, 0), v);
}

int main(){ _
	int n; cin >> n;
	vector<pt> v1(n);
	for (int i=0; i<n; i++){
		int a, b; cin >> a >> b;
		v1[i] = pt(a, b);
	}
	int m; cin >> m;
	vector<pt> v2(m);
	for (int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		v2[i] = pt(a, b);
	}


	int i1=0, i2=0;
	ld l1 = 0, l2 = 0, r1, r2;

	auto pos1 = [&](ld t) {
		pt v = v1[i1+1] - v1[i1];
		v =  v/norm(v);
		pt ret = v1[i1] + v*(t-l1);
	//	cout << "v1 (" << ret.x << ", " << ret.y << ")" << endl;
		return ret;
	};
	auto pos2 = [&](ld t) {
		pt v = v2[i2+1] - v2[i2];
		v =  v/norm(v);
		pt ret = v2[i2] + v*(t-l2);
	//	cout << "v2 (" << ret.x << ", " << ret.y << ")" << endl;
		return ret;
	};

	
	auto min_dist = [&]() {
		ld l = max(l1, l2), r = (min(r1, r2));
		ld ret = min(dist(pos1(l), pos2(l)), dist(pos1(r), pos2(r)));

		for (int t = 0; t<60; t++) {
			if (abs(l-r) < 1e-9) break;
			ld m1 = l + (r-l)/3, m2 = r - (r-l)/3;
			ld d1 = dist(pos1(m1), pos2(m1));
			ld d2 = dist(pos1(m2), pos2(m2));
			if (d1 < d2) r = m2;
			else l = m1;

			ret = min(ret, min(d1, d2));
		}
	//	cout << l << " " << ret << endl;
		return ret;
	};

	ld ans = LINF;
	while (i1 < n-1 and i2 < m-1) {
		r1 = l1 + dist(v1[i1+1], v1[i1]);
		r2 = l2 + dist(v2[i2+1], v2[i2]);
		ans = min(min_dist(), ans);
		if (r1 <= r2) l1 = r1, i1++;
		else l2 = r2, i2++;
	}

	cout << setprecision(10) << fixed;
	cout << ans << endl;
	
	
	exit(0);
}
