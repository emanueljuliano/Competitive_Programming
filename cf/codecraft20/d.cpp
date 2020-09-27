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
const int MAX = 1e3+10;
ii M[MAX][MAX];
char ans[MAX][MAX];
bool show = true;
int n;
ii ij;

bool val(int i, int j, char x){
	if(i<0 or i>=n or j<0 or j>=n) return false;
	if(ans[i][j]!='Z') return false;
	if(x=='X'){
		if(M[i][j] != ij) return false;
	}
	return true;
}

void bfs(int a, int b){
	ij = {a, b};
	queue<ii> q;
	q.push({a, b});
	char flag = 'X';
	if(ans[a][b] != 'X'){
		flag = 'Y';
		if(val(a+1, b, flag)) ans[a][b] = 'D';
		if(val(a-1, b, flag)) ans[a][b] = 'U';
		if(val(a, b+1, flag)) ans[a][b] = 'R';
		if(val(a, b-1, flag)) ans[a][b] = 'L';
		if(ans[a][b]=='Z') show = false;
	}
	while(!q.empty()){
		auto aux = q.front(); q.pop();
		int x=aux.f, y=aux.s;
		if(val(x+1, y, flag)) ans[x+1][y] = 'U', q.push({x+1, y});
		if(val(x-1, y, flag)) ans[x-1][y] = 'D', q.push({x-1, y});
		if(val(x, y+1, flag)) ans[x][y+1] = 'L', q.push({x, y+1});
		if(val(x, y-1, flag)) ans[x][y-1] = 'R', q.push({x, y-1});
	}
}

int main(){ _
	cin >> n;
	for(int i=0;i <n; i++){
		for(int j=0;j <n; j++){
			int a, b; cin >> a >> b;
			a--; b--;
			M[i][j] = {a, b};
			if(a==i and b==j)
				ans[i][j] = 'X';
			else ans[i][j] = 'Z';
		}
	}
	for(int i=0; i<n; i++) for(int j=0;j <n; j++){
		if(ans[i][j]=='X') bfs(i, j);
	}	
	ii pf = {-2, -2};
	for(int i=0; i<n; i++) for(int j=0;j <n; j++){
		if(ans[i][j]=='Z' and M[i][j]!=pf) return cout << "INVALID" << endl, 0;
	}
	for(int i=0; i<n; i++) for(int j=0;j <n; j++){
		if(ans[i][j]=='Z'){
			bfs(i, j);
		}
	}
	if(!show) return cout << "INVALID" << endl, 0;
	cout << "VALID" << endl;
	for(int i=0; i<n; i++){
		for(int j=0;j <n; j++){
			cout << ans[i][j];
		}
		cout << endl;
	}

	exit(0);
}
