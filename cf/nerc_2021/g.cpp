#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

#define sq(x) ((x)*(X))

const ld eps = 1e-8;

bool eq(ld a, ld b){
	return abs(a-b) <= eps;
}

struct pt{
	ld x, y;
	pt() {}
	pt (ld x_, ld y_) : x(x_), y(y_) {}
	pt operator +  (const pt p) const {return pt(x+p.x, y+p.y);}
	pt operator -  (const pt p) const {return pt(x-p.x, y-p.y);}
	pt operator *  (const ld c) const {return pt(x*c, y*c);}
	pt operator /  (const ld c) const {return pt(x/c, y/c);}
	ld operator *  (const pt p) const {return x*p.x+y*p.y;}
	ld operator ^  (const pt p) const {return x*p.y - y*p.x;}
};

struct line{
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
};

ld dist(pt p, pt q){
	return hypot(p.y - q.y, p.x - q.x);
}

int paral(pt u, pt v){
	if(!eq(u^v, 0)) return 0;
	if((u.x>eps) == (v.x>eps) and (u.y>eps) == (v.y>eps)) return 1;
	return -1;
}

bool paraline(line r, line s){
	return paral(r.p - r.q, s.p - s.q);
}

ld get_t(pt v, line r){
	assert(abs((r.p-r.q)^v) >eps);
	return (r.p^r.q) / ((r.p-r.q)^v);
}

pt inter(line r, line s){
	if(paraline(r, s)) return s.p;
	r.q = r.q - r.p, s.p = s.p-r.p, s.q = s.q - r.p;
	return r.q*get_t(r.q, s) + r.p;
}
int n, h;
pt ini;
bool see(pt p, pt q){
	//(ini.y-p.y)/(ini.x-p.x) > (p.y-q.y)/(p.x-q.x)
	return (ini.y-p.y)*(ini.x-q.x) + eps >= (ini.y-q.y)*(ini.x-p.x);
}

int main(){ _
	cin >> n >> h;
	
	vector<pt> v(n);
	for(int i=0;i <n; i++){
		int x, y; cin >> x >> y;
		v[i] = pt(x, y);
	}
	reverse(v.begin(), v.end());
	ini = pt(v[0].x, v[0].y+h);

	pt at = v[0];
	ld ans = 0;
	for(int i=1;i <n; i++){
		if(see(at, v[i])) {
			ans += dist(inter(line(ini, at), line(v[i-1], v[i])), v[i]);
			at = v[i];
		}
		//cout << "pt = (" << v[i].x << ", " << v[i].y << ") ans = " << ans << endl;
	}

	cout << setprecision(8) << fixed;
	cout << ans << endl;

	
	
	exit(0);
}
