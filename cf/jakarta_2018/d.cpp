#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const int MAX = 550;
char M[MAX][MAX];

int main(){ _
	int n, m; cin >> n >> m;
	
	for(int i=0;i <n; i++) for(int j=0; j<m; j++) cin >> M[i][j];

	if(min(n, m)>2){
		bool has_bord = false;
		for(int i=1;i <n-1; i++) if(M[i][0]=='#' or M[i][m-1]=='#') has_bord = true;
		for(int j=1;j <m-1; j++) if(M[0][j]=='#' or M[n-1][j]=='#') has_bord = true;
		int ans = !has_bord;
		
		for(int i=1; i<n-1; i++) for(int j=1; j<m-1; j++) if(M[i][j]!='#') ans++;
		cout << ans << endl;
	}
	else if(m==1){
		int ans = 0;
		for(int i=1;i <n-1; i++) if(M[i][0]!='#') ans++;
		cout << ans << endl;
	}
	else if(n==1){
		int ans = 0;
		for(int j=1;j <m-1; j++) if(M[0][j]!='#') ans++;
		cout << ans << endl;
	}
	else if(m==2){
		int ans = 0;
		for(int i=1;i <n-1; i++) if(M[i][0]!='#' and M[i][1]!='#') ans++;
		cout << ans << endl;		
	}
	else if(n==2){
		int ans = 0;
		for(int j=1;j <m-1; j++) if(M[0][j]!='#' and M[1][j]!='#') ans++;
		cout << ans << endl;
	}

	
	
	exit(0);
}
