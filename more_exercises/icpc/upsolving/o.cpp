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

typedef long double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-14;

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

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return eq(sarea(p, q, r), 0);
}

pt proj(pt p, line r) { // projecao do ponto p na reta r
	if (r.p == r.q) return r.p;
	r.q = r.q - r.p; p = p - r.p;
	pt proj = r.q * ((p*r.q) / (r.q*r.q));
	return proj + r.p;
}

int main(){ _
		
	int n; cin >> n;
	if(n==2) return cout << "0.00" << endl, 0;
	vector<pt> v;
	for(int i=0;i <n; i++){
		pt p; cin >> p;
		v.pb(p);
	}
	vector<pt> w;
	for(int i=0;i <n; i++) w.pb(v[(i+1)%n] - v[i]);
	v = w;
	sort(v.begin(), v.end(), [](pt a, pt b){return angle(a)+eps < angle(b);});
	w.clear(), w.pb(v[0]);
	for(int i=1;i <n; i++) w.pb(w.back()+v[i]);
	v = w;
	auto val = [&](int it, int i){
		pt p = v[it]; 
		return norm(p-proj(p, line(v[i], v[(i+1)%n])));
	};

	int it = 2;
	while(it<n and col(v[0], v[1], v[it])) it++;
	if(it==n) return cout << "0.00" << endl, 0;
	
	ld ans = DINF;
	for(int i=0;i <n; i++){
		while(val((it+1)%n, i) + eps >= val(it, i)) it = (it+1)%n;
		ans = min(ans, val(it, i));
	}
	cout << setprecision(2) << fixed;
	cout << ans << endl;
	exit(0);
}
