#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e3+30;
char M[4*MAX][6*MAX];

int main(){ _
		
	int tc; cin >> tc;
	while (tc--) {
		int n, m; cin >> n >> m;
		cin.ignore();
		int R = 4*n+3, C = 6*m+3;

		for (int i=0; i<=R; i++) for (int j=0; j<=C; j++)
			M[i][j] = ' ';
		
		map<pair<int, int>, int> mp;
		int p = 0;
		
		// linhas 4*i + 2 colunas 12*j+4
		// linhas 4*i + 4 colunas 12*j+10

		int s = 0, t = 0;
		for (int i=0;i <R; i++){
			string S;
			getline(cin, S);
			for (int j=0; j<S.size(); j++) {
				M[i][j] = S[j];

				if (M[i][j] == 'S') s = p;
				if (M[i][j] == 'T') t = p;
				
				if(i%4==2 and j%12==4) {
					pair<int, int> pi = {i, j};
					mp[pi] = p++;
				}
				if(i!=0 and i%4==0 and j%12==10) {
					pair<int, int> pi = {i, j};
					mp[pi] = p++;
				}
			}
		}
		
		vector<int> dx = {0, 3, 3, 0, -3, -3};
		vector<int> dy = {-2, -1, 1, 2, 1, -1};

		auto val = [&](int i, int j) {
			return  i>=0 and j>=0 and i<R and j<C and M[i][j]==' ';
		};

		vector g(p, vector<int>());

		for (int i=0; i<R; i++) for (int j=0; j<C; j++) {
			pair<int, int> p1 = {i, j};
			if (mp.count(p1)) {
				int v = mp[p1];
				for (auto x : dx) for (auto y : dy) {
					int ii = i+y, jj = j+x;
					if (val(ii, jj)) {
						pair<int, int> p2 = {i+2*y, j+2*x};
						if(mp.count(p2)){
							int u = mp[p2];
							g[v].push_back(u);
							g[u].push_back(v);
						}
					}
				}
			}	
		}

		/*for (auto [a, b] : mp) {
			auto [i, j] = a;
			cout << "(" << i << ", " << j << ") " << M[i][j] << " " << b << endl;
		}

		for (int i=0; i<p; i++) {
			cout << i << ": ";
			for(auto u : g[i]) cout << u << " ";
			cout << endl;
		}*/

		vector<int> d(p, -1);
		queue<int> q;
		q.push(s); d[s] = 1;
		while (!q.empty()) {
			int v = q.front(); q.pop();
			cout << v << " " << g[v].size() << endl;
			for (auto u : g[v]) if (d[u]==-1) {
				d[u] = d[v]+1;
				q.push(u);
			}
		}

		cout << d[t] << endl;
	}
	
	
	exit(0);
}
