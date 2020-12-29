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

int dp[111][111][111];
int M[111][3];
int n;
bool solve(int a, int b, int c, int x){
	if(x%3 or a>n or b>n or c>n) return 0;
	if(a==n and b==n and c==n) return 1;

	int &ret = dp[a][b][c];
	if(ret != -1) return ret;
	
	ret = false;
	for(int i=0;i <2; i++) for(int j=0; j<2; j++) for(int k=0; k<2; k++){
		if(!i and !j and !k) continue;
		int s = 0;
		int na=a, nb=b, nc=c;
		if(i) s += M[a][0], na++;
		if(j) s += M[b][1], nb++;
		if(k) s += M[c][2], nc++;

		ret |= solve(na, nb, nc, s);
	}
	return ret;
}

int main(){ _
	while(true){
		cin >> n;
		if(!n) break;

		for(int i=0;i <n; i++) for(int j=0; j<3; j++)
			cin >> M[i][j];

		for(int i=0;i <=n; i++) for(int j=0; j<=n; j++) for(int k=0; k<=n; k++)
			dp[i][j][k] = -1;

		cout << solve(0, 0, 0, 0) << endl;
		
	}
	exit(0);
}
