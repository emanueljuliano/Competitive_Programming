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

vector<string> vs;
namespace aho {
	const vector<pair<char, char>> vt = {
		{'A', 'Z'}
	};

	void fix(char &c){
		int acc = 0;
		for (auto p : vt){
			if (p.first <= c && c <= p.second){
				c = c - p.first + acc;
				return;
			}
			acc += p.second - p.first + 1;
		}
	}
	void unfix(char &c){
		int acc = 0;
		for (auto p : vt){
			int next_acc = acc + p.second - p.first;
			if (acc <= c && c <= next_acc){
				c = p.first + c - acc;
				return;
			}
			acc = next_acc + 1;
		}
	}
	void fix(string &s){ for (char &c : s) fix(c); }
	void unfix(string &s){ for (char &c : s) unfix(c); }


	const int SIGMA = 26;//fix(vt.back().second) + 1;
	const int MAXN = 2e6+10;

	int to[MAXN][SIGMA];
	int link[MAXN], end[MAXN];
	int idx;
	void init(){
		memset(to, 0, sizeof to);
		memset(end, 0, sizeof end);
		memset(link, 0, sizeof link);
		idx = 1;
	}
	void insert(string &s, int id){
		fix(s);
		int v =  0;
		for (char c : s){
			int &w = to[v][c];
			if (!w) w = idx++;
			v = w;
		}
		end[v] = id;
	}
	void build(){
		queue<int> q;
		q.push(0);
		while (!q.empty()){
			int cur = q.front(); q.pop();
			int l = link[cur];
			end[cur] |= end[l];
			for (int i = 0; i < SIGMA; i++){
				int &w = to[cur][i];
				if (w){
					link[w] = ((cur != 0) ? to[l][i] : 0);
					q.push(w);
				}
				else w = to[l][i];
			}
		}
	}
	vector<ii> query(string &s){
		//cout << s << endl;
		fix(s);
		vector<ii> ret;
		int v = 0;
		for (int i=0;i <s.size(); i++){
			char c = s[i];
			v = to[v][c];
			if (end[v]) {
				ret.pb({end[v]-1, i+1-vs[end[v]-1].size()});
			}
		}
		return ret;
	}
}

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, m, w; cin >> n >> m >> w;
		vector<string> M(n);
		for(auto &i : M) cin >> i;
		
		aho::init();
		vs.resize(w);
		int ptr = 1;
		for(auto &i : vs) cin >> i, aho::insert(i, ptr++);
		int a, b;
		aho::build();
		vector<ii> show;	
		vector<pair<ii, char>> ans(w);
		// horizontal
		for(int i=0;i <n; i++){
			string at;
			for(int j=0; j<m; j++) at += M[i][j];
			show = aho::query(at);
			for(auto u : show) a=u.f, b=u.s, ans[a]={{i, b}, 'C'};
			reverse(at.begin(), at.end());
			show = aho::query(at);
			for (auto u : show) a=u.f, b=u.s, ans[a]={{i, m-1-b}, 'G'};	
		}
		// vertical
		for(int j=0;j <m; j++){
			string at;
			for(int i=0; i<n; i++) at += M[i][j];
			show = aho::query(at);
			for (auto u : show) a=u.f, b=u.s, ans[a]={{b, j}, 'E'};
			reverse(at.begin(), at.end());
			show = aho::query(at);
			for (auto u : show) a=u.f, b=u.s, ans[a]={{n-1-b, j}, 'A'};	
		}
		// diagonal pelas linhas
		for(int i=0;i <n; i++){
			string at;
			for(int j=0; j<m and i+j<n; j++) at += M[i+j][j];
			int lim = at.size()-1;
			show = aho::query(at);
			for (auto u : show) a=u.f, b=u.s, ans[a]={{b+i, b}, 'D'};
			reverse(at.begin(), at.end());
			show = aho::query(at);
			for (auto u : show) a=u.f, b=u.s, ans[a]={{(lim-b)+i, lim-b}, 'H'};	
		}
		// diagonal  pelas colunas
		for(int j=1;j <m; j++){
			string at;
			for(int i=0; i<n and i+j<m; i++) at += M[i][j+i];
			int lim = at.size()-1;
			show = aho::query(at);
			for (auto u : show) a=u.f, b=u.s, ans[a]={{b, b+j}, 'D'};
			reverse(at.begin(), at.end());
			show = aho::query(at);
			for (auto u : show) a=u.f, b=u.s, ans[a]={{lim-b, lim-b+j}, 'H'};	
		}
		// anti-diagonal pelas linhas
		for(int i=0;i<n; i++){
			string at;
			for(int j=0; j<m and i-j+1; j++) at += M[i-j][j];
			int lim = at.size()-1;
			show = aho::query(at);
			for (auto u : show) a=u.f, b=u.s, ans[a]={{i-b, b}, 'B'};
			reverse(at.begin(), at.end());
			show = aho::query(at);
			for (auto u : show) a=u.f, b=u.s, ans[a]={{i-(lim-b), lim-b}, 'F'};	
		}
		// anti-diagonal pelas colunas
		for(int j=1;j<m; j++){
			string at;
			for(int i=n-1; i+1 and j+n-1-i<m; i--) at += M[i][j+n-1-i];
			int lim = at.size()-1;
			show = aho::query(at);
			for (auto u : show) a=u.f, b=u.s, ans[a]={{n-1-b, j+b}, 'B'};
			reverse(at.begin(), at.end());
			show = aho::query(at);
			for (auto u : show) a=u.f, b=u.s, ans[a]={{n-1-(lim-b), j+lim-b}, 'F'};	
		}

		for (auto u : ans) cout << u.f.f << " " << u.f.s << " " << u.s << endl;
		if(t) cout << endl;
	}
	
	exit(0);
}
