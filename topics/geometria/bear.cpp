#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int)(x.size())
#define pb push_back
#define s second
#define f first
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define sq(x) ((x)*(x))


// Primitivas Geometricas

typedef long long ll;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

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
};

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
};

// PONTO & VETOR

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

ld dot(pt u, pt v) { // produto escalar
	return u.x * v.x + u.y * v.y;
}

pt rotate90(pt p) { // rotaciona 90 graus
	return pt(-p.y, p.x);
}

vector<pt> circ_line_inter(pt a, pt b, pt c, ld r) { // intersecao da circunf (c, r) e reta ab
	vector<pt> ret;
	b = b-a, a = a-c;
	ld A = dot(b, b);
	ld B = dot(a, b);
	ld C = dot(a, a) - r*r;
	ld D = B*B - A*C;
	if (D < -eps) return ret;
	ret.push_back(c+a+b*(-B+sqrt(D+eps))/A);
	if (D > eps) ret.push_back(c+a+b*(-B-sqrt(D))/A);
	return ret;
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

int n, m;
vector<pair<pt, int>> cic;

bool dseg(pt p, pt q){
	vector<pair<pt, int>> ev;
	bool ips = false;
	if(p.y > q.y) swap(p, q);
	if(p.x > q.x) swap(p, q);
	ev.pb({p, 2});
	ev.pb({q, 2});

	for(int i=0;i <n; i++){
		vector<pt> seg = circ_line_inter(p, q, cic[i].f, cic[i].s);	
		if(seg.size()<=1) continue;
		pt a = seg[0], b=seg[1];

		if(a.y > b.y) swap(a, b);
		if(a.x > b.x) swap(a, b);
		ev.pb({a, 1});
		ev.pb({b, 3});
	}
	sort(ev.begin(), ev.end());
	//cout << " ev " << ev.size() << endl;
	//for(auto x : ev) cout << "(" << x.f.x << ", " << x.f.y << ") -" << x.s<<"- ";
	//cout << endl;
	int at = 0;
	
	bool ini = false;
	for(int i=0;i <ev.size(); i++){
		if(ev[i].s==2 and ini) break;
		if(ev[i].s==2) ini = true;
		
		if(ev[i].s==1) at++;
		else if(ev[i].s==3) at--;
		if(at<=0 and ini) return false;
	}
	return true;
}

const int MAX = 2e5;
ld di[MAX];
vector<vector<pair<int, ld>>> g(MAX);

void dji(int x){
	for(int i=0;i <MAX; i++) di[i] = -1.0;
	set<pair<ld, int>> st;
	st.insert({0.0, x});
	while(!st.empty()){
		pair<ld, int> aux = *st.begin();
		st.erase(aux);
		x = aux.s;
		ld d = aux.f;
		if(di[x]<-0.5){
			di[x] = d;
			for(int i=0; i<g[x].size(); i++){
				pair<int, ld> u = g[x][i];
				if(di[u.f]<-0.5) st.insert({u.s+d, u.f});
			}
		}
	}
}

int main(){ _
	ld xa, ya, xb, yb; cin >> xa >> ya >> xb >> yb;
	pt b1(xa, ya), b2(xb, yb);
	cout << setprecision(9) << fixed;
	if(eq(xa, xb) and eq(ya, yb))return  cout << 0.0000000 << endl, 0;
	cin >> n;
	for(int i=0;i <n; i++){
		ld a, b, c; cin >> a >> b >> c;
		cic.pb({pt(a, b), c});
	}

	vector<pt> ver;
	ver.pb(b1); ver.pb(b2);
	for(int i=0;i <n; i++){
		for(int j=i+1; j<n; j++){
			vector<pt> inter = circ_inter(cic[i].f, cic[j].f, cic[i].s, cic[j].s);
			for(pt x : inter) ver.pb(x);
		}
	}

	m = ver.size();
	
	for(int i=0;i <m-1; i++){
	//	cout << "Ponto 1 = (" << ver[i].x << ", " << ver[i].y << ") " << endl;
		for(int j=i+1;j <m; j++){
	//		cout << "Ponto 2 = (" << ver[j].x << ", " << ver[j].y << ") ";
			if(dseg(ver[i], ver[j])){
				ld d = dist(ver[i], ver[j]);
				g[i].pb({j, d});
				g[j].pb({i, d});
	//			cout << "Dist = " << d << endl;
			}
			else{
	//			cout << "Nop " << endl;
			}
		}
	//	cout << endl;
	}
	dji(0);
	ld ans = di[1];
	cout << setprecision(9) << fixed;
	if(ans<-0.5) cout << "impossible" << endl;
	else cout << ans << endl;

	exit(0);
}





