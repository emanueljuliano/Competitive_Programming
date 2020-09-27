// https://www.urionlinejudge.com.br/judge/en/problems/view/1295
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define s second
#define f first
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define sq(x) ((x)*(x))
#define sz(x) (int)(x.size())

typedef long long ll;
typedef pair<int, int> ii;
typedef double ld;

const int INF = 0x3f3f3f3f;
const ld DINF = 1e18;
const ld eps = 1e-9;

bool eq(ld a, ld b){
	return abs(a-b) <= eps;
}

struct pt{
	ld x, y;
	pt() {}
	pt(ld x, ld y) : x(x), y(y) {}
	bool operator < (const pt p) const {
		if(!eq(x, p.x)) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return eq(x, p.x) and eq(y, p.y);
	}
};

bool CY(pt p, pt q){
	return (p.y < q.y + eps);
}

ld dist(pt p, pt q){
	return sqrt(sq(p.x - q.x) + sq(p.y - q.y));
}

ld bruteforce(vector<pt> v){
	ld mini = DINF;
	for(int i=0; i<v.size(); ++i)
		for(int j=i+1; j<sz(v); j++)
			if(dist(v[i], v[j]) <mini)
				mini = dist(v[i], v[j]);
	return mini;
}

ld stripclosest(vector<pt> v, ld d){
	ld mini = d;
	sort(v.begin(), v.end(), CY);
	//for(int i=0; i<sz(v); i++) cout << "(" <<v[i].x << ", " << v[i].y << ") ";
	//cout << endl;
	for(int i=0; i<sz(v); i++){
		for(int j=i+1; j<sz(v) and (v[j].y - v[i].y) < mini; ++j){
			if(dist(v[i], v[j]) < mini)
				mini = dist(v[i], v[j]);
		}
	}
	return mini;
}

ld closestutil(vector<pt> v){
	if(sz(v) <= 3){
		return bruteforce(v);
	}
	int mid = sz(v)/2;
	pt midpt = v[mid];
	
	vector<pt> v1, v2;
	
	for(int i=0; i<sz(v); i++){
		if(i<=mid) v1.pb(v[i]);
		else v2.pb(v[i]);
	}
	ld dl = closestutil(v1);
	ld dr = closestutil(v2);
	//cout << "dl " << dl << " dr " << dr << endl;
	ld d = min(dl, dr);
//	cout << d << endl;

	vector<pt> strip;
	for(int i=0; i<sz(v); i++){
		if(abs(v[i].x - midpt.x) < d)
			strip.pb(v[i]);
	}
	return min(d, stripclosest(strip, d));
}

ld closest(vector<pt> v){
	sort(v.begin(), v.end());
	return closestutil(v);
}

int main(){ //_
	cout << setprecision(4) << fixed;
	while(true){
		int n; cin >> n;
		if(n==0) break;

		vector<pt> v;
		for(int i=0; i<n; i++){
			ld x, y; cin >> x >> y;
			v.pb(pt(x, y));
		}
		ld ans = closest(v);
		if(ans > 10000) cout << "INFINITY" << endl;
		else cout << ans << endl;
	}

	exit(0);
}
