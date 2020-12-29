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
const int MAX = 1e4+10;
int dp[MAX][15];
vector<int> v;
int n;
bool solve(int p, int dif){
	if(dif<0 or dif>10) return 0;
	if(p==n) return 1;
	int &ret = dp[p][dif];
	if(ret != -1) return ret;

	ret = solve(p+1, dif-v[p]);
	ret |= solve(p+1, dif+v[p]);
	return ret;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> n;
		v.resize(n);
		for(auto &i: v) cin >> i;
		for(int i=0;i <=n; i++) for(int j=0; j<=10; j++)
			dp[i][j] = -1;
		if(solve(0, 5)) cout << "Feliz Natal!" << endl;
		else cout << "Ho Ho Ho!" << endl;
	
	}
	exit(0);
}
