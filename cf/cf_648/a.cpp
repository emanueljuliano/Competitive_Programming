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

const int MAX = 55;

int M[MAX][MAX];

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		int nr=0, nc = 0;
		for(int i=0;i <n; i++){
			int at = 0;
			for(int j=0; j<m; j++){
				cin >> M[i][j];
				at += M[i][j];
			}
			if(at==0) nc++;
		}
		for(int j=0;j <m; j++){
			int at = 0;
			for(int i=0; i<n; i++){
				at += M[i][j];
			}
			if(at==0) nr++;
		}
		int ans = min(nc, nr);
		if(ans%2==0) cout << "Vivek" << endl;
		else cout << "Ashish" << endl;
	}
	
	
	
	exit(0);
}
