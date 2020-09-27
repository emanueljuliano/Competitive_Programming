#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int M[10][10][2];
int a, b;
set<int> st;
bool over(){
	for(int i=1; i<=4; i++) for(int j=1; j<=2; j++){
		int x = 0, y = 0;
		for(int k=0; k<3; k++){
			if(M[i][j+k][0]==1)x++;
			if(M[i][j+k][1]==1)y++;
		}
		if(x==3 or y==3) return true;
	}
	for(int j=1; j<=4; j++) for(int i=1; i<=2; i++){
		int x = 0, y = 0;
		for(int k=0; k<3; k++){
			if(M[i+k][j][0]==1)x++;
			if(M[i+k][j][1]==1)y++;
		}
		if(x==3 or y==3) return true;
	}
	for(int i=2; i>=1; i--) for(int j=1; j<=2; j++){ 
		int x = 0, y = 0;
		for(int k=0; k<3; k++){
			if(M[i+k][j+k][0]==1)x++;
			if(M[i+k][j+k][1]==1)y++;		
		}
		if(x==3 or y==3) return true;	
	}
	for(int i=4; i>=3; i--) for(int j=1; j<=2; j++){ 
		int x = 0, y = 0;
		for(int k=0; k<3; k++){
			if(M[i-k][j+k][0]==1)x++;
			if(M[i-k][j+k][1]==1)y++;		
		}
		if(x==3 or y==3) return true;	
	}
	return false;
}

int ans = 0;
int p3[20];
void solve(int x, int y, bool p){
	if(M[a][b][1]){
		if(over()){
			int val = 0;
			vector<int> w;
			for(int i=4; i>=1; i--) for(int j=1; j<=4; j++){
				int m1 = M[i][j][0], m2 = M[i][j][1];
				int v = (m1|m2) + m2, p = p3[(i-1)*4+(j-1)];
				val+=v*p;
				w.pb(v*p);
			}
			st.insert(val);
		}
		return;
	}
	if(x==a and y==b and p==0) return;
	if(over()) return;

	for(int j=1;j <=4; j++) for(int i=1; i<=4; i++){
		if(M[i][j][0]==0 and M[i][j][1]==0){
			M[i][j][!p] = 1;
			solve(i, j, !p);
			M[i][j][!p] = 0;
			break;
		}
	} 
	return;
}
int main(){ _
	memset(M, 0, sizeof(M));
	p3[0] = 1;
	for(int i=1;i <17; i++) p3[i] = 3*p3[i-1];
	
	int x; cin >> x;
	cin >> a >> b;
	
	M[1][x][0] = 1;
	solve(1, x, 0);
	cout << st.size() << endl;
	
	exit(0);
}
