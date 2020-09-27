#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
const double EPS = 1E-9;
double eps = 1e-8;
struct pt {
	double x, y;
};

struct seg {
	pt p, q;
	int id;

	double get_y(double x) const {
		if (abs(p.x - q.x) < EPS) return p.y;
		return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
	}
};

bool intersect1d(double l1, double r1, double l2, double r2) {
	if (l1 > r1) swap(l1, r1);
	if (l2 > r2) swap(l2, r2);
	return max(l1, l2) <= (min(r1, r2) + EPS);
}

int vec(const pt& a, const pt& b, const pt& c) {
	double s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if(abs(s) < EPS) return 0;
	if(s>0) return 1;
	return -1;
}

bool intersect(const seg& a, const seg& b)
{
	return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x) &&
		intersect1d(a.p.y, a.q.y, b.p.y, b.q.y) &&
		vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0 &&
		vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
}

bool operator<(const seg& a, const seg& b)
{
	double x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
	double val = a.get_y(x);
	double val2 = b.get_y(x);
	if(val==val2) return a.id < b.id; //DIFERENTE
	return val < val2 - EPS;
}

struct event {
	double x;
	int tp, id;

	event() {}
	event(double x, int tp, int id) : x(x), tp(tp), id(id) {}

	bool operator<(const event& e) const {
		if (abs(x - e.x) > EPS) return x < e.x;
		return tp > e.tp;
	}
};

set<seg> s;
vector<set<seg>::iterator> where;

set<seg>::iterator prev(set<seg>::iterator it) {
	return it == s.begin() ? s.end() : --it;
}

set<seg>::iterator next(set<seg>::iterator it) {
	return ++it;
}
int solve(vector<seg>& a) {
	int ret = 0;
	int n = (int)a.size();
	vector<event> e;
	for (int i = 0; i < n; ++i) {
		e.push_back(event(a[i].p.x, +1, i));
		e.push_back(event(a[i].q.x, -1, i));
	}
	sort(e.begin(), e.end());
//	cout << n << endl;
	s.clear();
	where.resize(a.size());
	for (size_t i = 0; i < e.size(); ++i) {
		int id = e[i].id;
		if (e[i].tp == +1) {
			set<seg>::iterator nxt = s.lower_bound(a[id]), prv = prev(nxt);
			if (nxt != s.end() && intersect(*nxt, a[id]))
				if(abs(nxt->id - id) > 1 && abs(nxt->id - id) != n-1) 
					ret++;
			if (prv != s.end() && intersect(*prv, a[id]))
				if(abs(prv->id - id) > 1 && abs(prv->id - id) != n-1) 
					ret++;
			where[id] = s.insert(nxt, a[id]);
		} else {
			set<seg>::iterator nxt = next(where[id]), prv = prev(where[id]);
			if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
				if(abs(prv->id - nxt->id) > 1 && abs(prv->id - nxt->id) != n-1) 
					ret++;
			s.erase(where[id]);
		}
	}

	return ret;
}

int main(){
	while(true){
		int n;	cin >> n;
		if(n==0) break;
		vector<pt> v;
		for(int i=0;i <n; i++){
			int a, b; cin >> a >> b;
			v.pb({double(a), double(b)});
		}
		vector<seg> w;
		for(int i=0;i <n; i++){
			seg x;
			x.p = v[i]; x.q = v[(i+1)%n]; x.id = i;
			if(x.p.x > x.q.x) swap(x.p, x.q);
			w.pb(x);
		}
		//cout << solve(w) << endl;
		if(solve(w)) cout << "NO" << endl;
		else cout << "YES" << endl;
	}




}
