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

#define sq(x) ((x)*(ll)(x))

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

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

// PONTO & VETOR

ll dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return sarea2(p, q, r) == 0;
}

int paral(pt u, pt v) { // se u e v sao paralelos
	if (u^v) return 0;
	if ((u.x > 0) == (v.x > 0) and (u.y > 0) == (v.y > 0)) return 1;
	return -1;
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea2(p, q, r) > 0;
}

int quad(pt p) { // quadrante de um ponto
   return (p.x<0)^3*(p.y<0);
}

bool compare_angle(pt p, pt q) { // retorna se ang(p) < ang(q)
    if (quad(p) != quad(q)) return quad(p) < quad(q);
    return ccw(q, pt(0, 0), p);
}

pt rotate90(pt p) { // rotaciona 90 graus
	return pt(-p.y, p.x);
}

// RETA

bool paraline(line r, line s) { // se r e s sao paralelas
	return paral(r.p - r.q, s.p - s.q);
}

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	if (p == r.p or p == r.q) return 1;
	return paral(p - r.p, p - r.q) == -1;
}

bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

int segpoints(line r) { // numero de pontos inteiros no segmento
	return 1 + __gcd(abs(r.p.x - r.q.x), abs(r.p.y - r.q.y));
}

double get_t(pt v, line r) { // retorna t tal que t*v pertence a reta r
	return (r.p^r.q) / (double) ((r.p-r.q)^v);
}

bool operator < (const line& a, const line& b) { // comparador pro sweepline
	if (a.p == b.p) return ccw(a.p, a.q, b.q);
	if (a.p.x != a.q.x and (b.p.x == b.q.x or a.p.x < b.p.x))
		return ccw(a.p, a.q, b.p);
	return ccw(a.p, b.q, b.p);
}

vector<line> L;
bool ord(pair<ii, ii> a, pair<ii, ii> b){
	if(a.f.f != b.f.f) return a.f.f < b.f.f;
	if(a.f.s != b.f.s) return a.f.s < b.f.s;
	if(a.s.f != b.s.f) return a.s.f < b.s.f;
	return a.s.s<b.s.s;	
}

const int MAX = 3e5+10;
int idd[MAX];
void build(){
	for(int i=0;i <MAX; i++) idd[i]=i;
}

int find(int p){
	if(p==idd[p]) return p;
	return idd[p] = find(idd[p]);
}

void une(int p, int q){
	p = find(p), q=find(q);
	idd[p] = q;
}

int main(){ _
	int n, m; cin >> n >> m;
	
	vector<pair<ii, ii>> ev;
	for(int i=0;i <n; i++){
		int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
		if(x1>x2) swap(x1, x2), swap(y1, y2);
		L.pb(line(pt(x1, y1), pt(x2, y2)));
		int flag = 0;
		if(y1<y2) flag = -1;
		else if(y1>y2) flag = 1;

		ev.pb({{x1, 0}, {flag, i}});
		ev.pb({{x2, 2}, {flag, i}});
	}
	vector<int> v;
	for(int i=0;i <m; i++){
		int x; cin >> x;
		ev.pb({{x, 1}, {0, i+n}});
		v.pb(x);
	}
	
	sort(ev.begin(), ev.end());

	build();
	set<pair<line, int>> st;
	vector<pt> ans(n+m+10);
	for(int i=0;i <n+m; i++) ans[i] = pt(0, 0);

	for(auto IT : ev){
		int id = IT.s.s, flag=IT.f.s, ori=IT.s.f;
		int x = IT.f.f;
		if(flag==0){
			if(ori==0 or ori==-1) st.insert({L[id], id});
			else{
				st.insert({L[id], id});
				auto it = st.lower_bound({L[id], id});
				it++;
				if(it!=st.end()){
					if(it->f.p.y==it->f.q.y){
						ans[find(id)] = pt(x, it->f.p.y);
					}
					else une(id, it->s);
				}
			}
		}
		else if(flag==2){
			if(ori==0 or ori==1) st.erase({L[id], id});
			else{
				auto it = st.lower_bound({L[id], id});
				it++;
				if(it!=st.end()){
					if(it->f.p.y==it->f.q.y){
						ans[find(id)] = pt(x, it->f.p.y);
					}
					else une(id, it->s);
				}
				st.erase({L[id], id});
			}
		}
		else{
			line l(pt(x-1, 0), pt(x, 0));
					
			if(st.size()){
				auto it = st.upper_bound({l, id});
				if(it != st.end()){
					if(it->f.p.y==it->f.q.y){
						ans[find(id)] = pt(x, it->f.p.y);
					}
					else une(id, it->s);
				}
			}
		}
	}
	
	vector<int> vacuo(n+m);
	for(int i=0;i <n; i++){
		int f = find(i);
		if(L[i].p.y > ans[f].y) ans[f] = L[i].p, vacuo[f]=1;
		if(L[i].q.y > ans[f].y) ans[f] = L[i].q, vacuo[f]=1;
	}

	for(int i=0; i<m; i++){
		if(ans[find(i+n)].y==0) cout << v[i] << endl;
		else if(vacuo[find(i+n)]) cout << ans[find(i+n)].x << endl;
		else cout << ans[find(i+n)].x << " " << ans[find(i+n)].y << endl;
	}

	exit(0);
}
