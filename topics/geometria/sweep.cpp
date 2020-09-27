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

// Primitivas Geometricas Inteiras

#define sq(x) ((x)*(ll)(x))

struct pt { // ponto
	int x, y;
	pt() {}
	pt(int x_, int y_) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
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
	bool operator < (const line l) const {
		if (!(p == l.p)) return p < l.p;
		return q < l.q;
	}

};

// PONTO & VETOR

ll dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return sarea2(p, q, r) == 0;
}

int paral(pt u, pt v) { // se u e v sao paralelos
	if (u^v) return 0;
	if ((u.x > 0) == (v.x > 0) and (u.y > 0) == (v.y > 0)) return 1;
	return -1;
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea2(p, q, r) > 0;
}

int quad(pt p) { // quadrante de um ponto
   return (p.x<0)^3*(p.y<0);
}

bool compare_angle(pt p, pt q) { // retorna se ang(p) < ang(q)
    if (quad(p) != quad(q)) return quad(p) < quad(q);
    return ccw(q, pt(0, 0), p);
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
	return paral(r.p - r.q, s.p - s.q);
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

double get_t(pt v, line r) { // retorna t tal que t*v pertence a reta r
	return (r.p^r.q) / (double) ((r.p-r.q)^v);
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

ll interior_points(vector<pt> v) { // numero de pontos interiores em um poligono simples
	ll b = 0;
	for (int i = 0; i < v.size(); i++)
		b += segpoints(line(v[i], v[(i+1)%v.size()])) - 1;
	return (polarea2(v) - b) / 2 + 1;
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
		return (pol[l-1]^pol[l]) >= ((pol[l-1]-pol[l])^p);
	}
};

// comparador pro set pra fazer sweep angle com segmentos

pt dir;
struct cmp {
    bool operator () (const line& a, const line& b) const {
        return get_t(dir, a) < get_t(dir, b);
    }
};

struct cmp2 {
	bool operator () (const line& a, const line& b) const {
		/*if(a.p==b.p) return a.q.y<b.q.y;
		if(a.p==b.q) return a.q.y<b.p.y;
		if(a.q==b.p) return a.p.y<b.q.y;
		if(a.q==b.q) return a.p.y<b.p.y;
		*/return ccw(a.p, a.q, b.p);
	}
};
bool show(line a, line b){
	if(interseg(a, b)){
		if(!(a.p==b.p) and !(a.p==b.q) and !(a.q==b.p) and !(a.q==b.q)) return true;
	}
	return false;
}
bool lineeq2(line a, line b){
	return (a.q==b.q and a.p==b.p) or (a.p == b.q and a.q==b.p);
}

int main(){_
	while(true){
		int n; cin >> n;
		if(n==0) break;
		vector<line> vl;
		map<line, int> ma;
		vector<pair<pt, pair<bool, int>>> ev;
		for(int i=0;i <n; i++){
			line l; cin >> l;
			if(l.q < l.p) swap(l.p, l.q);
			vl.pb(l);
			ma[l] = i+1;
			ev.pb({l.p, {0, i+1}}), ev.pb({l.q, {1, i+1}});
		}	
		set<line, cmp2> st;
		sort(ev.begin(), ev.end());
		bool inter = false;
	for (auto IT : ev){
			pt p = IT.f;
			bool close = IT.s.f;
			line l = vl[IT.s.s-1];
			line lo, lf;
			cout << "n= " << IT.s.s << " pt= (" << p.x << ", " << p.y << ") ";
			cout << "cl= " << close << " s= " << st.size() << endl;
			if(!close){
				st.insert(l);
				lo = *st.begin();
				lf = *st.rbegin();

				auto it = st.find(l);

				if(!lineeq2(lf, l)){
					auto it1 = it; it1++;
					inter |= show(l, *it1);
				}
				if(!lineeq2(lo, l)){
					auto it2 = it; it2--;
					inter |= show(l, *it2);
				}
				if(!lineeq2(lo, l) and !lineeq2(lf, l)){
					auto it1 = it, it2 = it;
					it1--; it2++;
					inter |= show(*it1, *it2);
				}
			}
			else{
				lo = *st.begin();
				lf = *st.rbegin();

				auto it = st.find(l);

				/*if(!lineeq2(lf, l)){
					auto it1 = it; it1++;
					inter |= inerseg(l, *it1);
				}
				if(!lineeq2(lo, l)){
					auto it2 = it; it2--;
					inter |= interseg(l, *it2);
				}*/
				if(!lineeq2(lo, l) and !lineeq2(lf, l)){
					auto it1 = it, it2 = it;
					it1--; it2++;
					inter |= interseg(*it1, *it2);
				}
				st.erase(l);
			}
			if(inter) cout << "INTER" << endl;
			for(auto r : st) cout << ma[r] << " ";
			cout << endl;
		}
		if(inter) cout << "NO" << endl;
		else cout << "YES" << endl;
	}	


	exit(0);
}
