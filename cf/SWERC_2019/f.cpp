#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second
#define sz(x) (int)(x.size())
#define sq ((x)*(x))

typedef double ld;
typedef pair<int, int> ii;
typedef long long ll;

const ld eps = 1e-9;

struct pt{
	ld x, y;
	pt(){}
	pt(ld x, ld y) : x(x), y(y) {}
	pt operator - (const pt p) const {return pt(x-p.x, y-p.y);}
};

ld cross(pt u, pt v){
	return u.x * v.y - u.y * v.x;
} 

ld sarea(pt p, pt q, pt r){
	return cross(q-p, r-q) / 2.0;
}

ld polarea(vector<pt> v){
	ld ret = 0;
	for(int i=0; i<sz(v); i++){
		ret += sarea(pt(0, 0), v[i], v[(i+1) % sz(v)]);
	}
	return abs(ret);
}

int main(){ _
	int n; cin>> n;
	double ans = 0;
	for(int i=0; i<n; i++){
		vector<pt> v;
		int p; cin >> p;
		for(int j=0; j<p; j++){
			double x, y; cin >> x >> y;
			v.pb(pt(x, y));			
		}
		ans += polarea(v);
	}
			cout << (ll)ans << endl;

	exit(0);
}
