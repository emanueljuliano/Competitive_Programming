#include <bits/stdc++.h>

using namespace std;

//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
//#pragma GCC optimize("O1") 

#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1010;
bool M[MAX][MAX];
int dp[MAX][MAX], R[MAX][MAX], C[MAX][MAX];

int n, m;
bool val(int i, int j){
	if(i<=n and j<=m) return true;
	return false;
}

int read_int() {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (1) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true;
	else result = ch-'0';
	while (1) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus) return -result;
	else return result;
}

void solve(int i, int j, int l, int at){
//	cout << i << " " << j << " " << l << " " << at << endl;
	if(dp[i][j] != -1) return;

	while(true){
		if(!val(i+l+1, j+l+1)) break;
		int soma = C[i+l+1][j+l+1] - C[i-1][j+l+1];
		soma += R[i+l+1][j+l+1] - R[i+l+1][j-1];
		soma -= M[i+l+1][j+l+1];
		if(soma+at >1) break;

		l++;
		at += soma;
	}
	dp[i][j] = l;

	if(dp[i][j+1]==-1 and val(i, j+1)){
		int perde = C[i+l][j] - C[i-1][j];
		perde += R[i+l][j+l] - R[i+l][j-1];
		perde -= M[i+l][j];
	//	if(i==1 and j==15){
		//	cout << "C " << C[i+l][j] << " " << C[i-1][j] << endl;
		//	cout << "R " << R[i+l][j+l] << " " << R[i+l][j-1] << endl;
		//	cout << perde << " " << l << endl;
	//	}
		if(l==0) perde -= M[i][j+1];
		solve(i, j+1, max(l-1, 0), at-perde);
	}
	if(dp[i+1][j]==-1 and val(i+1, j)){
		int perde = C[i+l][j+l] - C[i-1][j+l];
		perde += R[i][j+l] - R[i][j-1];
		perde -= M[i][j+l];
		if(l==0) perde -= M[i+1][j];
		solve(i+1, j, max(l-1, 0), at-perde);
	}
	return;
}

int main(){ //_
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i=1;i <=n; i++) for(int j=1; j<=m; j++) dp[i][j]=-1, M[i][j] = read_int();
		for(int i=1;i <=n; i++){
			R[i][1] = M[i][1];
			for(int j=2; j<=m; j++) R[i][j] = R[i][j-1]+M[i][j];	
		}
		for(int j=1;j <=m; j++){
			C[1][j] = M[1][j];
			for(int i=2; i<=n; i++) C[i][j] = C[i-1][j]+M[i][j];	
		}
		solve(1, 1, 0, M[1][1]);
	//			for(int i=0;i <=n; i++){
	//				for(int j=0; j<=m; j++) cout << R[i][j] << " ";
	//				cout << endl;
	//			}

		int ans = 0;
		for(int i=1;i <=n; i++) for(int j=1; j<=m; j++) ans = max(ans, dp[i][j]);
		printf("%d\n", ans+1);
	}

	exit(0);
}
