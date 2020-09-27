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

int M[505][505];
int v[505][505][4];
int main(){ _
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		for(int i=0;i <n; i++){
			for(int j=0; j<m; j++){
				cin >> M[i][j];
			}
		}
		v[0][0][0] = M[0][0];
		for(int i=1;i <n; i++) v[i][0][0] = max(v[i-1][0][0], M[i][0]);
		for(int i=1;i <m; i++) v[0][i][0] = max(v[0][i-1][0], M[0][i]);
		for(int i=1;i <n; i++)
			for(int j=1; j<m; j++) v[i][j][0] = max({v[i-1][j][0], v[i][j-1][0], M[i][j]});

		v[n-1][0][1] = M[n-1][0];
		for(int i=n-2;i >=0; i--) v[i][0][1] = max(v[i+1][0][1], M[i][0]);
		for(int i=1;i <m; i++) v[n-1][i][1] = max(v[n-1][i-1][1], M[n-1][i]);
		for(int i=n-2;i+1; i--)
			for(int j=1; j<m; j++) v[i][j][1] = max({v[i+1][j][1], v[i][j-1][1], M[i][j]});

		v[0][m-1][2] = M[0][m-1];
		for(int i=1;i <n; i++) v[i][m-1][2] = max(v[i-1][m-1][2], M[i][m-1]);
		for(int i=m-2;i+1; i--) v[0][i][2] = max(v[0][i+1][2], M[0][i]);
		for(int i=1;i <n; i++)
			for(int j=m-2; j+1; j--) v[i][j][2] = max({v[i-1][j][2], v[i][j+1][2], M[i][j]});

		v[n-1][m-1][3] = M[n-1][m-1];
		for(int i=n-2;i+1; i--) v[i][m-1][3] = max(v[i+1][m-1][3], M[i][m-1]);
		for(int i=m-2;i+1; i--) v[n-1][i][3] = max(v[n-1][i+1][3], M[n-1][i]);
		for(int i=n-2;i+1; i--)
			for(int j=m-2; j+1; j--) v[i][j][3] = max({v[i+1][j][3], v[i][j+1][3], M[i][j]});
	/*	
		cout << "zero" << endl;
		for(int i=0;i <n; i++){for(int j=0; j<m; j++) cout << v[i][j][0] << " "; cout << endl;}
		cout << "um" << endl;
		for(int i=0;i <n; i++){for(int j=0; j<m; j++) cout << v[i][j][1] << " "; cout << endl;}
		cout << "dois" << endl;
		for(int i=0;i <n; i++){for(int j=0; j<m; j++) cout << v[i][j][2] << " "; cout << endl;}
		cout << "tres" << endl;
		for(int i=0;i <n; i++){for(int j=0; j<m; j++) cout << v[i][j][3] << " "; cout << endl;}
*/		
		int ans = INF;
		for(int i=1; i<n-1; i++)
			for(int j=1; j<m-1; j++){
//				cout << "Indices " << i << " " << j << endl;
//				cout << v[i-1][j-1][0] <<" " <<v[i+1][j-1][1] << " " 
//					<< v[i-1][j+1][2] << " " << v[i+1][j+1][3] << endl; 
				int maxi = max({v[i-1][j-1][0], v[i+1][j-1][1], v[i-1][j+1][2], v[i+1][j+1][3]});
				int mini = min({v[i-1][j-1][0], v[i+1][j-1][1], v[i-1][j+1][2], v[i+1][j+1][3]});
				ans = min(ans, maxi-mini); 
			}
		cout << ans << endl;
	}
	
	
	
	exit(0);
}
