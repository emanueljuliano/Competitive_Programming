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

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

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
	return sarea(p, q, r) > eps;
}

pt rotate(pt p, ld th) { // rotaciona o ponto th radianos
	return pt(p.x * cos(th) - p.y * sin(th),
			p.x * sin(th) + p.y * cos(th));
}

pt rotate90(pt p) { // rotaciona 90 graus
	return pt(-p.y, p.x);
}

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

bool paraline(line r, line s) { // se r e s sao paralelas
	return paral(r.p - r.q, s.p - s.q);
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

bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
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

bool operator < (const line& a, const line& b) { // comparador pro sweepline
	if (a.p == b.p) return ccw(a.p, a.q, b.q);
	if (!eq(a.p.x, a.q.x) and (eq(b.p.x, b.q.x) or a.p.x+eps < b.p.x))
		return ccw(a.p, a.q, b.p);
	return ccw(a.p, b.q, b.p);
}

bool has_intersection(vector<line> v) {
	auto intersects = [&](pair<line, int> a, pair<line, int> b) {
		return interseg(a.f, b.f);
	};
	vector<pair<pt, pair<int, int>>> w;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].q < v[i].p) swap(v[i].p, v[i].q);
		w.push_back({v[i].p, {0, i}});
		w.push_back({v[i].q, {1, i}});
	}
	sort(w.begin(), w.end());
	set<pair<line, int>> se;
	for (auto i : w) {
		line at = v[i.s.s];
		if (i.s.f == 0) {
			auto nxt = se.lower_bound({at, i.s.s});
			if (nxt != se.end() and intersects(*nxt, {at, i.s.s})) return 1;
			if (nxt != se.begin() and intersects(*(--nxt), {at, i.s.s})) return 1;
			se.insert({at, i.s.s});
		} else {
			auto nxt = se.upper_bound({at, i.s.s}), cur = nxt, prev = --cur;
			if (nxt != se.end() and prev != se.begin()
					and intersects(*nxt, *(--prev))) return 1;
			se.erase(cur);
		}
	}
	return 0;
}
int n;
vector<pair<pt, pt>> pts;
vector<int> S;
ld com = 0.218750000;
bool has = false;
bool show(ld m){
	bool ret= false;
	vector<line> v;
	for(int i=0; i<n; i++){
		pt p = pts[i].f;
		pt q = pts[i].s;
		ld mul = m*S[i]/norm(q);
		q = q*mul;
		q = q+p;
		v.pb(line(p, q));
	}
//	if(eq(m, com)){
//		for(auto k : v) cout << k.p.x << " " << k.p.y << " " << k.q.x << " " << k.q.y << endl;
//	}
	ret = has_intersection(v);
	has |= ret;
	return ret;
}

ld bb(ld l, ld r){
	if(eq(l, r)) return l;
	ld m = (l+r)/2.0;
	if(show(m)) r = m;
	else l = m;
	return bb(l, r);
}

int main(){ _
	cin >> n;
	for(int i=0;i <n; i++){
		pt a, b; cin >> a >> b;
		int s; cin >> s; S.pb(s);
		pts.pb({a, b});
	}
	//cout << show(com) << endl;	
	cout << setprecision(9) << fixed;
	ld ans = bb((ld)0, (ld)1e13);
	if(!has) cout << "No show :(" << endl;
	else cout << ans << endl;

	exit(0);
}
