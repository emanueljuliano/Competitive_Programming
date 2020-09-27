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

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

struct kuhn {
	int n, m;
	vector<vector<int>> g;
	vector<int> vis, ma, mb;
	kuhn(int n_, int m_) : n(n_), m(m_), g(n),
		vis(n+m), ma(n, -1), mb(m, -1) {}
	
	void add(int a, int b) {g[a].pb(b);}
	
	bool dfs(int i){
		vis[i] = 1;
		for(int j : g[i]) if(!vis[n+j]){
			vis[n+j] = 1;
			if(mb[j]==-1 or dfs(mb[j])){
				ma[i] = j, mb[j] = i;
				return true;
			}
		}
		return false;
	}
	int matching(){
		int ret = 0, aum = 1;
		for(auto&i : g) shuffle(i.begin(), i.end(), rng);
		while(aum){
			for(int j=0; j<m; j++) vis[n+j] = 0;
			aum = 0;
			for(int i=0; i<n; i++)
				if(ma[i]==-1 and dfs(i)) ret++, aum=-1;
		}
		return ret;
	}
};

int n;
int vx[4] = {1, -1, 0, 0}, vy[4] = {0, 0, 1, -1};
int f(int x, int y){ return x*n+y;}
bool val(int x, int y){return x>=0 and x<n and y>=0 and y<n;}

int main(){ _
	int m; cin >> n >> m;
	kuhn K(n*n,n*n);
	vector v(n, vector<int> (n));
	for(int i=0; i<m; i++){
		int x, y; cin >> x >> y; x--, y--;
		v[x][y] = -1;
	}
	for(int i=0;i <n; i++) for(int j=0; j<n; j++) if(i%2==j%2 and v[i][j]!=-1)
		for(int k=0; k<4; k++){
			int x = i+vx[k], y = j+vy[k];
			if(val(x, y) and v[x][y]!=-1){ 
				K.add(f(i, j), f(x, y));
			//	cout << "Pts: (" << i << ", " << j << ") (" << x << ", " << y << ") : ";
			//	cout << f(i, j) << " " << f(x, y) << endl;
			}
		}
	
	int ans = K.matching();
	if(2*ans != n*n-m){
		cout << "No" << endl; exit(0);
	}
	vector<ii> vh, vv;
	for(int i=0;i <n*n; i++) if(K.ma[i]!=-1){
		int x = i/n, y = i%n;
		int xx = K.ma[i]/n, yy = K.ma[i]%n;
		if(y==yy) vh.pb({min(x, xx)+1, y+1});
		else vv.pb({x+1, min(y, yy)+1});
	}
	cout << "Yes" << endl;
	cout << vh.size() << endl;
	for(auto p : vh) cout << p.f << " " << p.s << endl;
	cout << vv.size() << endl;
	for(auto p : vv) cout << p.f << " " << p.s << endl;
	
	exit(0);
}
