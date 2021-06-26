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
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<string> M(n);
		for(auto &v : M) cin >> v;
		
		vector vis(n, vector<int>(10));
		vector<vector<ii>> pts(10);
		
		for(int i=0;i <n; i++) for(int j=0; j<n; j++){
			int dig = M[i][j]-'0';
			int &vi = vis[i][dig];
			if(!vi) pts[dig].pb({i, j}), vi++;
			else if(vi==1) pts[dig].pb({i, j}), vi++;
			else pts[dig].pop_back(), pts[dig].pb({i, j});
		}

		for(int dig=0;dig <10; dig++){
			int at = 0;
			for(int i=0;i <pts[dig].size(); i++) for(int j=i+1; j<(int)pts[dig].size(); j++){
				at = max(at, abs(pts[dig][i].f-pts[dig][j].f)*
				max({pts[dig][i].s, pts[dig][j].s, n-1-pts[dig][i].s, n-1-pts[dig][j].s}));
				at = max(at, abs(pts[dig][i].s-pts[dig][j].s)*
				max({pts[dig][i].f, pts[dig][j].f, n-1-pts[dig][i].f, n-1-pts[dig][j].f}));
			}
			cout << at << " ";
		}
		cout << endl;
		

	}
	
	
	
	exit(0);
}
