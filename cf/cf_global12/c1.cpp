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

int main(){ _
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector M(n, vector(n, char()));
		for(auto &v : M) for(auto &i:v) cin >> i;
		vector<pair<int, ii>> ans(n*n);
		for(int m1=0; m1<3; m1++) for(int m2=0; m2<3; m2++) {
			if(m1==m2) continue;
			vector<pair<int, ii>> at;
			for(int i=0;i <n; i++) for(int j=0; j<n; j++) {
				if((i+j)%3==m1){if(M[i][j]=='X') at.pb({0, {i, j}});} 
				else if((i+j)%3==m2){if(M[i][j]=='O') at.pb({1, {i, j}});} 
			}
			if(at.size()<ans.size()) ans = at;
		}
		for(auto [f, p] : ans) {
			if(f) M[p.f][p.s] = 'X';
			else M[p.f][p.s] = 'O';
		}
		for(int i=0;i <n; i++) {
			for(int j=0; j<n; j++) cout << M[i][j];
			cout << endl;
		}
	}
	
	
	
	exit(0);
}
