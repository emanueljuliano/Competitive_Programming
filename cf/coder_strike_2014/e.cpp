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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n, m; cin >> n >> m;
	vector M(2, vector(n, char()));
	vector comp(2, vector(n, int()));
	vector vis(2, vector(n, int()));
	for(int i=0;i <2; i++) for(int j=0; j<n; j++) cin >> M[i][j];

	vector<int> up, down;
	vector<ii> alter;

	auto val = [&](ii p){
		if(p.s>=n) return false;
		return !vis[p.f][p.s] and M[p.f][p.s]!='X';
	};
	function<void(ii)> dfs = [&](ii v){
		vis[v.f][v.s] = 1;
		ii w = v; w.f = !w.f;
		ii w1 = v; w1.s++; 
		if(val(w)) comp[w.f][w.s] = comp[v.f][v.s], dfs(w);
		if(val(w1)) comp[w1.f][w1.s] = comp[v.f][v.s], dfs(w1);
	};
	int cmp = 1;
	for(int i=0;i <n; i++){
		if(val({0, i}) and !comp[0][i]) comp[0][i]=cmp++, dfs({0, i});
		if(val({1, i}) and !comp[1][i]) comp[1][i]=cmp++, dfs({1, i});
	}

	ii prev = {-1, 0};
	for(int i=0;i <n; i++){
		if(M[0][i]=='X'){
			up.pb(i);
			if(prev.f==-1 or prev.s!=0) alter.push_back({i, 0}), prev={i, 0};
			else alter.pop_back(), alter.push_back({i, 0}), prev={i, 0};
		}
		if(M[1][i]=='X'){
			down.pb(i);
			if(prev.f==-1 or prev.s!=1) alter.push_back({i, 1}), prev={i, 1};
			else alter.pop_back(), alter.push_back({i, 1}), prev={i, 1};
		}
	}

	auto dist = [&](int a, int b){
		if(a/n != b/n) return (b%n-a%n+1);
		int la, lb;
		if(a/n==0){
			la = lower_bound(up.begin(), up.end(), a%n) - up.begin();
			lb = lower_bound(up.begin(), up.end(), b%n) - up.begin();
			if(la==lb) return b%n-a%n;
			else return b%n - a%n + 2;
		}
		else{
			la = lower_bound(down.begin(), down.end(), a%n) - down.begin();
			lb = lower_bound(down.begin(), down.end(), b%n) - down.begin();
			if(la==lb) return b%n-a%n;
			else return b%n - a%n + 2;	
		}
	};

	while(m--){
		int a, b; cin >> a >> b; a--, b--;
		if(a%n>b%n) swap(a, b);
		if(comp[a/n][a%n] != comp[b/n][b%n]) {cout << -1 << endl; continue;}	
		
		ii pa = {a%n, a/n}, pb = {b%n, b/n};
		int  la = lower_bound(alter.begin(), alter.end(), pa) - alter.begin();
		int lb = lower_bound(alter.begin(), alter.end(), pb) - alter.begin();
		if(la==lb){
			int ans = dist(a, b);
			cout << ans << endl;
		}
		else{
			ii va = alter[la];
			int ans = 0;
			ans += dist(a, va.f+n*(!va.s));
		//	cout << ans << " a va " << endl;
			ii vb = alter[lb-1];
			ans += dist(vb.f+n*(!vb.s), b);
		//	cout << ans << " ans + b vb " << endl;
			ans += vb.f-va.f + (lb-1) - la;
			cout << ans << endl;
		}
	}

	
	
	exit(0);
}
