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

map<pt, vector<pt>> mp;

ll solve(pt p, pt angle, ll area, bool minus) {
	auto& v = mp[angle];
	
	int l = 0, r = v.size();
	//cout << "entrou " << p << " angle " << angle << " area " << area << endl;
	while (l < r) {
		int m = (l+r)/2;
		if (abs(sarea2(pt(0, 0), p, v[m])) <= 2*area-minus) l = m+1;
		else r = m;
	}
	//cout << "saiu " << l << " v.size(): " << v.size() << endl;
	return l;
}

bool ord2(pt a, pt b) {
	return dist2(pt(0, 0), a) < dist2(pt(0, 0), b);
}

int main(){ _
	#warning FILE IN 
    freopen("points.in", "r", stdin);	

	int t; cin >> t;
	while (t--) {
		ll n, L, R; cin >> n >> L >> R;
		vector<pt> v(n);
		for (auto &i : v) cin >> i;
		if (n <= 2) {
			cout << 0 << endl;
			continue;
		}	
		ll ans = 0;
		for (int i=0; i<n; i++) {
			//cout << endl << "PONTO CENTRAL " << v[i] << endl;
			mp.clear();
			vector<pt> w, v2;
			
			for (int j=0; j<n; j++) if(j != i) {
				pt p = v[j] - v[i];
				v2.push_back(p);
				int g = gcd(p.x, p.y);
				p.x /= g, p.y/=g;
				if (!mp.count(p)) w.push_back(p);
				mp[p].push_back(v[j]-v[i]);
			}

			sort(w.begin(), w.end(), compare_angle);
			sort(v2.begin(), v2.end(), compare_angle);
			for (auto &[p, vec] : mp) sort(vec.begin(), vec.end(), ord2);
			
			int it = 1%w.size();
			for (int j=0; j<v2.size(); j++) {
				if (sarea2(pt(0, 0), v2[j], w[it]) == 0) it = (it + 1) % w.size();
				while (ccw(pt(0, 0), v2[j], w[it]) and is_act(v2[j], w[it])) 
					it = (it+1)%w.size();
				if (!ccw(pt(0, 0), v2[j], w[it])) continue;	

				//cout << "seg atual " << v2[j] << " it " << w[it] << endl;
				
				if (is_rect(v2[j], w[it])) {
					ans += solve(v2[j], w[it], R, 0) - solve(v2[j], w[it], L, 1);
				}
			}
		}

		cout << ans << endl;
	}
	
	
	exit(0);
}
