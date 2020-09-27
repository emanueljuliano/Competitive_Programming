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

typedef long double ld;
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
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
};

pt rotate(pt p, ld th) { // rotaciona o ponto th radianos
	return pt(p.x * cos(th) - p.y * sin(th),
		p.x * sin(th) + p.y * cos(th));
}

vector<pt> v;

ld query(ld ang){
	ld x1=DINF, x2=-DINF, y1=DINF, y2=-DINF;
	for(int i=0; i<v.size(); i++){
		pt at = rotate(v[i], ang);
		if(at.x < x1) x1 = at.x;
		if(at.x > x2) x2 = at.x;
		if(at.y < y1) y1 = at.y;
		if(at.y > y2) y2 = at.y;
	}
	return max(x2-x1, y2-y1);
}

int main(){ _
	int t; cin >> t;
	while(t--){
		v.resize(0);
		ld n; cin >> n; n*=2.0;
		pt at; at.x = 0, at.y=0; ld ang = 0;
		for(int i=0; i<n;i++){
			ang += pi*2.0/n;
			at.x += cos(ang); at.y += sin(ang);
			v.pb(at);
		}
		
		ld ans = DINF;
		ld l = 0.0; ld r = pi/n;
		for(int i=0; i<200; i++){
			if(eq(l, r)) break;
			ld th = (r-l)/3.0;
			ld q1 = query(l+th), q2 = query(r-th);
			ans = min(ans, q1);
			ans = min(ans, q2);
			if(q1<q2)  r-=th;
			else l+=th;
		}
		cout << setprecision(6) << fixed;
		cout << ans << endl;
	}



	exit(0);
}
