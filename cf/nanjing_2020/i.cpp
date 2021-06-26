#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

struct pt {
	int x, y;
	pt() {}
	pt(int x_, int y_) : x(x_), y(y_) {}
	bool operator == (const pt p) const { return x == p.x and y == p.y; }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
};

struct line {
	pt p; pt q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
};

ll sarea2(pt p, pt q, pt r) {
	return (q-p)^(r-q);
}

int paral(pt u, pt v) { 
	if (u^v) return 0;
	if ((u.x > 0) == (v.x > 0) and (u.y > 0) == (v.y > 0)) return 1;
	return -1;
}

bool ccw(pt p, pt q, pt r) {
	return sarea2(p, q, r) > 0;
}

bool isinseg(pt p, line r) { 
	if (p == r.p or p == r.q) return 1;
	return paral(p - r.p, p - r.q) == -1;
}


bool interseg(line r, line s) {
	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 0;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

int main(){ _
	int n, m, vy; cin >> n >> m >> vy;
	vector<line> seg;
	vector<pt> ev;
	
	ev.push_back(pt(0, -INF));
	for (int i=0; i<n; i++) {
		int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
		seg.push_back(line(pt(x1, y1), pt(x2, y2)));	
		
		if (abs(x1) != m) ev.push_back(pt(x1, y1));
		if (abs(x2) != m) ev.push_back(pt(x2, y2));
	}
	ev.push_back(pt(0, INF));
	int sink = ev.size()-1, source = 0;

	vector<vector<pair<int, double>>> g(ev.size());
	for (int i=0; i<ev.size(); i++) for (int j=i+1; j<ev.size(); j++) {
		pt p1 = ev[i], p2 = ev[j];
		bool inter = false;
		for (auto s : seg) inter |= interseg(s, line(p1, p2));
		if (!inter) {
			if (i == source or j == sink)
				g[i].push_back({j, 0});
			else {
				double w = double(p1.x-p2.x) * vy / (p1.y - p2.y); 
				if (w < 0) w = -w;
				if (p1.y < p2.y) g[i].push_back({j, w});
				else g[j].push_back({i, w});
			}
		}
	}	
	
	vector<double> dp(ev.size(), -5);
	function<void(int)> dfs = [&](int i) {
		dp[i] = INF;
		if (i == sink) dp[i] = 0;
		for (auto [j, w] : g[i]) {
			if (dp[j] < -1) dfs(j);
			if (dp[j] < INF-1) dp[i] = min(dp[i], max(dp[j], w));
		}
	};
	dfs(source);
	
	cout << setprecision(9) << fixed;
	if (dp[source] < -1 or dp[source] > INF-1)
		cout << -1 << endl;
	else cout << dp[source] << endl;

	exit(0);
}
