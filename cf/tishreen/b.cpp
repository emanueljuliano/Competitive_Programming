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

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

pt rotate90(pt p) { // rotaciona 90 graus
	return pt(-p.y, p.x);
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

int main(){ _
	int t; cin >> t;
	while(t--){
		vector<pair<pt, ii>> v;
		int n, m; cin >>  n >> m;
		int ans = 0;
		vector<pt> ev;
		for(int i=0;i <n; i++){
			pt p; int r, s; cin >> p >> r >> s;
			v.pb({p, {r, s}});
			ev.pb(p);
		}
		for(int i=0;i <n; i++) for(int j=i+1; j<n; j++){
			vector<pt> aux = circ_inter(v[i].f, v[j].f, v[i].s.f, v[j].s.f);
			for(auto p : aux) ev.pb(p);
		}
		for(auto p : ev){
			vector<int> pos;
			for(int i=0;i <n; i++){
				if(dist(p, v[i].f) <= (ld)v[i].s.f+eps) pos.pb(v[i].s.s);
			}
			sort(pos.begin(), pos.end(), greater<>());
			int at = 0;
			for(int i=0;i <min(m, (int)pos.size()); i++) at += pos[i];
			ans = max(ans, at);
		}
		cout << ans << endl;

	}



	exit(0);
}
