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

ll sarea2(pt p, pt q, pt r) {
	return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r) { 
	return sarea2(p, q, r) >= 0;
}

int quad(pt p) { 
   return (p.x<0)^3*(p.y<0);
}

pt rotate90(pt p) { 
	return pt(-p.y, p.x);
}

typedef tuple<pt, int, int> T;
bool ord(T a, T b){
	auto [pa, fa, ida] = a;
	auto [pb, fb, idb] = b;

	if(quad(pa) != quad(pb)) return quad(pa) < quad(pb);
	if(pa.y*pb.x != pb.y*pa.x) return ccw(pb, pt(0, 0), pa);
	return fa < fb;
};

int main(){ _
	int n, q; cin >> n >> q;
	
	vector<pt> v(n);
	vector<pt> query(q);
	for(auto &i : v) cin >> i;
	for(auto &i : query) cin >> i;
	
	if(n<=3){
		for(int i=0;i <q; i++) cout << "Y" << endl;
		return 0;
	}

	vector<T> ev;
	for(int i=0;i <n; i++){
		if(!ccw(v[i], v[(i+1)%n], v[(i+2)%n])){ // verificar ccw

			//cout << i << " " << v[i].x << " " << v[i].y << endl;
			
			pt va = v[i]-v[(i+1)%n];
			pt vb = v[(i+2)%n]-v[(i+1)%n];

			ev.pb(T({pt(0, 0)-rotate90(vb), 2, i}));
			ev.pb(T({rotate90(va), 0, i}));
			ev.pb(T({rotate90(vb), 2, i}));
			ev.pb(T({pt(0, 0)-rotate90(va), 0, i}));
		}
	}
	for(int i=0; i<q; i++){
		ev.pb(T({query[i], 1, i}));
	}
	
	sort(ev.begin(), ev.end(), ord);
	vector<bool> ans(q);
	set<int> st;
	for(int it=0;it <2; it++) for(auto [p, f, id] : ev){
		if(f==1){
			if(st.size()) ans[id] = 1;
		}
		if(f==2){
			st.insert(id);
		}
		if(f==0){
			if(st.count(id)) st.erase(id);
		}
	}
	
	for(auto u : ans){
		if(u) cout << "N" << endl;
		else cout << "Y" << endl;
	}
	
	exit(0);
}
