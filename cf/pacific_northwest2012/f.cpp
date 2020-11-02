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

typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-8;

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

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

pt rotate90(pt p) { // rotaciona 90 graus
	return pt(-p.y, p.x);
}

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

ld dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

ld disttoline(pt p, line r) { // distancia do ponto a reta
	return 2 * abs(sarea(p, r.p, r.q)) / dist(r.p, r.q);
}

pt proj(pt p, line r) { // projecao do ponto p na reta r
	if (r.p == r.q) return r.p;
	r.q = r.q - r.p; p = p - r.p;
	pt proj = r.q * ((p*r.q) / (r.q*r.q));
	return proj + r.p;
}

vector<string> split(string s, char c){
	stringstream ss(s);
	vector<string> vt;
	string t;
	while (getline(ss, t, c))
		vt.push_back(t);
	return vt;
}

pair<int, int> to_cord(string s){
	stringstream ss(s);
	char c;
	int l, r;
	ss >> c >> l >> c >> r >> c;
	return pair(l, r);
}

#define ALL(x) x.begin(),x.end()

int main() { _
	string s1, s2;
	while (getline(cin, s1)){
		getline(cin, s2);

		vector<pt> a, b; // bom, ruim

		for (auto s : split(s1, ' ')) {
			if (s == "none") break;
			if (s.empty()) continue;
			if (s[0] != '(') continue;

			auto [l, r] = to_cord(s);
			a.pb(pt(l, r));
		}

		for (auto s : split(s2, ' ')) {
			if (s == "none") break;
			if (s.empty()) continue;
			if (s[0] != '(') continue;

			auto [l, r] = to_cord(s);
			b.pb(pt(l, r));
		}

#if 0
		for (pt p : a) cout << p.x << " " << p.y << endl;
		cout << "===" << endl;
		for (pt p : b) cout << p.x << " " << p.y << endl;
		cout << endl;
#endif

		if (a.size() == 1) {
			cout << 0 << endl;
			continue;
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		auto testa_bb = [&](line R, double raio) -> bool {
			vector<pair<pt, int>> w;
			vector<pair<pt, int>> w1_a, w2_a;
			vector<pair<pt, int>> w1_b, w2_b;

			pt unit = R.p - R.q;
			unit = unit / dist(pt(0, 0), unit);

			for (pt p : a) { // bom
				if (disttoline(p, R) > raio) return 0;

				pt pp = proj(p, R);
				double d = sqrt(sq(raio) - dist2(pp, p));
				pt p1 = pp + unit*d;
				pt p2 = pp - unit*d;

				if (p2 < p1) swap(p1, p2);

				w1_a.pb({p1, 0}); // poe
				w2_a.pb({p2, 1}); // tira
			}

			for (pt p : b) { // ruim
				if (disttoline(p, R) > raio) continue;

				pt pp = proj(p, R);
				double d = sqrt(sq(raio) - dist2(pp, p));
				pt p1 = pp + unit*d;
				pt p2 = pp - unit*d;

				if (p2 < p1) swap(p1, p2);

				w1_b.pb({p1, 2}); // poe
				w2_b.pb({p2, 3}); // tira
			}

			vector<pair<pt, int>> wa, wb;
			merge(ALL(w1_a), ALL(w2_a), back_inserter(wa));
			merge(ALL(w1_b), ALL(w2_b), back_inserter(wb));

			merge(ALL(wa), ALL(wb), back_inserter(w));

			//sort(w.begin(), w.end());

			int ab = 0, ab_ruim = 0;

			for (auto [p, op] : w) {
				if (op == 0) ab++;
				else if (op == 1) ab--;
				else if (op == 2) ab_ruim++;
				else ab_ruim--;
				
				if (ab == a.size() and !ab_ruim) return 1;
			}
			return 0;
		};

		auto testa = [&](line R) -> double {

			double l = 0, r = 150;
			for (int it = 0; it < 33; it++) {
				if (abs(l-r) < eps) break;
				double m = (l+r)/2;

				if (testa_bb(R, m)) r = m;
				else l = m;
			}
			if (l > 149) return DINF;
			return (l+r)/2;
		};

		ld ans = DINF;

		for (int i = 0; i < a.size(); i++) for (int j = i+1; j < a.size(); j++) {
			pt mid = (a[i]+a[j])/2;
			line r(mid, mid + rotate90(a[i] - mid));
			ans = min(ans, testa(r));
		}
		if (ans > 1e16) cout << "The Orcs are close" << endl;
		else cout << fixed << setprecision(12) << ans << endl;

	}
	exit(0);
}
