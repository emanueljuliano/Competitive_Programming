#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

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
	friend ostream& operator << (ostream& out, pt& p) {
		return out << "(" << p.x << ", " << p.y << ") ";
	}

};

ll dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
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

bool is_rect(pt p, pt q) {
	// p.y/p.x == -q.x/q.y
	return p*q == 0;
}

bool is_act(pt p, pt q) {
	return p * q > 0;
}


int main(){ _
	#warning FILE IN 
   // freopen("points.in", "r", stdin);	

	int t; cin >> t;
	while (t--) {
		ll n, L, R; cin >> n >> L >> R;
		vector<pt> v(n);
		for (auto &i : v) cin >> i;
		ll ans = 0;
		for (int i=0; i<n; i++) for (int j=0; j<n; j++)
		for (int k=0; k<n; k++) {
			if (i == j or i == k or j == k) continue;
			pt p = v[j]-v[i], q = v[k]-v[i];
			ll area = abs(sarea2(v[i], v[j], v[k]));
			if (is_rect(p, q) and area >= 2*L and area <= 2*R) {
				cout << v[i] << " " << v[j] << " " << v[k] << endl;
				ans++;
			}
		}
		cout << ans/2 << endl;

	}
	
	
	exit(0);
}
