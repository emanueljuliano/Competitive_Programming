#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x.size())
#define pb push_back
#define s second
#define f first
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define sq(x) ((x)*(x))

typedef long long ll;
typedef pair<int, int> ii;
typedef double ld;

const int INF = 0x3f3f3f3f;
const ld DINF = 1e18;
const ld eps = 1e-9;

bool eq(ld a, ld b){
	return abs(a-b) <= eps;
}

struct pt{
	ld x, y;
	pt() {}
	pt(ld x, ld y) : x(x), y(y) {}
	bool operator == (const pt p) const {return eq(x, p.x) and eq(y, p.y);}
	pt operator + (const pt p) const {return pt(x+p.x, y+p.y);}
	pt operator - (const pt p) const {return pt(x-p.x, y-p.y);}
	pt operator * (const ld c) const {return pt(x*c, y*c);}
};

ld dist(pt p, pt q){
	return hypot(p.x-q.x, p.y-q.y);
}

ld dot(pt u, pt v){
	return u.x * v.x + u.y * v.y;
}

ld cross(pt u, pt v){
	return u.x*v.y - u.y * v.x;
}

ld sarea(pt p, pt q, pt r){
	return cross(q-p, r-q) / 2.0;
}

bool ccw(pt p, pt q, pt r){
	return sarea(p, q, r)>0;
}

struct line{
	pt p, q;

	line() {}
	line(pt p, pt q) : p(p), q(q) {}
};


pt proj(pt p, line r){
	if(r.p == r.q) return r.p;
	r.q = r.q - r.p; p = p-r.p;
	pt proj = r.q * (dot(p, r.q) / dot(r.q, r.q));
	return proj + r.p;
}

ld distoline(pt p, line r){
	return dist(p, proj(p, r));
}

int main(){ _
	while(true){
	int n; cin >> n;
	if(n==0) break;

	vector<pt> v;
	for(int i=0; i<n; i++) {ld a, b; cin >> a >> b; v.pb(pt(a, b));}

	ld ans = DINF;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			ld el=0, er=0;
			line r(v[i], v[j]);
			for(int k=0; k<n; k++){
				ld d = distoline(v[k], r);
				if(ccw(v[i], v[j], v[k])) el += d;
				else er += d;
			}
			if(abs(el-er)<ans) ans = abs(el-er);
		}
	}
	cout << setprecision(3) << fixed;
	cout << ans << endl;
	}
	exit(0);
}
