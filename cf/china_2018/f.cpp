#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 202;
int d[MAX][MAX][MAX], W[MAX];
vector<int> limit;
int D[MAX][MAX];
int n;

int main(){ _
	int t; cin >> t;
	int cs = 0;
	while(t--){ cs++;
		cout << "Case #" << cs << ": " << endl;;
		
		int q; cin >> n >> q;
		limit.resize(n);
		vector<pair<int, int>> ww;
		ww.push_back({-1, -1});
		for(int i=0;i <n; i++) cin >> W[i], ww.push_back({W[i], i});
		for(int i=0;i <n; i++) for(int j=0; j<n; j++) cin >> D[i][j], d[0][i][j]=D[i][j];

		sort(ww.begin(), ww.end());
		for(int it=1; it<=n; it++) {
			int k = ww[it].second;
			for(int i=0;i <n; i++)
			for(int j=0; j<n; j++)
				d[it][i][j] = min(d[it-1][i][j], d[it-1][i][k]+d[it-1][k][j]);
		}
		while(q--){
			int a, b, c; cin >> a >> b >> c; a--, b--;
			pair<int, int> p = {c, INF};
			int up = upper_bound(ww.begin(), ww.end(), p) - ww.begin();
			up--;
			int ans = d[up][a][b];
			cout << ans << endl;
		}
	}
	
	
	
	exit(0);
}
