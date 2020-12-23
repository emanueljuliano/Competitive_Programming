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
		int n, m;
		cin >> n >> m;
		vector M(n, vector<int>(m));
		vector R(n, vector<int>(m));
		vector C(m, vector<int>(n));
		
		for(auto &u : R) for(auto &x : u) cin >> x;
		for(auto &u : C) for(auto &x : u) cin >> x;

		vector<int> id(n);
		int a = C[0][0];
		int pos = 0;
		for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(R[i][j]==a) pos = j;
		for(int i=0;i <n; i++){
			a = C[0][i];
			for(int j=0; j<n; j++) if(R[j][pos] == a) {id[i] = j; break;}
		}

		for(int i=0;i <n; i++) for(int j=0; j<m; j++) M[i][j] = R[id[i]][j];

		for(auto u : M){
			for(auto c : u) cout << c << " ";
			cout << endl;
		}
	}
	
	
	
	exit(0);
}
