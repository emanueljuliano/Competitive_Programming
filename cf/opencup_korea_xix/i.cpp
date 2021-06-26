#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 5e3+10;

int dp[MAX];

int solve(int n){
	if(dp[n] != -1) return dp[n];
	if(n<=1) return dp[n] = 0;
	vector<int> g(n+1);
	for(int i=0;i <=n-2; i++){
		int a = solve(i), b = solve(n-i-2);
		a ^= b;
		if(a<n) g[a]=1;
	}
	
	for(int i=0;i <=n; i++) if(!g[i]) return dp[n] = i;
}

int main(){ _
	memset(dp, -1, sizeof dp);
	
	solve(5);

	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		if(solve(n)) cout << "First" << endl;
		else cout << "Second" << endl;
	}
	
	exit(0);
}
