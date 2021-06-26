#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 1e3+10;

int n, m;
ld d[MAX], o[MAX], def[MAX];
vector<pair<int, int>> ar;
vector<ld> w;
ld eps = 1e-8;

bool bellman_ford(double t) {
	bool ret = false;

	for (int i=0; i<n; i++) d[i] = o[i];
	for (int i=0; i<m; i++) w[i] += t;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<m; j++) {
			if (d[ar[j].second] > eps + d[ar[j].first] + w[j]) {
				if (i==n or def[ar[j].second]) ret = true;
				d[ar[j].second] = d[ar[j].first] + w[j];
			}
		}
	}
	for (int i=0; i<m; i++) w[i] -= t;
	return ret;
}

int main(){ _
	while (cin >> n >> m) {
		for (int i=0; i<n; i++) {
			string s; cin >> s;
			if(s == "?") d[i] = 1e9, def[i] = 0;
			else d[i] = stoi(s), def[i] = 1;
			o[i] = d[i];
		}
		ar.clear(), w.clear();
		for (int i=0; i<m; i++) {
			int a, b, c; cin >> a >> b >> c; a--, b--;
			ar.push_back({b, a});
			w.push_back(-c);
		}

		double l = 0, r = 1e8;
		while (abs(l-r) > eps) {
			double mi = (l+r)/2;
			if (bellman_ford(mi)) l = mi;
			else r = mi;
		}
		bellman_ford((l+r)/2);
		cout << setprecision(8) << fixed;
		cout << (l+r)/2 << endl;
		for (int i=0; i<n; i++) cout << d[i] << " ";
		cout << endl;
	}
	
	
	
	exit(0);
}
