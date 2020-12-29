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

const int MAX = 1e3+10;
int dp[MAX][MAX];
vector<int> v;
vector<int> soma;

int solve(int l, int r){
	int &ret = dp[l][r];
	
	if(ret !=-1) return ret;
	if(l==r) return ret = v[l];
	
	int tot = soma[r+1]-soma[l]; 
	ret = max(tot-solve(l+1, r), tot-solve(l, r-1));
//	cout << "(l, r) = " << l << " " << r << " -> " << ret << endl;
	return ret;
}

int main(){ _
	int n;
	while(true){
		cin >> n; n*=2;
		if(!n) break;
		
		for(int i=0;i <=n; i++) for(int j=0; j<=n; j++)
			dp[i][j] = -1;

		v.resize(n);
		soma.clear();
		for(auto &u:v) cin >> u, u = (u+1)%2;
		soma.pb(0);
		for(auto u:v) soma.pb(soma.back()+u);

		cout << solve(0, n-1) << endl;
	}


	exit(0);
}
