#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
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

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};


ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}


bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea2(p, q, r) > 0;
}

bool operator < (const line& a, const line& b) { // comparador pro sweepline
	if (a.p == b.p) return ccw(a.p, a.q, b.q);
	if (a.p.x != a.q.x and (b.p.x == b.q.x or a.p.x < b.p.x))
		return ccw(a.p, a.q, b.p);
	return ccw(a.p, b.q, b.p);
}

bool ord(pair<pt, ii> a, pair<pt, ii> b){
	if(a.f.x!=b.f.x) return a.f.x < b.f.x;
	if(a.s.f != b.s.f) return a.s.f < b.s.f;
	if(a.s.f==0) return a.f.y < b.f.y;
	return a.f.y > b.f.y;
}

int main(){ _
	int t=1; while(t--){
	int n; cin >> n;
	vector<line> v(n);
	for(auto &i: v) cin >> i.p >> i.q;

	vector<int> dir(n);
	vector<pair<pt, ii>> ev;
	int mini=INF, maxi=0;
	
	for(int i=0;i <v.size(); i++){
		if(v[i].p.x > v[i].q.x) swap(v[i].p, v[i].q);
		maxi = max(maxi, v[i].q.x), mini = min(mini, v[i].p.x);

		ev.pb({v[i].p, {0, i}});
		ev.pb({v[i].q, {2, i}});

		if(v[i].p.y > v[i].q.y) dir[i] = 1; // acaba em q
		else dir[i] = -1; // acaba em p
	}

	for(int i=mini; i<=maxi; i++){
		ev.pb({pt(i, INF), {3, n+i}});
		v.pb(line(pt(i, INF), pt(i, INF)+pt(1, 0)));
	}	

	sort(ev.begin(), ev.end(), ord);
	set<pair<line, int>> st;
	vector<int> ans(n, 0);
	vector<vector<int>> g(n);

	for(auto IT : ev){
		int flag = IT.s.f, i = IT.s.s;
		auto it = st.lower_bound({v[i], i});
	//	cout << i << " " << flag << endl;
		if(flag==0){
			if(dir[i]==-1 and it!=st.begin()){
				it--;
				g[it->s].pb(i);
			}
			st.insert({v[i], i});
		}
		else if(flag==2){
			if(dir[i]==1 and it!=st.begin()){
				it--;
				g[it->s].pb(i);
			}
			st.erase({v[i], i});
		}
		else{
			if(st.empty()) continue;
			ans[st.rbegin()->s]++;
		}
	}
	vector<int> vis(n);
	function<void(int)> dfs = [&](int i){
		for(auto u : g[i]){
			if(!vis[u]) vis[u]=1, dfs(u);
			ans[i] += ans[u];
		}
	};

	for(int i=0;i <n; i++) if(!vis[i]) vis[i] = 1, dfs(i);
	

	for(int i=0;i <n; i++){
		cout << ans[i] << endl;
	}
	}
	exit(0);
}
