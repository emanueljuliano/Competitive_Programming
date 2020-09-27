#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int M[7][7][9];
ll viz[7][7];
int vale[7][7];
int vx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int vy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int main(){ _

	for(int i=5; i<=5; i++) for(int j=i; j<=6; j++){
		cout << i << " " << j << endl;
		for(int ii=0; ii<i; ii++) for(int jj=0; jj<j; jj++){
			ll at = 0; int val = 0;
			for(int k=0; k<8; k++){
				int x = ii+vx[k], y = jj+vy[k];
				if(x>=0 and y>=0 and x<i and y<j){
					val++;
					at |= 1LL<<(x*j + y);
				}
			}
			viz[ii][jj] = at;
			vale[ii][jj] = val;
		}

		for(ll msk = 0; msk<(1LL<<(ll)i*j); msk++){
			int mm = 0, minas=__builtin_popcountll(msk);
			
			for(int ii=0; ii<i; ii++) for(int jj=0; jj<j; jj++){
				int cnt = __builtin_popcountll(msk&viz[ii][jj]);
				int val = vale[ii][jj];
				if(msk & (1LL<<(ii*j + jj))){
					if(cnt==val) {mm = 100; break;}
				}
				else mm = max(mm, cnt);
			}
			
			for(int m=1; m<=8; m++) if(mm<=m) M[i][j][m] = max(minas, M[i][j][m]);
		}
		for(int m=1; m<=8; m++) M[j][i][m] = M[i][j][m];
		for(int m=1;m <=8; m++) cout << i << " " << j << " " << m << "  " << M[i][j][m] << endl;
	}
	exit(0);
	for(int m=1; m<=8; m++){
		vector<int> v(36);
		for(int i=2;i <=6; i++) for(int j=2; j<=6; j++) v[(i-1)*6+(j-1)]=M[i][j][m];
		cout << "v"<<m<<"[36] = {";
		for(auto x : v) cout << x << ", ";
		cout << "};" << endl;
	}	

	exit(0);
}
