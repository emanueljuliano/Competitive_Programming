#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 910;
int dist[MAX][MAX][2];
int from[MAX][MAX];

int main(){ _
	int n, m;
	while (cin >> n >> m) {
		vector<vector<int>> g(n);
		vector<pair<int, int>> eg(m);
		for (auto &[u, v] : eg) {
			cin >> u >> v; u--, v--;
			g[u].push_back(v);
		}	
		
		for (int i=0; i<n; i++) {
			for (int j = 0; j < n; j++) for (int k=0; k<2; k++)
				dist[i][j][k] = INF, from[i][j] = -1;

			queue<pair<int, int>> q;
			for (int j : g[i]) q.push({j, 1}), dist[i][j][1] = 1, from[i][j] = j;
			
			while (!q.empty()) {
				auto [j, first] = q.front(); q.pop();

				for (int k : g[j]) if (k != i) {
					if (first) {
						if (dist[i][k][1] > dist[i][j][1] + 1) { // first bfs
							q.push({k, 1});
							dist[i][k][1] = dist[i][j][1] + 1;
							from[i][k] = from[i][j];
						}
						else if (dist[i][k][0] > dist[i][j][1] + 1 and from[i][k] != from[i][j]) {
							// transition from the first bfs to second bfs
							q.push({k, 0});
							dist[i][k][0] = dist[i][j][1] + 1;
						}
					}
					else {
						if (dist[i][k][0] > dist[i][j][0] + 1) { // second bfs
							q.push({k, 0});
							dist[i][k][0] = dist[i][j][0] + 1;
						}
					}
				}
			}
		}

		for (auto [u, v] : eg) {
			if (dist[u][v][0] != INF) cout << dist[u][v][0] << " ";
			else cout << 0 << " ";
		}
		cout << endl;
	}
	
	exit(0);
}
