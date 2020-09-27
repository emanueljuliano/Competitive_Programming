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

const int MAX = 330;
int n, m;
int vx[4] = {1, -1, 0, 0};
int vy[4] = {0, 0, 1, -1};
bool val(int i, int j){
//	cout << i <<" "  << j << " " << n << " " << m << endl;
	return i>=0 and j>=0 and i<n and j<m;
	return false;
}

int main(){ _
	int t; cin >> t;
	int M[MAX][MAX];
	while(t--){
		cin >> n >> m;
		for(int i=0;i <n; i++){
			for(int j=0;j <m; j++){
				cin >> M[i][j];
			//	if(M[i][j]==0) M[i][j]++;
			}
		}
		bool show = true;
		for(int i=0;i <n; i++){
			for(int j=0; j<m; j++){
				int v = 0;
				for(int k=0; k<4; k++){
					int x = i+vx[k], y = j+vy[k];
					if(val(x, y)) v++;
				}
				//cout << i << " " << j << " " << v << " " << M[i][j] << endl;
				if(v<M[i][j]) show = false;
				else M[i][j] = v;
			}
		}
		if(!show) cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			for(int i=0;i <n; i++){
				for(int j=0; j<m; j++) cout << M[i][j] << " ";
				cout << endl;
			}
		}
	}
	
	
	
	exit(0);
}
