#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// Primitivas Geometricas

const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

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
		in >> p.x >> p.y;
		return in;
	}
};

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		in >> r.p >> r.q;
		return in;
	}
};

// PONTO & VETOR

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

ld dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

ld norm(pt v) { // norma do vetor
	return dist(pt(0, 0), v);
}

ld angle(pt v) { // angulo do vetor com o eixo x
	ld ang = atan2(v.y, v.x);
	if (ang < 0) ang += 2*pi;
	return ang;
}

pt normalize(pt v) { // vetor normalizado
	if (!norm(v)) return v;
	v = v / norm(v);
	return v;
}

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return eq(sarea(p, q, r), 0);
}

int paral(pt u, pt v) { // se u e v sao paralelos
	if (!eq(u^v, 0)) return 0;
	if ((u.x > eps) == (v.x > eps) and (u.y > eps) == (v.y > eps))
		return 1;
	return -1;
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea(p, q, r)-eps > 0;
}

pt rotate(pt p, ld th) { // rotaciona o ponto th radianos
	return pt(p.x * cos(th) - p.y * sin(th),
			p.x * sin(th) + p.y * cos(th));
}

pt rotate90(pt p) { // rotaciona 90 graus
	return pt(-p.y, p.x);
}

// RETA

bool isvert(line r) { // se r eh vertical
	return eq(r.p.x, r.q.x);
}

ld getm(line r) { // coef. ang. de r
	if (isvert(r)) return DINF;
	return (r.p.y - r.q.y) / (r.p.x - r.q.x);
}

ld getn(line r) { // coef. lin. de r
	if (isvert(r)) return DINF;
	return r.p.y - getm(r) * r.p.x;
}

bool lineeq(line r, line s) { // r == s
	return col(r.p, r.q, s.p) and col(r.p, r.q, s.q);
}

bool paraline(line r, line s) { // se r e s sao paralelas
	if (isvert(r) and isvert(s)) return 1;
	if (isvert(r) or isvert(s)) return 0;
	return eq(getm(r), getm(s));
}

bool isinline(pt p, line r) { // se p pertence a r
	return col(p, r.p, r.q);
}

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	if (p == r.p or p == r.q) return 1;
	return paral(p - r.p, p - r.q) == -1;
}

ld get_t(pt v, line r) { // retorna t tal que t*v pertence a reta r
	return (r.p^r.q) / ((r.p-r.q)^v);
}

pt proj(pt p, line r) { // projecao do ponto p na reta r
	if (r.p == r.q) return r.p;
	r.q = r.q - r.p; p = p - r.p;
	pt proj = r.q * ((p*r.q) / (r.q*r.q));
	return proj + r.p;
}

pt inter(line r, line s) { // r inter s
	if (paraline(r, s)) return pt(DINF, DINF);

	if (isvert(r)) return pt(r.p.x, getm(s) * r.p.x + getn(s));
	if (isvert(s)) return pt(s.p.x, getm(r) * s.p.x + getn(r));

	ld x = (getn(s) - getn(r)) / (getm(r) - getm(s));
	return pt(x, getm(r) * x + getn(r));
}

bool interseg(line r, line s) { // se o seg de r intercepta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s)
			or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
		ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

ld disttoline(pt p, line r) { // distancia do ponto a reta
	return dist(p, proj(p, r));
}

ld disttoseg(pt p, line r) { // distancia do ponto ao seg
	if (isinseg(proj(p, r), r))
		return disttoline(p, r);
	return min(dist(p, r.p), dist(p, r.q));
}

ld distseg(line a, line b) { // distancia entre seg
	if (interseg(a, b)) return 0;

	ld ret = DINF;
	ret = min(ret, disttoseg(a.p, b));
	ret = min(ret, disttoseg(a.q, b));
	ret = min(ret, disttoseg(b.p, a));
	ret = min(ret, disttoseg(b.q, a));

	return ret;
}

// POLIGONO

ld polper(vector<pt> v) { // perimetro do poligono
	ld ret = 0;
	for (int i = 0; i < v.size(); i++)
		ret += dist(v[i], v[(i + 1) % v.size()]);
	return ret;
}

ld polarea(vector<pt> v) { // area do poligono
	ld ret = 0;
	for (int i = 0; i < v.size(); i++)
		ret += sarea(pt(0, 0), v[i], v[(i + 1) % v.size()]);
	return abs(ret);
}

bool onpol(pt p, vector<pt> v) { // se um ponto esta na fronteira do poligono
	for (int i = 0; i < v.size(); i++)
		if (isinseg(p, line(v[i], v[(i + 1) % v.size()]))) return 1;
	return 0;
}

bool inpol(pt p, vector<pt> v) { // se um ponto pertence ao poligono
	if (onpol(p, v)) return 1;
	int c = 0;
	line r = line(p, pt(DINF, pi * DINF));
	for (int i = 0; i < v.size(); i++) {
		line s = line(v[i], v[(i + 1) % v.size()]);
		if (interseg(r, s)) c++;
	}
	return c & 1;
}

bool interpol(vector<pt> v1, vector<pt> v2) { // se dois poligonos se interceptam
	for (int i = 0; i < v1.size(); i++) if (inpol(v1[i], v2)) return 1;
	for (int i = 0; i < v2.size(); i++) if (inpol(v2[i], v1)) return 1;
	return 0;
}

ld distpol(vector<pt> v1, vector<pt> v2) { // distancia entre poligonos
	if (interpol(v1, v2)) return 0;

	ld ret = DINF;

	for (int i = 0; i < v1.size(); i++) for (int j = 0; j < v2.size(); j++)
		ret = min(ret, distseg(line(v1[i], v1[(i + 1) % v1.size()]),
					line(v2[j], v2[(j + 1) % v2.size()])));
	return ret;
}

vector<pt> convex_hull(vector<pt> v) { // convex hull
	vector<pt> l, u;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		while (l.size() > 1 and !ccw(l[l.size()-2], l.back(), v[i]))
			l.pop_back();
		l.pb(v[i]);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		while (u.size() > 1 and !ccw(u[u.size()-2], u.back(), v[i]))
			u.pop_back();
		u.pb(v[i]);
	}
	l.pop_back(); u.pop_back();
	for (pt i : u) l.pb(i);
	return l;
}

