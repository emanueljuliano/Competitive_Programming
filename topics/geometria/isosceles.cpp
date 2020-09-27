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

// Primitivas Geometricas Inteiras

#define sq(x) (ll(x)*(x))

struct pt { // ponto
	int x, y;
	pt() {}
	pt(int x_, int y_) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x == p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
};

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
};

// PONTO & VETOR

ll dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

ll dot(pt u, pt v) { // produto escalar
	return u.x * (ll)v.x + u.y * (ll)v.y;
}

ll cross(pt u, pt v) { // norma do produto vetorial
	return u.x * (ll)v.y - u.y * (ll)v.x;
}

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return cross(q - p, r - q);
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return sarea2(p, q, r) == 0;
}

int paral(pt u, pt v) { // se u e v sao paralelos
	if (cross(u, v) != 0) return 0;
	if ((u.x > 0) == (v.x > 0) and (u.y > 0) == (v.y > 0)) return 1;
	return -1;
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea2(p, q, r) > 0;
}

pt rotate90(pt p) { // rotaciona 90 graus
	return pt(-p.y, p.x);
}

// RETA

bool isvert(line r) { // se r eh vertical
	return r.p.x == r.q.x;
}

bool lineeq(line r, line s) { // r == s
	return col(r.p, r.q, s.p) and col(r.p, r.q, s.q);
}

bool paraline(line r, line s) { // se r e s sao paralelas
	return paral(r.p - r.q, s.p - s.p);
}

bool isinline(pt p, line r) { // se p pertence a r
	return col(p, r.p, r.q);
}

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	if (p == r.p or p == r.q) return 1;
	return paral(p - r.p, p - r.q) == -1;
}

bool interseg(line r, line s) { // se o seg de r intercepta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

int segpoints(line r) { // numero de pontos inteiros no segmento
	return 1 + __gcd(abs(r.p.x - r.q.x), abs(r.p.y - r.q.y));
}

// POLIGONO

ll polarea2(vector<pt> v) { // 2 * area do poligono
	ll ret = 0;
	for (int i = 0; i < v.size(); i++)
		ret += sarea2(pt(0, 0), v[i], v[(i + 1) % v.size()]);
	return abs(ret);
}

bool onpol(pt p, vector<pt> v) { // se um ponto esta na fronteira do poligono
	for (int i = 0; i < v.size(); i++)
		if (isinseg(p, line(v[i], v[(i + 1) % v.size()]))) return 1;
	return 0;
}

vector<pt> convexhull(vector<pt> v) { // convex hull
	vector<pt> l, u;

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		while (l.size() > 1 and !ccw(v[i], l.back(), l[l.size() - 2]))
			l.pop_back();
		l.pb(v[i]);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		while (u.size() > 1 and !ccw(v[i], u.back(), u[u.size() - 2]))
			u.pop_back();
		u.pb(v[i]);
	}

	l.pop_back(); u.pop_back();

	for (pt i : u) l.pb(i);

	return l;
}

ll interior_points(vector<pt> v) { // numero de pontos interiores em um poligono simples
	ll b = 0;
	for (int i = 0; i < v.size(); i++)
		b += segpoints(line(v[i], v[(i+1)%v.size()])) - 1;
	return (polarea2(v) - b) / 2 + 1;
}

int main(){ _
	int n;
	while(true){
		cin >> n;
		if(!n) break;
		map<ll, int> m;
		vector<pt> v;
		for(int i=0;i <n; i++){
			int x, y; cin >> x >> y;
			v.pb(pt(x, y));
		}
		ll ans = 0;
		for(int i=0;i <n; i++){
			m.clear();
			for(int j=0;j <n; j++){
				m[dist2(v[i], v[j])]++;
			}
			for( auto x : m){
				ll d = x.s;
				ans += d*(d-1)/2;
			}
	//		cout << i << " "<< ans << endl;
		}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
