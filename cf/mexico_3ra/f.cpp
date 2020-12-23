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
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, m;
int vis[31][31];

void mark(int x1, int y1, int x2, int y2, int c){
	for(int i=x1; i<=x2; i++) for(int j=y1; j<=y2; j++) vis[i][j] = c;
}

int sum(int x1, int y1, int x2, int y2){
	int ret = 0;
	for(int i=x1; i<=x2; i++) for(int j=y1; j<=y2; j++) ret += vis[i][j];
	return ret;
}

bool val(int i, int j){
	bool vi = (i<0 or i>=n), vj = (j<0 or j>=m);
	if(vi or vj) return true;
	return vis[i][j];
}

bool border(int i, int j, int x){
	if(val(i-1, j) and val(i, j-1)) return true;
	if(val(i-1, j) and val(i, j+x)) return true;
	if(val(i+x, j) and val(i, j-1)) return true;
	if(val(i+x, j) and val(i, j+x)) return true;
	return false;
}

bool can(int x){
	if(!x){
/*		for(int i=0;i <n; i++){
			for(int j=0; j<m; j++) cout << vis[i][j];
			cout << endl;
		}
*/		return true;	
	}
	for(int i=0;i+x-1 <n; i++) for(int j=0; j+x-1<m; j++)
		if(!vis[i][j] and border(i, j, x) and sum(i, j, i+x-1, j+x-1)==0){
			mark(i, j, i+x-1, j+x-1, 1);
			if(can(x-1)) return true;
			mark(i, j, i+x-1, j+x-1, 0);
		}
	return false;
}

int main(){ _
	cin >> n >> m;
	int ans = 1;
	for(int i=1; i<=30; i++){
		mark(0, 0, n-1, m-1, 0);
		if(can(i)) ans = i;
		else break;
	}

	cout << ans << endl;

	
	exit(0);
}
