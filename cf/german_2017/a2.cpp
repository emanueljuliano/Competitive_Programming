#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 8e2+10;

ld memo[MAX][2];

vector<pair<int,ld>> g[MAX];

int main(){ _

	int n, m; cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		ld c; cin >> c;
		g[a].push_back({b,c});
	}

	ld ans = 0;

	int here = n%2;
	for(int i=0; i < n; i++) if(ans < 1.1) {
		for(int j=0; j<n; j++) memo[j][here] = 0;
		memo[i][here] = 1;

		for(int j = n-1; j >= 0; j--) if(ans < 1.1) {

			int looking = j%2, next = (j+1) % 2; 

			for(int k = i; k < n; k++) {
				ld now = 0;
				for(pair<int,ld>& u : g[k]) 
					now = max(now, u.s * memo[u.f][next]);

				memo[k][looking] = now;
			}

			ans = max(ans, memo[i][looking]);
		}
	}

	assert(ans <= 0.9 or ans >= 1.1);

	if(ans >= 1.1) cout << "inadmissible" << endl;
	else cout << "admissible" << endl;

	return 0;
}