struct convex_pol {
	vector<pt> pol;

	convex_pol(vector<pt> v) : pol(convex_hull(v)) {}
	bool is_inside(pt p) { // se o ponto ta dentro do hull - O(log(n))
		if (pol.size() == 1) return p == pol[0];
		int l = 1, r = pol.size();
		while (l < r) {
			int m = (l+r)/2;
			if (ccw(p, pol[0], pol[m])) l = m+1;
			else r = m;
		}
		if (l == 1) return isinseg(p, line(pol[0], pol[1]));
		if (l == pol.size()) return false;
		return (pol[l-1]^pol[l])+eps > ((pol[l-1]-pol[l])^p);
	}
};

// CIRCUNFERENCIA

pt getcenter(pt a, pt b, pt c) { // centro da circunf dado 3 pontos
	b = (a + b) / 2;
	c = (a + c) / 2;
	return inter(line(b, b + rotate90(a - b)),
			line(c, c + rotate90(a - c)));
}

vector<pt> circ_line_inter(pt a, pt b, pt c, ld r) { // intersecao da circunf (c, r) e reta ab
	vector<pt> ret;
	b = b-a, a = a-c;
	ld A = b*b;
	ld B = a*b;
	ld C = a*a - r*r;
	ld D = B*B - A*C;
	if (D < -eps) return ret;
	ret.push_back(c+a+b*(-B+sqrt(D+eps))/A);
	if (D > eps) ret.push_back(c+a+b*(-B-sqrt(D))/A);
	return ret;
}

vector<pt> circ_inter(pt a, pt b, ld r, ld R) { // intersecao da circunf (a, r) e (b, R)
	vector<pt> ret;
	ld d = dist(a, b);
	if (d > r+R or d+min(r, R) < max(r, R)) return ret;
	ld x = (d*d-R*R+r*r)/(2*d);
	ld y = sqrt(r*r-x*x);
	pt v = (b-a)/d;
	ret.push_back(a+v*x + rotate90(v)*y);
	if (y > 0) ret.push_back(a+v*x - rotate90(v)*y);
	return ret;
}

// comparador pro set para fazer sweep angle com segmentos

double ang;
struct cmp {
	bool operator () (const line& a, const line& b) const {
		line r = line(pt(0, 0), rotate(pt(1, 0), ang));
		return norm(inter(r, a)) < norm(inter(r, b));
	}
};


int main(){ _
	ld x1, y1, r1;
	ld x2, y2, r2;
	cin >> x1 >> y1 >> r1;
	cin >> x2 >> y2 >> r2;
	pt c1(x1, y1), c2(x2, y2);	

	line l(pt(x1, y1), pt(x2, y2));
	vector<pt> v = circ_line_inter(l.p, l.q, pt(x1, y1), r1);
	vector<pt> w = circ_line_inter(l.p, l.q, pt(x2, y2), r2);	
	pt a, b;
	if(dist(v[0], c2) < dist(v[1], c2)) a = v[0];
	else a = v[1];
	
	if(dist(w[0], c1) < dist(w[1], c1)) b = w[0];
	else b = w[1];

	ld x = (a.x + b.x)/2.0;
	ld y = (a.y + b.y)/2.0;
	ld r = hypot((a-b).x, (a-b).y);
	r/=2.0;
	cout << setprecision(10) << fixed;
	cout << x << " " << y << " " << r << endl;

	exit(0);
}
