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

typedef long double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-13;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ld x, y;
	pt() {}
	pt(ld x_, ld y_) : x(x_), y(y_) {}
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


// PONTO & VETOR

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

ld norm(pt v) { // norma do vetor
	return dist(pt(0, 0), v);
}
ld angle(pt v) { // angulo do vetor com o eixo x
	ld ang = atan2(v.y, v.x);
	if (ang < 0) ang += 2*pi;
	return ang;
}

pt rotate(pt p, ld th) { // rotaciona o ponto th radianos
	return pt(p.x * cos(th) - p.y * sin(th),
			p.x * sin(th) + p.y * cos(th));
}

pt p1, p2, c1, c2;
ld r1, r2;

ld dcirc(pt p, pt q){
	ld ang = p*q/norm(p)/norm(q);
	ang = acos(ang);
	return r1*ang;
}

int main(){ _
	cin >> p1;
	cin >> p2;
	cin >> c2 >> r2;
	cin >> c1 >> r1;

	p1 = p1 - c1;
	p2 = p2 - c1;
	c1 = c1 - c1;

	vector<pt> v, w;

	pt p = p1;
	ld d2 = r1*r1/dist(p, c1);
	ld h = sqrt(r1*r1 - d2*d2);
	v.pb(rotate(pt(d2, h), angle(p)));
	v.pb(rotate(pt(d2, -h), angle(p)));
	
	p = p2;
	d2 = r1*r1/dist(p, c1);
	h = sqrt(r1*r1 - d2*d2);
	w.pb(rotate(pt(d2, h), angle(p)));
	w.pb(rotate(pt(d2, -h), angle(p)));
	
	cout << setprecision(7) << fixed;
	ld ans = DINF;
	for(int i=0;i <2; i++) for(int j=0; j<2; j++){
		pt p = v[i], q = w[j];
		ld at = dist(p1, p) + dist(p2, q);
		at += dcirc(p, q);
		ans= min(ans, at);
	}

	cout << ans << endl;


	exit(0);
}
