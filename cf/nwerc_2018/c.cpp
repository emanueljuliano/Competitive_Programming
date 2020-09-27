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

typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-4;

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

ld dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
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

int paral(pt u, pt v) { // se u e v sao paralelos
	if (!eq(u^v, 0)) return 0;
	if ((u.x > eps) == (v.x > eps) and (u.y > eps) == (v.y > eps))
		return 1;
	return -1;
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea(p, q, r) > eps;
}

pt rotate(pt p, ld th) { // rotaciona o ponto th radianos
	return pt(p.x * cos(th) - p.y * sin(th),
			p.x * sin(th) + p.y * cos(th));
}

pt rotate90(pt p) { // rotaciona 90 graus
	return pt(-p.y, p.x);
}

// RETA

bool isvert(line r) { // se r eh vertical
	return eq(r.p.x, r.q.x);
}

ld getm(line r) { // coef. ang. de r
	if (isvert(r)) return DINF;
	return (r.p.y - r.q.y) / (r.p.x - r.q.x);
}

ld getn(line r) { // coef. lin. de r
	if (isvert(r)) return DINF;
	return r.p.y - getm(r) * r.p.x;
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

pt proj(pt p, line r) { // projecao do ponto p na reta r
	if (r.p == r.q) return r.p;
	r.q = r.q - r.p; p = p - r.p;
	pt proj = r.q * ((p*r.q) / (r.q*r.q));
	return proj + r.p;
}

pt inter(line r, line s) { // r inter s
	if (paraline(r, s)) return pt(DINF, DINF);

	if (isvert(r)) return pt(r.p.x, getm(s) * r.p.x + getn(s));
	if (isvert(s)) return pt(s.p.x, getm(r) * s.p.x + getn(r));

	ld x = (getn(s) - getn(r)) / (getm(r) - getm(s));
	return pt(x, getm(r) * x + getn(r));
}

bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s)
			or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
		ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int MAX = 1e3+10;
vector<vector<int>> g(MAX);
vector<pair<line, ii>> S;
vector<pt> P;
vector<ld> pa;
const int M = 1e3+7;

void dfs(int v, int pai){
	shuffle(pa.begin(), pa.end(), rng);
	
	int it = 0;
	for(int i=0;i <g[v].size(); i++){
		int u = g[v][i];
		if(u==pai) continue;
		pt ptu;
		while(it<pa.size()){
			ld a = pa[it];
			ptu = pt(P[v].x + cos(a), P[v].y + sin(a));
			bool flag = true;

		}

		while(true){
			int r = rng()%M;
			ld a = double(r)/M*2*pi;
			line s(P[v], ptu);
			for(auto p : S){
				if((p.s.f==v or p.s.s==v) and (ptu==p.f.q or ptu==p.f.p)) {
					flag = false; 
					break;
				}
				if(p.s.f!=v and p.s.s!=v and interseg(p.f, s)) {flag = false; break;}
			}
			if(flag) break;
		}
		P[u] = ptu;
		S.pb({line(P[v], ptu), {v, u}});
		dfs(u, v);
	}
}

int main(){ _
	for(int i=1;i <=M; i++)
		pa.pb(ld(i)/M*2*pi);
	int n; cin >> n;
	vector<int> dg(n);
	P.resize(n);
	for(int i=0;i <n-1; i++){
		int a, b; cin >> a >> b; a--, b--;
		g[a].pb(b);
		g[b].pb(a);
		dg[a]++;
		dg[b]++;
	}

	int root = 0;
	for(int i=0;i <n; i++) if(dg[i]>dg[root]) root=i;

	P[root] = pt(0.0, 0.0);
	dfs(root, -1);

	cout << setprecision(6) << fixed;
	for(int i=0;i <n; i++)
		cout << P[i].x << " " << P[i].y << endl;

	exit(0);
}
