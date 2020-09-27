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

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}
bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea2(p, q, r) > 0;
}

int main(){ _

	ll n; cin >> n;
	vector<pt> v(n);
	for(auto &i: v) cin >> i;
	int t; cin >> t;
	while(t--){
		ll ans = n*(n-1)*(n-2)/6;
		pt p; cin >> p;
		int at=1;
		for(int i=0;i <n; i++){
			if(i==at) at = (at+1)%n;
			while(!ccw(v[i], v[at], p)) at = (at+1)%n;
			at = (at-1+n)%n;
			if(at==i) {ans=0; break;}
			ll x = (at-i+n)%n;
			ans -= x*(x-1)/2;
		}
		cout << ans << endl;
	}
	exit(0);
}
