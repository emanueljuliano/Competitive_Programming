#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 810;

int n, m;
ld d[MAX];
vector<pair<int, int> > ar; // vetor de arestas
vector<ld> w;              // peso das arestas

bool bellman_ford(int a) {
	for (int i = 0; i < n; i++) d[i] = INF;
	d[a] = 0;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j < m; j++) {
			if (d[ar[j].second] > d[ar[j].first] + w[j]) {
				if (i == n) return 1;

				d[ar[j].second] = d[ar[j].first] + w[j];
			}
		}

	return 0;
}

int main(){ _
	cin >> n >> m;
	for(int i=0;i <m; i++){
		int a, b; ld c; cin >> a >> b >> c;
		a--, b--;
		ar.pb({a, b});
		w.pb(-log(c));
	}

	bool ans = bellman_ford(0);

	if(ans) cout << "inadmissible" << endl;
	else cout << "admissible" << endl;

	exit(0);
}
