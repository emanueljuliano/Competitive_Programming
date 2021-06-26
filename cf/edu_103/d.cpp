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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 3e5+10;
int dp[MAX][3][3]; // v, t, dir

int n;
string s;
int solve(int v, int t, int dir){
	if(v<0 or v>n) return 0;
	int &ret = dp[v][t][dir];
	if(ret!=-1) return ret;
	ret = 0;
	if(dir==0){
		if(v!=0 and (s[v-1]=='L')^t){
			ret = 1+solve(v-1, !t, dir);
		}
	}
	else{
		if(v!=n and (s[v]=='R')^t){
			ret = 1+solve(v+1, !t, dir);
		}	
	}
	//cout << v << " " << t << " " << dir << " " << ret << endl;
	return ret;
}

int main(){ _
	int t; cin >> t;
	while(t--){
		cin >> n;
		cin >> s;
		for(int i=0;i <=n; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++)
			dp[i][j][k] = -1;
		for(int i=0;i <n+1; i++) solve(i, 0, 0), solve(i, 0, 1);

		for(int i=0;i <n+1; i++) cout << dp[i][0][0]+dp[i][0][1]+1 << " ";
		cout << endl;
	}
	
	
	
	
	exit(0);
}
