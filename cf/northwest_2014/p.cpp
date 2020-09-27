#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int tt; cin >> tt;
	while (tt--) {
		int n, m; cin >> n >> m;
		vector t(n, vector(m, int()));
		for (auto& i : t) for (auto& j : i) {
			char c; cin >> c;
			if (c == '#') j = 1;
			else j = 0;
		}
#if 0
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) cout << t[i][j] << " ";
			cout << endl;
		}
#endif
		bool trans = 0;

		vector<int> ans(4, INF);

		auto hor = [&]() {
			for (int k = 0; k < n-1; k++) {
				bool deu = 1;
				vector vis(n, vector(m, int(0)));
				for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
					int ni = k+1 + (k-i);
					if (ni >= 0 and ni < n) {
						if (!(t[i][j]^t[ni][j])) deu = 0;
						vis[i][j] = 1;
						vis[ni][j] = 1;
					}
				}
				for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
					if (!vis[i][j] and !t[i][j]) deu = 0;
				if (deu) {
					vector<int> at;
					if (trans) at = {1, k+1, m, k+1};
					else at = {k+1, 1, k+1, m};
					if (at < ans) ans = at;
				}
			}
		};

		auto transpose = [&]() {
			trans ^= 1;
			vector t2(m, vector(n, int()));
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
				t2[j][i] = t[i][j];
			t = t2;
			swap(n, m);
		};

		hor();
		transpose();
		hor();
		transpose();

		bool refl = 0;

		auto diag = [&]() {
			for (int k = -(m-1); k <= n-1; k++) {
				//cout << "testando k: " << k << endl;
				//cout << n << " " << m << endl;
				bool deu = 1;
				vector vis(n, vector(m, int(0)));
				for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
					int d = i-j - k;
					//cout << "d: " << d << endl;
					int ni = i - d;
					int nj = j + d;
					//cout << i << " " << j << " ; " << ni << " " << nj << endl;
					if (i == ni and j == nj) {
						if (!t[i][j]) deu = 0;
					} else if (ni >= 0 and ni < n and nj >= 0 and nj < m) {
						if (!(t[i][j]^t[ni][nj])) deu = 0;
						vis[i][j] = 1;
						vis[ni][nj] = 1;
					}
				}
				for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
					if (!vis[i][j] and !t[i][j]) deu = 0;
				if (deu) {
					pair<int, int> p1 = {max(0, k)+1, max(0, -k)+1};
					pair<int, int> p2 = {min(n-1, m-1+k)+1, min(m-1, m-1-k)+1};
					if (refl) {
						swap(p1, p2);
						p1.s = m+1-p1.s;
						p2.s = m+1-p2.s;
					}
					vector<int> at = {p1.f, p1.s, p2.f, p2.s};
					if (at < ans) ans = at;
				}
			}
		};

		auto reflete = [&]() {
			refl ^= 1;
			vector t2(n, vector(m, int()));
			for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
				t2[i][m-1-j] = t[i][j];
			t = t2;
		};

		diag();
		reflete();
		diag();
		reflete();

		assert(ans[0] < INF);

		for (int i : ans) cout << i << " ";
		cout << endl;
	}
	exit(0);
}
