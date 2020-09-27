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


int main(){ _
	int MAX = 550;
	int M[MAX][MAX];	
	int n; cin >> n;
	if(n<=2) return cout << -1 << endl, 0;
	int at = 1;
	for(int i=0; i<n; i++){
		if(i==n-1) i++;
		if(i%2==0){
			for(int j=0; j<n; j++){
				M[i][j] = at;
				at++;
			}
		}
		else{
			for(int j=n-1; j>=0; j--){
				M[i][j] = at;
				at++;
			}
		}
	}
	int keep = 0;
	if(n%2==0)keep = M[0][n-2], M[0][n-2] = at;
	else keep = M[0][1], M[0][1] = at;

	for(int i=0;i <n; i++){
		if(i==n-1) i++;
		for(int j=0;j <n; j++){
			if(M[i][j]>keep) cout << M[i][j]-1 << " ";
			else cout << M[i][j] << " ";
		}
		cout << endl;
	}
	exit(0);
}
