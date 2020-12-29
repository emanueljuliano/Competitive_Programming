#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pb push_back
#define f first
#define s second

typedef pair<int, int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int n, k, d;
double dp[(int)1e3+10][(int)1e2+10];
vector<ii> v;

double solve(int p, int m){
	if(p==n) return 0.0;

	double &ret = dp[p][m];
	if(ret > -1.0) return ret;
	
	ret = (double)v[p].f/d + solve(p+1, m);
	if(m>0) ret = min(ret, v[p].f/double(d+v[p].s) + solve(p+1, m-1));
	return ret;
}

int main(){ _
	while(cin >> n >> k>> d){
		v.resize(n);
		for(auto &i:v) cin >> i.f >> i.s;
		for(int i=0;i <=n; i++) for(int j=0; j<=k; j++)
			dp[i][j] = -5;

		cout << setprecision(4) << fixed;
		cout << solve(0, k) << endl;
	}


	exit(0);
}
