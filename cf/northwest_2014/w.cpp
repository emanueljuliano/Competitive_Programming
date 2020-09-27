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

typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

struct pt { // ponto
	ld x, y, z;
	pt() {}
	pt(ld x_, ld y_, ld z_) : x(x_), y(y_), z(z_) {}
	bool operator < (const pt p) const {
		if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		if (!eq(z, p.z)) return z < p.z;
		return 0;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y) and eq(z, p.z);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y, z+p.z); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y, z-p.z); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  , z*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  , z/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y + z*p.z; }
};
// distancia
ld dist(pt a, pt b) {
	return sqrt(sq(a.x-b.x) + sq(a.y-b.y) + sq(a.z-b.z));
}

int main(){ _
	int tt; cin >> tt;
	for(int cs = 1; cs<=tt; cs++){
		cout << "Case " << cs << ":" << endl;
	
		int n; cin >> n;
		map<string, int> mp;
		int ptr = 0;
		vector D(n, vector<ld> (n));
		vector<pt> v(n);
		for(int i=0;i <n; i++){
			string s; cin >> s;
			ld x, y, z; cin >> x >> y >> z;
			v[ptr] = pt(x, y, z);
			mp[s] = ptr++;
		}
		for(int i=0;i <n; i++) for(int j=0; j<n; j++){
			if(i==j) continue;
			D[i][j] = dist(v[i], v[j]);
		}
		int m; cin >> m;
		for(int i=0;i <m; i++){
			string s, t; cin >> s >> t;
			D[mp[s]][mp[t]] = 0;
		}
		
		auto floyd = [&](){
			for (int k = 0; k < n; k++)
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
		};
		floyd();
		int q; cin >> q;
		while(q--){
			string s, t; cin >> s >> t;
			ll d = round(D[mp[s]][mp[t]]);
			cout << "The distance from " << s << " to " << t << " is " << d << " parsecs." << endl;
		}
	
	}
	exit(0);
}
