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
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
int n;

int M[1510][1510];
int N[1510][1510];

int main(){ _
	cin >> n;
	vector<int> v;
	for(int i=0;i <n; i++){
		int a; cin >> a; v.pb(a);
	}
	M[0][0] = 0;
	N[0][0] = 0;
	for(int j=1;j <n; j++){
		int at = 0, nt=0;
		for(int i=j; i>=0; i--){
			if(i==j) {M[i][j] = 0, N[i][j]=0; continue;}
			else if(v[i]>v[j]) at++;
			M[i][j] = M[i][j-1]+at;
			nt++;
			N[i][j] = N[i][j-1]+nt;
		}
	}
	
	int ans = M[0][n-1]%2;
	int m; cin >> m;
	for(int i=0;i <m; i++){
		int a, b; cin >> a >> b;a--; b--;
	//	cout << N[a][b] << " " << M[a][b] << endl;

		if((N[a][b]-M[a][b])%2 != M[a][b]%2) ans ^=1;
		if(ans) cout << "odd" << endl;
		else cout << "even" << endl;
	}


	exit(0);
}
