#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MOD = 1e9+7;

int M[int(5e6)][11];
int p3[int(5e6)];
int v[10];
int n, m, ans=0;

int c(int x, int y){
	return M[v[y]][x];
}

void solve(int pos) {
	if (pos == m) {
		bool f = false;
		for (int x1 = 0; x1<n and !f; x1++)
			for (int x2 = x1+1; x2<n and !f; x2++)
				for (int y1 = 0; y1<m and !f; y1++)
					for (int y2 = y1+1; y2<m and !f; y2++) {
						f = c(x1, y1) == c(x1, y2) and c(x2, y1) == c(x2, y2);
						f |= c(x1, y1) == c(x2, y1) and c(x1, y2) == c(x2, y2);
					}
		ans += !f;
		return;
	}
	if (pos == 0) for (int i=0; i<p3[n]; i++) v[pos] = i, solve(pos+1);
	else for (int i=v[pos-1]+1; i<p3[n]; i++) v[pos] = i, solve(pos+1);
}

int main(){ _
	cin >> n >> m;
	if (n < m) swap(n, m);
	p3[0] = 1;
	for (int i=1; i<=n*m; i++) p3[i] = ll(p3[i-1])*3%MOD;
	
	for (int i=0; i<p3[n]; i++) {
		int at=i;
		int j = 0;
		while (at > 0) {
			M[i][j] = at%3;
			at/=3;
			j++;
		}
	}	
	solve(0);
	for (int i=m; i>=1; i--) ans *= i;
	cout << "Numero de proibidos " << ans << endl;
	//cout << p3[n*m] - ans << endl;
	
	exit(0);
}
