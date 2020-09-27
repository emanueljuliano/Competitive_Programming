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


ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}


bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea2(p, q, r) > 0;
}

bool operator < (const line& a, const line& b) { // comparador pro sweepline
	if (a.p == b.p) return ccw(a.p, a.q, b.q);
	if (a.p.x != a.q.x and (b.p.x == b.q.x or a.p.x < b.p.x))
		return ccw(a.p, a.q, b.p);
	return ccw(a.p, b.q, b.p);
}

bool ord(pair<pt, ii> a, pair<pt, ii> b){
	if(a.f.x!=b.f.x) return a.f.x < b.f.x;
	if(a.s.f != b.s.f) return a.s.f < b.s.f;
	return a.f.y < b.f.y;
}

const int MAX = 2e5+10;
int id[MAX];

void build(int n){
	for(int i=0;i <n; i++) id[i] = i;
}

int find(int p){
	if(p==id[p]) return p;
	return id[p] = find(id[p]);
}

void une(int p, int q){
	p = find(p), q = find(q);
	if(p==q) return;
	id[p] = q; return;
}

int main(){ _
	int n, c; while(cin >> n >> c){
	
	vector<line> v(n);
	for(auto &i: v) cin >> i.p >> i.q;
	
	
	vector<int> dir(n+c+10);
	vector<pair<pt, ii>> ev;
	for(int i=0;i <c; i++){
		int x; cin >> x;
		
		ev.pb({pt(x, -1), {1, n+i}});
		v.pb(line(pt(x, -1), pt(x, -1)+pt(1, 0)));
	}

	for(int i=0;i <n; i++){
		if(v[i].p.x > v[i].q.x) swap(v[i].p, v[i].q);

		ev.pb({v[i].p, {0, i}});
		ev.pb({v[i].q, {2, i}});

		if(v[i].p.y < v[i].q.y) dir[i] = 1; // acaba em q
		else if(v[i].p.y > v[i].q.y) dir[i] = -1; // acaba em p
		else dir[i] = 0; // horizontal
	}

	sort(ev.begin(), ev.end(), ord);
	set<pair<line, int>> st;
	build(n+c+10);

	vector<pair<pt, int>> ans(n+c+10, {pt(-1, -1), -2});
	for(auto IT : ev){
		int x = IT.f.x, flag = IT.s.f, i = IT.s.s;
		auto it = st.lower_bound({v[i], i});

		if(flag==0){
			if(dir[i]==-1 and it!=st.end()){
				if(dir[it->s]!=0) une(i, it->s);
				else ans[find(i)] = {pt(x, it->f.p.y), 0};
			}
			st.insert({v[i], i});
		}
		else if(flag==2){
			if(dir[i]==1 and it!=st.end() and (++it)!=st.end()){
				if(dir[it->s]!=0) une(i, it->s);
				else ans[find(i)] = {pt(x, it->f.p.y), 0};
			}
			st.erase({v[i], i});
		}
		else{
			if(it!=st.end()){
				if(dir[it->s]!=0) une(i, it->s);
				else ans[find(i)] = {pt(x, it->f.p.y), 0};
			}
			else ans[find(i)] = {pt(x, -1), -2};
		}
	}
	for(int i=0;i <n; i++){
		pt p = v[i].p;
		auto &at = ans[find(i)];
		if(at.s==0) continue;
		if(v[i].q.y > p.y) p = v[i].q;
		if(at.f.y < p.y) at = {p, dir[find(i)]};
	} 
	for(int i=0;i <c; i++){
		pt p = ans[find(i+n)].f;
		int d = ans[find(i+n)].s;
		if(d==0 and p.y!=-2) cout << p.x << " " << p.y << endl;
		else cout << p.x << endl;
	}
	}
	exit(0);
}
