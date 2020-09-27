#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n, m;
vector<ll> v;
vector<vector<ii>> g(20);
ll pd[1<<18][18];
ll ent[20][20];

int main(){ _
	memset(pd, -1, sizeof(pd));
	memset(ent, 0, sizeof(ent));
	int k; cin >> n >> m >> k;
	v.resize(n);
	for(auto&i : v) cin >> i;
	for(int i=0; i<k; i++){
		int a, b, c; cin >> a >> b >> c; a--; b--;
		ent[a][b] = c;
	}
	ll ans = 0;
	for(int i=0; i<n; i++) pd[1<<i][i] = v[i];
	for(int mask=1; mask<1<<n; mask++){
		for(int i=0; i<n; i++) if((1<<i)&mask){
			if(__builtin_popcount(mask) == m) ans = max(ans, pd[mask][i]);
			for(int j=0; j<n; j++) if(!((1<<j)&mask)){
				int nmask = mask+(1<<j);
				pd[nmask][j] = max(pd[nmask][j], pd[mask][i] + v[j]+ent[j][i]);
				if(__builtin_popcount(nmask) == m) ans = max(ans, pd[nmask][j]);
			}
		}
	}
	cout << ans << endl;

	exit(0);
}
