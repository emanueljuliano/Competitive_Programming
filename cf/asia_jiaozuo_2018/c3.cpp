#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int N = 2123450;

int x[N], y[N], xx[N], yy[N];
ll cnt[2][2];

int main () {
	int t; cin >> t;
	while (t--) {
		memset (cnt, 0, sizeof cnt);
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", x+i, y+i);
			xx[x[i]] = i;
			yy[y[i]] = i;
		}
		if (n == 1) {
			for (int i = 0; i < m; i++) {
				char c; scanf(" %c", &c);
				if (c == '!') cout << 0 << endl;
				else {
					int x; scanf("%d", &x);
					if (c == '?') printf("%d %d\n", 1, 1);
				}
			}
			continue;
		}
		deque <int> deq[2];
		for (int i = 1; i <= n; i++) {
			deq[1].pb(xx[i]);
			deq[0].pb(yy[i]);
		}
		set <int> s[2][2];
		s[0][0].insert(deq[0].front());
		s[0][1].insert(deq[0].back());
		if (s[0][0].count(deq[1].front())) {
			cnt[0][0]++;
		} else if (s[0][1].count(deq[1].front())) {
			cnt[1][0]++;
		}
		if (s[0][0].count(deq[1].back())) {
			cnt[0][1]++;
		} else if (s[0][1].count(deq[1].back())) {
			cnt[1][1]++;
		}
		s[1][0].insert(deq[1].front());
		s[1][1].insert(deq[1].back());
		

		deq[0].pop_front(); deq[0].pop_back();
		deq[1].pop_front(); deq[1].pop_back();
		int l = 1, r = n, u = 1, d = n;
		int tlr = 0, tud = 0;
		for (int i = 0; i < m; i++) {
			char c; scanf(" %c", &c);
			if (c == '!') {
				ll ans = 0;
				for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					ans += (cnt[i][j] * (cnt[i][j] - 1)) / 2;
				printf("%lld\n", ans);
			} else {
				int k; scanf("%d", &k);
				if (c == 'L') {
					if (l - k >= 1) {
						l -= k;
						r -= k;
					} else {
						int xd = l - 1;
						k -= xd;
						r -= xd;
						l = 1;
						while (k and r > 1) {
							r--;
							k--;
							if (r == 1) {
								//juntou tudo
								cnt[0][0] = s[1][0].size();
								cnt[0][1] = s[1][1].size();
								cnt[1][0] = cnt[1][1] = 0;
								
								while (!s[0][1].empty()) {
									int x = *(s[0][1].begin());
									s[0][1].erase(x);
									s[0][0].insert(x);
								}
							} else {
								int x = deq[0].front();
								s[0][0].insert(deq[0].front());
								deq[0].pop_front();
								if (s[1][0].count(x)) {
									cnt[0][0]++;
								} else if (s[1][1].count(x)) {
									cnt[0][1]++;
								}
							}
						}
					}
				} else if (c == 'R') {
					if (r + k <= n) {
						l += k;
						r += k;
					} else {
						int xd = n - r;
						l += xd;
						k -= xd;
						r = n;
						while (k and l < n) {
							l++;
							k--;
							if (l == n) {
								//juntou tudo
								cnt[0][0] = s[1][0].size();
								cnt[0][1] = s[1][1].size();
								cnt[1][0] = cnt[1][1] = 0;
								
								while (!s[0][1].empty()) {
									int x = *(s[0][1].begin());
									s[0][1].erase(x);
									s[0][0].insert(x);
								}
							} else {
								int x = deq[0].back();
								s[0][1].insert(deq[0].back());
								deq[0].pop_back();
								if (s[1][0].count(x)) {
									cnt[1][0]++;
								} else if (s[1][1].count(x)) {
									cnt[1][1]++;
								}
							}
						}
					}
				} else if (c == 'U') {
					if (u - k >= 1) {
						u -= k;
						d -= k;
					} else {
						int xd = u - 1;
						k -= xd;
						d -= xd;
						u = 1;
						while (k and d > 1) {
							d--;
							k--;
							if (d == 1) {
								//juntou tudo
								cnt[0][0] = s[0][0].size();
								cnt[1][0] = s[0][1].size();
								cnt[0][1] = cnt[1][1] = 0;
								while (!s[1][1].empty()) {
									int x = *(s[1][1].begin());
									s[1][1].erase(x);
									s[1][0].insert(x);
								}
							} else {
								int x = deq[1].front();
								s[1][0].insert(deq[1].front());
								deq[1].pop_front();
								if (s[0][0].count(x)) {
									cnt[0][0]++;
								} else if (s[0][1].count(x)) {
									cnt[1][0]++;
								}
							}
						}
					}
				} else if (c == 'D') {
					if (d + k <= n) {
						d += k;
						u += k;
					} else {
						int xd = n - d;
						k -= xd;
						u += xd;
						d = n;
						while (k and u < n) {
							u++;
							k--;
							if (u == n) {
								//juntou tudo
								cnt[0][0] = s[0][0].size();
								cnt[1][0] = s[0][1].size();
								cnt[0][1] = cnt[1][1] = 0;
								while (!s[1][1].empty()) {
									int x = *(s[1][1].begin());
									s[1][1].erase(x);
									s[1][0].insert(x);
								}
							} else {
								int x = deq[1].back();
								s[1][1].insert(deq[1].back());
								deq[1].pop_back();
								if (s[0][0].count(x)) {
									cnt[0][1]++;
								} else if (s[0][1].count(x)) {
									cnt[1][1]++;
								}
							}
						}
					}
				} else if (c == '?') {
					int px = x[k-1], py = y[k-1];
					swap(px, py);
					{
						int left = s[0][0].size();
						int right = s[0][1].size();
						int mid = n - left - right;
						if (px <= left) {
							px = l;
						} else if (px <= left + mid) {
							px = px - left + 1 + l - 1;
						} else {
							px = r;
						}
					}
					{
						int left = s[1][0].size();
						int right = s[1][1].size();
						int mid = n - left - right;
						if (py <= left) {
							py = u;
						} else if (py <= left + mid) {
							py = py - left + 1 + u -1;
						} else {
							py = d;
						}
					}
					swap(px, py);
					printf("%d %d\n", px, py);
				}

			}
		}

	}
	return 0;
}

