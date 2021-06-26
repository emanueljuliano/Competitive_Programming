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


#define sq(x) ((x)*(ll)(x))

struct pt { // ponto
	ll x, y;
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

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea2(p, q, r) > 0;
}

int quad(pt p) { // quadrante de um ponto
   return (p.x<0)^3*(p.y<0);
}

ll get_t(pt v, line r) { // retorna t tal que t*v pertence a reta r
	return (r.p^r.q) / ((r.p-r.q)^v);
}

pt inter(line r, line s) { // r inter s
	r.q = r.q - r.p, s.p = s.p - r.p, s.q = s.q - r.p;
	return r.q *  get_t(r.q, s) + r.p;
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



int main(){ _
	int n; cin >> n;
	vector<pt> v;
	for(int i=0;i <n; i++){
		int x, y, z; cin >> x >> y >> z;
		v.pb(pt(x+z, y));
		v.pb(pt(x-z, y));
		v.pb(pt(x, y+z));
		v.pb(pt(x, y-z));
	}

	v = convex_hull(v);

	vector<line> w(4);
	vector<int> vis(4);
	for(int i=0;i <v.size(); i++){
		pt p = v[(i+1)%v.size()] - v[i];
		if(abs(p.x)==abs(p.y) and !vis[quad(p)]){
			vis[quad(p)] = 1;
			w[quad(p)] = line(v[i], v[i]+p);
		}
	}

	vector<pt> pontas;
	for(int i=0;i <4; i++)
		for(int j=i+1; j<4; j++)
			if(!paraline(w[i], w[j]){
				pontas.pb(inter(w[i], w[j]);
			}
	for(int i=0;i <4; i++)
		for(int j=i+1; j<4; j++)
			if(pontas[i].x==pontas[j].x)
	
	exit(0);
}
