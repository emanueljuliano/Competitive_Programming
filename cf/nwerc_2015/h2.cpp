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

typedef tuple<int, int, int, int> T;
typedef long double ld;

ld pi = acos(-1);
ld eps = 1e-8;
const ld DINF = 1e18;


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
	bool operator < (const line l) const {
		if(!(p==l.p)) return p<l.p;
		if(!(q==l.q)) return q<l.q;
		return 0;
	}

	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
	friend ostream& operator << (ostream& out, line& r) {
		return out << r.p.x << " " << r.p.y << " " <<  r.q.x << " " << r.q.y;
	}

};

ld dist(pt p) { // distancia
	return hypot(p.y, p.x);
}

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
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

pt inter(line r, line s) { // r inter s
	if (paraline(r, s)) return pt(DINF, DINF);
	r.q = r.q - r.p, s.p = s.p - r.p, s.q = s.q - r.p;
	return r.q * get_t(r.q, s) + r.p;
}

bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

int n;

void reflex(vector<line> &v, line l, pt &t, int i){
	auto [p, q] = l;
	int it = 0;
	if(p.x==q.x){
		t.x = p.x+(p.x-t.x);
		for(auto &[p2, q2] : v) if(++it>i) 
			p2.x = p.x + (p.x-p2.x), q2.x = q.x + (q.x-q2.x);
	}
	else if(p.y==q.y){
		t.y = p.y+(p.y-t.y);
		for(auto &[p2, q2] : v) if(++it>i) 
			p2.y = p.y + (p.y-p2.y), q2.y = q.y + (q.y-q2.y);
	}
}

int main(){ _
	cin >> n;
	pt t; cin >> t;
	vector<line> w(n);
	for(auto &l : w) cin >> l;
	if(n==0){
		cout << 0 << endl;
		exit(0);
	}
	sort(w.begin(), w.end());
	int ans = -1;
	
	do{
		//cout << "NEW ITERATION" << endl;
		vector<line> v = w;
		//for(auto l : v) cout << l << endl;
		pt p = t;
		vector<vector<line>> seg(n+1);

		auto can = [&](int i){
			line s(pt(0, 0), p);
		//	cout << "Can i " << i << " " << p.x << " " << p.y << endl;
			if(i==0){
				for(auto l : seg[0]) if(interseg(s, l)) return false;
				return true;
			}
			pt at(0, 0);
			for(int j=0; j<i; j++){
				pt nat = inter(s, seg[j][0]);
		//		cout << j << " " << nat.x << " " << nat.y << endl;	
				if(dist(nat)<dist(at) or !isinseg(nat, s) or !isinseg(nat, seg[j][0])) return false;
				for(int k=1; k<seg[j].size(); k++){
					pt bad = inter(s, seg[j][k]);
					if(dist(bad)<dist(at) or !isinseg(bad, s) or !isinseg(bad, seg[j][k]) or 
						dist(bad)>dist(nat)) 
						continue;
					return false;
				}
				at = nat;
			}
			s = line(at, p);
			for(auto l : seg[i]) if(interseg(s, l)) return false;
			return true;
	
		};	

		for(int j=0; j<n; j++){
			seg[0].pb(v[j]);
		}
		if(can(0)) ans = max(ans, 0);

		for(int i=0; i<n; i++){
			reflex(v, v[i], p, i);
			for(int j=i+1; j<n; j++){
				seg[i+1].pb(v[j]);
			}
			if(can(i+1)) ans = max(ans, i+1);
		}
		//cout << endl;
	}while(next_permutation(w.begin(), w.end()));
	
	if(ans != -1) cout << ans << endl;
	else cout << "impossible" << endl;
	exit(0);
}
