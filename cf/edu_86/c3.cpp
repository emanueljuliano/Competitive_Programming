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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10;

vector<int> w[MAX];
int v[MAX], c[MAX], n;

bool vai(int t) {
	for (int i = 0; i < t; i++) w[i].clear();
	int at = 0;
	for (int i = 0; i < n; i++) {
		w[at].pb(v[i]);
		at = (at+1)%t;
	}
	for (int i = 0; i < t; i++) for (int j = 0; j < w[i].size(); j++)
		if (c[w[i][j]] < w[i].size()-j) return 0;
	return 1;
}

int main() { _
	int k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i]--;
	}
	sort(v, v+n);
	for (int i = 0; i < k; i++) cin >> c[i];
	int l = 1, r = n;
	while (l < r) {
		int m = (l+r)/2;
		if (vai(m)) r = m;
		else l = m+1;
	}
	vai(l);
	cout << l << endl;
	for (int i = 0; i < l; i++) {
		cout << w[i].size() << " ";
		for (int j : w[i]) cout << j+1 << " ";
		cout << endl;
	}
	exit(0);
}

