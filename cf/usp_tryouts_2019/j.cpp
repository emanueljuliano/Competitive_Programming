#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
#define sq(x) ((x)*(x))

const double EPS = 1e-12;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

struct pt {
	double x, y;
	pt(double x_ = 0, double y_ = 0) : x(x_), y(y_) {}
	pt operator + (const pt& p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt& p) const { return pt(x-p.x, y-p.y); }
	pt operator * (double c) const { return pt(x*c, y*c); }
	pt operator / (double c) const { return pt(x/c, y/c); }
};

double dot(pt p, pt q) { return p.x*q.x+p.y*q.y; }
double cross(pt p, pt q) { return p.x*q.y-p.y*q.x; }
double dist(pt p, pt q) { return sqrt(dot(p-q, p-q)); }

pt center(pt p, pt q, pt r) {
	pt a = p-r, b = q-r;
	pt c = pt(dot(a, p+r)/2, dot(b, q+r)/2);
	return pt(cross(c, pt(a.y, b.y)), cross(pt(a.x, b.x), c)) / cross(a, b);
}

struct circle {
	pt cen;
	double r;
	circle(pt cen_, double r_) : cen(cen_), r(r_) {}
	circle(pt a, pt b, pt c) {
		cen = center(a, b, c);
		r = dist(cen, a);
	}
	bool inside(pt p) { return dist(p, cen) < r+EPS; }
};

circle minCirc(vector<pt> v) {
	shuffle(v.begin(), v.end(), rng);
	circle ret = circle(pt(0, 0), 0);
	for (int i = 0; i < v.size(); i++) if (!ret.inside(v[i])) {
		ret = circle(v[i], 0);
		for (int j = 0; j < i; j++) if (!ret.inside(v[j])) {
			ret = circle((v[i]+v[j])/2, dist(v[i], v[j])/2);
			for (int k = 0; k < j; k++) if (!ret.inside(v[k]))
				ret = circle(v[i], v[j], v[k]);
		}
	}
	return ret;
}


int main(){ _
	int n; cin >> n;
	vector<pt> v(n);
	for (int i=0; i<n; i++){
		double a, b; cin >> a >> b;
		v[i] = pt(a, b);
	}
	auto C = minCirc(v);
	cout << setprecision(5) << fixed;
	cout << C.cen.x << " " << C.cen.y << " " << sq(C.r)/2 << endl;
	
	
	exit(0);
}
