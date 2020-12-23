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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

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
		return in >> p.x >> p.y;
	}
};

struct pt2 { // ponto
	ld x, y;
	pt2() {}
	pt2(ld x_, ld y_) : x(x_), y(y_) {}
	bool operator < (const pt2 p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt2 p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
	pt2 operator + (const pt2 p) const { return pt2(x+p.x, y+p.y); }
	pt2 operator - (const pt2 p) const { return pt2(x-p.x, y-p.y); }
	pt2 operator * (const ld c) const { return pt2(x*c  , y*c  ); }
	pt2 operator / (const ld c) const { return pt2(x/c  , y/c  ); }
	ld operator * (const pt2 p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt2 p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt2& p) {
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

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}

int paral(pt u, pt v) { // se u e v sao paralelos
	if (u^v) return 0;
	if ((u.x > 0) == (v.x > 0) and (u.y > 0) == (v.y > 0)) return 1;
	return -1;
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea2(p, q, r) > 0;
}

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	if (p == r.p or p == r.q) return 1;
	return paral(p - r.p, p - r.q) == -1;
}

double get_t(pt v, line r) { // retorna t tal que t*v pertence a reta r
	return (r.p^r.q) / (double) ((r.p-r.q)^v);
}

int inpol(vector<pt>& v, pt p) { // O(n)
	int qt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == p) return 2;
		int j = (i+1)%v.size();
		bool igual = v[i].y == p.y and v[j].y == p.y, baixo = v[i].y < p.y;
		if (!igual and baixo == (v[j].y < p.y)) continue;
		auto t = (p-v[i])^(v[j]-v[i]);
		if (!t) return 2;
		if (!igual and baixo == (t > 0)) qt += baixo ? 1 : -1;
	}
	return qt != 0;
}

vector<pt> convex_hull(vector<pt> v) { // convex hull - O(n log(n))
	if (v.size() <= 1) return v;
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

pt2 inter(line r, line s) { // r inter s
	r.q = r.q-r.p, s.p = s.p-r.p, s.q = s.q-r.p;
	ld t = get_t(r.q, s);
	pt2 ret(r.p.x + r.q.x*t, r.p.y + r.q.y*t);
	return ret;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		pt p;
		int n; cin >> n >> p;
		cout << setprecision(12) << fixed;	
		map<pt, int> mp;
		vector<pt> v(n);
		for(int i=0;i <n; i++){
			cin >> v[i];
			mp[v[i]] = i;
		}	
		mp[pt(0, 0)] = n;
		v.pb(pt(0, 0));
		vector<ld> ans(n+1, 0.0);

		auto f = [&] (pt2 v1, pt2 v2, pt2 v3){
			// c1*v1 + (1-c1)*v2 = v3
			// c1(v1-v2) = (v3-v2)
			pt2 a1 = (v1-v2), a2 = (v3-v2);
			pair<ld, ld> ret; ret = {0, 0};
			if(abs(a1.x)>eps) ret.f = a2.x/a1.x, ret.s = 1.0-ret.f;
			else if(abs(a1.y)>eps) ret.f = a2.y/a1.y, ret.s = 1.0-ret.f;
			else ret.f=1.0;
			return ret;
		};

		// PONTO
		bool is_pt = false;
		int a1;
		for(int i=0; i<v.size(); i++) if(v[i] == p){
				a1 = i, is_pt = true;
				break;
		}
		if(is_pt){
			ans[a1] = 1.0;
			cout << "Y" << endl;
			for(int i=0;i <n; i++) cout << ans[i] << endl;
			continue;
		}
		
		// SEGMENTO
		v = convex_hull(v);
		n = v.size();
		bool is_in_seg = false;
		int a2;
		for(int i=0;i <v.size(); i++){
			if(isinseg(p, line(v[i], v[(i+1)%n]))){
				a1 = i, a2 = (i+1)%n;
				is_in_seg = true;
				break;
			}
		}
		if(is_in_seg){
			auto [c1, c2] = f(pt2(v[a1].x, v[a1].y), pt2(v[a2].x, v[a2].y), pt2(p.x, p.y));
			ans[mp[v[a1]]] = c1;
			ans[mp[v[a2]]] = c2;
			cout << "Y" << endl;
			for(int i=0;i <ans.size()-1; i++) cout << ans[i] << endl;
			continue;
		}

		// TRIANGULO
		if(v.size() <= 2) {cout << "N" << endl; continue;}

		//while(p.x>0.001 and !C.is_inside(p)) p=p/2;
		if(v.size() <=2 or !inpol(v, p)) {cout << "N" << endl; continue;}
		int a3;
		for(int i=1; i<n-1; i++){
			vector<pt> at = {v[0], v[i], v[i+1]};
			if(inpol(at, p)){
				a1 = 0, a2 = i, a3 = i+1;
				break;
			}
		}
		
		pt2 e = inter(line(v[a3], p), line(v[a1], v[a2]));
		auto [c1, c2] = f(pt2(v[a1].x, v[a1].y), pt2(v[a2].x, v[a2].y), e);
		auto [c3, c4] = f(pt2(v[a3].x, v[a3].y), e, pt2(p.x, p.y));
		ans[mp[v[a1]]] += c1*c4;
		ans[mp[v[a2]]] += c2*c4;
		ans[mp[v[a3]]] += c3;
		cout << "Y" << endl;
		for(int i=0;i <ans.size()-1; i++) cout << ans[i] << endl;
	}
	
	
	
	exit(0);
}
