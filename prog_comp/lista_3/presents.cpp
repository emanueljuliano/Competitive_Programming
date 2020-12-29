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

bool M[101][101][2010];

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(2*n);
		int s = 0;
		for(auto &i:v) cin >> i, s+=i;
		for(int i=0;i <=n; i++) for(int j=0; j<=n; j++) for(int k=0; k<=1000+s; k++)
			M[i][j][k] = false;
		
		int ans = INF;
		function<void(int, int, int)> solve = [&](int i, int j, int c){
			if(i>n or j>n) return;
			if(i==n and j==n){ ans = min(ans, abs(1000-c)); return;}
			if(M[i][j][c]) return;

			M[i][j][c] = true;
			solve(i+1, j, c+v[i+j]);
			solve(i, j+1, c-v[i+j]);
		};
		solve(0, 0, 1000);
		cout << ans << endl;
	}
	
	exit(0);
}
