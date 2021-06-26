#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ld DINF = 1e18;

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
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

ld max_dist_manhattan(vector<pt> v) {
	ld mini_sum = maxi_sum = v[0].x + v[0].y;
	ld mini_sum = maxi_sum = v[0].x - v[0].y;
	for (auto [x, y] : v) {
		mini_sum = min(mini_sum, x+y);
		maxi_sum = max(maxi_sum, x+y);
		mini_dif = min(mini_dif, x-y);
		maxi_dif = max(maxi_dif, x-y);
	}
	return max(maxi_sum - mini_sum, max_dif - mini_dif);
}

int main(){ _
	int n; cin >> n;
	vector<pair<double, double>> V(n), v;
	for (int i=0;i <n; i++) {
		int x, y; cin >> x >> y;
		V[i] = {x, y};
	}
	
	int a=0, b=1;
	double d=0;
	
	// solve x e y
	for (int f = 0; f<2; f++){
		v = V;
		for (int i=0; i<n; i++) {
			auto &[x, y] = v[i];
			if (f==0) x = (sqrt(2.0)-1)*x;
			else y = (sqrt(2.0)-1)*y;
		}
		
		vector dist(2, vector<pair<double, int>>(n));
		for (int i=0; i<n; i++) {
			dist[0][i] = {v[i].first+v[i].second, i};
			dist[1][i] = {v[i].first-v[i].second, i};
		}
		for (int i=0; i<2; i++) {
			sort(dist[i].begin(), dist[i].end());
			double di = dist[i].back().first - dist[i][0].first;
			if (di > d) {
				d = di;
				a = dist[i].back().second;
				b = dist[i][0].second;
			}
		}
	}

	cout << a+1 << " "<< b+1 << endl;
	
	exit(0);
}
