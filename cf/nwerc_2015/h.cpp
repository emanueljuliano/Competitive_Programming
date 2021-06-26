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

typedef tuple<int, int, int, int> T;
typedef long double ld;
typedef vector<pair<ld, ld>> vp;
ld pi = acos(-1);
ld eps = 1e-8;
pair<ld, ld> zero = {0, 2*pi};

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

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}
bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea(p, q, r) > eps;
}

vp ang(T l){
	auto [x1, y1, x2, y2] = l;
	if(y1>y2) swap(y1, y2), swap(x1, x2);
	ld a1 = atan2(ld(y1), ld(x1)), a2 = atan2(ld(y2), ld(x2));
	if(a1<0) a1 += 2*pi;
	if(a2<0) a2 += 2*pi;
	
	if(x1==x2 and y1<=0 and y2>=0 and x1>0){
		return {{0, a2}, {a1, 2*pi}};
	}
	if(a1>a2) swap(a1, a2);
	return {{a1, a2}};
}

vp inter(vp l, vp r){
	vp ret;
	for(auto [a1, a2] : l)
		for(auto [b1, b2] : r){
			if(b2+eps<a1 or a2+eps<b1) continue;
			ret.pb({max(a1, b1), min(a2, b2)});
		}
	return ret;
}

vp inter2(vp l, vp r){
//	cout << "INTER2" << endl;
//	for(auto [a, b] : l) cout << "l " << a << " " << b << endl;
//	for(auto [a, b] : r) cout << "r " << a << " " << b << endl;
	vp ret;
	for(auto [a1, a2] : l){
		vp at = {{a1, a2}};
		for(auto [b1, b2] : r){
			vp nat;
			for(auto [c1, c2] : at){
				if(b2<c1+eps or c2<b1+eps) nat.pb({c1, c2});
				else if(b1+eps<c1 and c2+eps<b2) continue;
				else if(b1+eps<c1 and c1+eps<b2) nat.pb({b2, c2});
				else if(b1+eps<c2 and c2+eps<b2) nat.pb({c1, b1});
				else nat.pb({c1, b1}), nat.pb({b2, c2});
			}
			at = nat;
		}
		for(auto u : at) ret.pb(u);
	}
//	for(auto [a, b] : ret) cout << "ret " << a << " " << b << endl;
//	if(l.size() and !ret.size()) cout << "AQUIIIIIIIIIIIIIIIIIIIIIIII" << endl;	
	return ret;
}

void reflex(vector<T> &v, T l, ii &p){
	auto [x1, y1, x2, y2] = l;
	if(x1==x2){
		p.f = x1+(x1-p.f);
		for(auto &[x3, y3, x4, y4] : v) 
			x3 = x1 + (x1-x3), x4 = x1 + (x1-x4);
	}
	else if(y1==y2){
		p.s = y1+(y1-p.s);
		for(auto &[x3, y3, x4, y4] : v) 
			y3 = y1 + (y1-y3), y4 = y1 + (y1-y4);
	}
}

int main(){ _
	int n; cin >> n;
	ii t; cin >> t.f >> t.s;
	vector<T> w(n);
	for(auto &[x1, y1, x2, y2] : w) cin >> x1 >> y1 >> x2 >> y2;
	if(n==0){
		cout << 0 << endl;
		exit(0);
	}
	sort(w.begin(), w.end());
	int ans = -1;
	
	do{
		vp angles = {zero};
		vector<T> v = w;
		ii p = t;
		if(get<0>(v[0]) == get<2>(v[0])){
			for (auto &[x1, y1, x2, y2] : v) 
				swap(x1, y1), swap(x2, y2), x1*=-1, x2*=-1;
			swap(p.f, p.s), p.f*=-1;
		}
		if(get<1>(v[0])<0) 	
			reflex(v, {-INF, 0, INF, 0}, p);
		
		int xat = 0, yat = 0, it=0;
		auto can = [&](int i){
			ld a = atan2(ld(p.s), ld(p.f));
			if(a<0) a += 2*pi;
			bool ret = false;
			for(auto [a1, a2] : angles) if(a1<=a+eps and a <= a2+eps) ret = true;
			//cout << "can? " << ret << endl;
			for(int j=i; j<n; j++) {
				continue;
				auto [x1, y1, x2, y2] = v[j];
				if(x1==x2 and abs(x1)<=abs(xat)) continue;
				if(y1==y2 and abs(y1)<=abs(yat)) continue;
				pt rp, rq, sp, sq;
				rp = pt(x1, y1), rq = pt(x2, y2), sp = pt(0, 0), sq = pt(p.f, p.s);
				if(ccw(rp, rq, sp) != ccw(rp, rq, sq) and
					ccw(sp, sq, rp) != ccw(sp, sq, rq)) ret = false;
			}
			if(i==5) cout << ret << " " << abs(xat) << " " << yat << " " << abs(p.f) << " " << p.s << endl;
			//if(i and (abs(p.f)<abs(xat) or p.s<yat)) ret = false;
			return ret;
		};
		//cout << "NOVA PERMUTACAO" << endl;	
		for(int i=0; i<n; i++){
			if(can(i)) ans = max(ans, i);
			if(i==5){cout << "i: " << i<< endl;
			cout << "angles " << endl;
			for(auto [a, b] : angles) cout << a << " " << b << endl;
			cout << "segments " << endl;
			for(int j=i; j<n; j++)
				cout << get<0>(w[j]) << " " << get<1>(w[j]) << " " << get<2>(w[j]) << " " << get<3>(w[j]) << endl; 
			cout << "point " << endl;
			cout << p.f << " "<< p.s << endl;
			cout << "xat " << xat << " yat " << yat << endl;
			cout << endl;
			}
			angles = inter(angles, ang(v[i]));
			auto [x3, y3, x4, y4] = v[i];
			//if(x3==x4 and abs(x3)<abs(xat)) break;
			//if(y3==y4 and y3<yat) break;
			for(int j=i+1; j<n; j++){
				auto [x1, y1, x2, y2] = v[j];
				if(y3==y4){
					if(y1==y2 and y1>0 and y1<y3 and y1>yat) 
						angles = inter2(angles, ang(v[j]));
					else if(x1==x2 and max(y1, y2)>0 and min(y1, y2)<y3 and abs(x1)>abs(xat)){
						if(y1>y2) swap(y1, y2), swap(x1, x2);
						y2 = min(y2, y3);
						angles = inter2(angles, ang({x1, y1, x2, y2}));
					}
				}
				else{
					if(x1==x2 and abs(x1)<=abs(x3) and abs(x1)>xat) 
						angles = inter2(angles, ang(v[j]));
					else if(y1==y2 and y1>=0 and y1<=max(y3, y4) and y1>yat) 
						angles = inter2(angles, ang(v[j]));
				}
			}
			if(!angles.size()) break;
			reflex(v, v[i], p);
			if(x3==x4) xat = x3;
			if(y3==y4) yat = y3;
			it++;
		}
		if(it==n and can(n)) ans = max(ans, n);

	}while(next_permutation(w.begin(), w.end()));
	
	if(ans != -1) cout << ans << endl;
	else cout << "impossible" << endl;
	exit(0);
}
