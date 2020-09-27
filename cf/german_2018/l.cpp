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

const int MAX = 110;
int M[MAX][MAX], ans[MAX][MAX];
int n, m;

int vx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
int vy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

bool val(int x, int y){
	return (x>=0 and y>=0 and x<n+2 and y<m+2);
}

int main(){ _
	cin >> n >> m;
	memset(ans, 0, sizeof(ans));
	for(int i=0;i <n+2; i++){
		for(int j=0; j<m+2; j++){
			cin >> M[i][j];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int at = 0;
			for(int k=0; k<9; k++){
				int x = i+vx[k], y = j+vy[k];
				if(val(x, y)) at += ans[x][y];
			}
			ans[i+1][j+1] = M[i][j] - at;
		}
	}

	bool show = true;
	for(int i=0; i<n+2; i++){ for(int j=0; j<m+2; j++){
			int at = 0;
			for(int k=0; k<9; k++){
				int x = i+vx[k], y = j+vy[k];
				if(val(x, y)){
					at += ans[x][y];
					if(ans[x][y] != 0 and ans[x][y] != 1) show = false;
				}
			}
			if(at != M[i][j]) show = false;
	}}

	if(!show) cout << "impossible" << endl;
	else{
		for(int i=1; i<=n; i++){
			for(int j=1; j<=m; j++){
				if(!ans[i][j]) cout << ".";
				else cout << "X";
			}
			cout << endl;
		}
	}
	
	
	exit(0);
}
