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

typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt3 { // ponto
	ld x, y, z;
	pt3() {}
	pt3(ld x_, ld y_, ld z_) : x(x_), y(y_), z(z_) {}
	bool operator < (const pt3 p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		if (!eq(z, p.z)) return z < p.z;
		return 0;
	}
	bool operator == (const pt3 p) const {
		return eq(x, p.x) and eq(y, p.y) and eq(z, p.z);
	}
	pt3 operator + (const pt3 p) const { return pt3(x+p.x, y+p.y, z+p.z); }
	pt3 operator - (const pt3 p) const { return pt3(x-p.x, y-p.y, z-p.z); }
	pt3 operator * (const ld c) const { return pt3(x*c  , y*c  , z*c  ); }
	pt3 operator / (const ld c) const { return pt3(x/c  , y/c  , z/c  ); }
	ld operator * (const pt3 p) const { return x*p.x + y*p.y + z*p.z; }

	void rotate_x(ld a) {
		ld ny = y*cos(a) - z*sin(a);
		ld nz = y*sin(a) + z*cos(a);
		y = ny;
		z = nz;
	}
	void rotate_y(ld a) {
		ld nx =  x*cos(a) + z*sin(a);
		ld nz = -x*sin(a) + z*cos(a);
		x = nx;
		z = nz;
	}
	void rotate_z(ld a) {
		ld nx = x*cos(a) - y*sin(a);
		ld ny = x*sin(a) + y*cos(a);
		x = nx;
		y = ny;
	}
};

ld dist3(pt3 a, pt3 b) {
	return sqrt(sq(a.x-b.x) + sq(a.y-b.y) + sq(a.z-b.z));
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

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	if (p == r.p or p == r.q) return 1;
	return paral(p - r.p, p - r.q) == -1;
}


// POLIGONO

ld polarea(vector<pt> v) { // area do poligono
	ld ret = 0;
	for (int i = 0; i < v.size(); i++)
		ret += sarea(pt(0, 0), v[i], v[(i + 1) % v.size()]);
	return abs(ret);
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
		return !ccw(p, pol[l], pol[l-1]);
	}
};

const int MAX = 1e4+10;
int id[MAX], sz[MAX];
void build(){
	for(int i=0; i<MAX-5; i++) id[i]=i, sz[i]=1;
}
int find(int p){
	if(id[p]==p) return p;
	return id[p] = find(id[p]);
}
void une(int p, int q){
	p = find(p), q = find(q);
	if(p==q) return;
	if(sz[p]>sz[q]) swap(p, q);
	id[p] = q;
	sz[q] += sz[p];
}

vector<pt3> p3;
vector<vector<int>> g(MAX);
int vis[MAX];
vector<ld> dp(MAX, INF), val(MAX);
ld R, A;
vector<bool> ex(MAX);

void dfs(int x){
	ld ret = INF;
	if(ex[x]) ret = 0;
	dp[x] = ret;
	for(auto u : g[x]){
		if(!vis[u]) vis[u] = 1, dfs(u);
		ret = min(ret, dp[u] + p3[x].z-p3[u].z + val[u]);
	}
	dp[x] = ret;
}

int main(){ _
	int n; cin >> n;
	for(int i=0;i <n; i++){
		ld a, b, c; cin >> a >> b >> c;
		pt3 p(a, b, c);
		p3.pb(p);
	}
	vector<ii> v;
	int m; cin >> m; v.resize(m);
	for(auto &u : v) cin >> u.f >> u.s, u.f--;

	build();
//	cout << "Cachorros" << endl;
	for(int i=0;i <m; i++){
		for(int j=i+1; j<m; j++){
			if(dist3(p3[v[i].f], p3[v[j].f]) <= max(v[i].s, v[j].s)){
				une(i, j);
//				cout << v[i].f+1 << " " << v[j].f+1 << endl;
//				cout << i << " " << j << " " << dist3(p3[v[i].f], p3[v[j].f]) << endl; 
			}
		}
	}

	vector<vector<pt>> pack(m);
	for(int i=0;i <m; i++) pack[find(i)].pb(pt(p3[i].x, p3[i].y));
	
	for(auto u : pack){
		if(u.size()<=2) continue;
		convex_pol hull(u);
//		cout << "POLIGONO" << endl;
//		for(auto a : hull.pol) cout << a.x << " "<< a.y << endl;
		ld a = polarea(hull.pol);
//		cout << "AREA " << a << endl;
		for(int i=0;i <n; i++){
			if(hull.is_inside(pt(p3[i].x, p3[i].y))) val[i]+=a;
		}
	}

	int k; cin >> k;
	for(int i=0;i <k; i++){
		int a; cin >> a; ex[a-1] = 1;
	}

	int x; cin >> x >> R >> A; x--;
//	cout << "GRAFO" << endl;
	for(int i=0;i <n; i++){
		for(int j=i+1; j<n; j++){
//			cout << i << " "<< j << " " << dist3(p3[i], p3[j]) << endl;
			if(dist3(p3[i], p3[j]) > R + eps) continue; 
			if(p3[i].z>p3[j].z) g[i].pb(j);
			else if(p3[i].z<p3[j].z) g[j].pb(i);
			else g[i].pb(j), g[j].pb(i);
		}
	}

	vis[x] = 1;
	dfs(x); 
	ld mini = dp[x];
/*	for(int i=0;i <n; i++){
		cout << "(" << i << ") ";
		for(auto u : g[i]) cout << u<< " ";
		cout << endl;
	}
	cout << "VALORES" << endl;
	for(int i=0;i <n; i++) cout << i << " "<< val[i] << " " << dp[i]<< endl;
*/	
	cout << setprecision(7) << fixed;
	if(ex[x]) cout << A << endl;
	else if(mini<=A+eps) cout << A-mini << endl;
	else cout << -1.0 << endl;
	exit(0);
}
