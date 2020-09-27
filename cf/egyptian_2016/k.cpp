#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld eps = 1e-12;

ld P[25][25], C[25][25];
vector<int> v;
ld dp[25][25];
int dest =-1;
int endit;
int n;

ld solve(int at, int it){
	ld &ret = dp[at][it];
	if(ret>-3) return ret;
	if(dest!=-1 and it==endit-1) return ret = P[at][dest] * C[at][v[it]];
	if(it==endit-1) return ret = C[at][v[it]];

	ld p = 0.0;
	for(int i=0; i<n; i++) p += P[at][i] * solve(i, it+1);
	return ret = C[at][v[it]]*p;
}

int main(){ _
	freopen("trip.in", "r", stdin);
	int t; cin >> t;
	while(t--){
		for(int i=0;i <25; i++) for(int j=0; j<25; j++) dp[i][j] = -5;
		
		int m, k, q, z; 
		cin >> n >> m >> k >> q >> z;
		for(int i=0;i <n; i++) for(int j=0; j<n; j++) cin >> P[i][j];
		for(int i=0;i <n; i++) for(int j=0; j<m; j++) cin >> C[i][j];
		
		v.resize(k);
		for(auto &i : v) cin >> i;
	
		if(q==0){
			cout << setprecision(3) << fixed;
			if(z!=0 or C[0][v[0]] < eps) cout << 0.0 << endl;
			else cout << 1.0 << endl;
			continue;
		}

		dest = z, endit = q;
		ld p1 = solve(0, 0);
		
		for(int i=0;i <25; i++) for(int j=0; j<25; j++) dp[i][j] = -5;
		dest = -1, endit=k;
		ld p2 = solve(z, q);

		for(int i=0;i <25; i++) for(int j=0; j<25; j++) dp[i][j] = -5;
		ld p3 = solve(0, 0);

		cout << setprecision(3) << fixed;
		cout << p1*p2/p3 << endl;
	}	
	
	exit(0);
}
