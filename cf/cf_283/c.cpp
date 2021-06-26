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


vector<string> M;

int main(){ _
	int n, m; cin >> n >> m;
	M.resize(n);
	for(auto &u : M) cin >> u;
	
	int ans = 0;
	vector<int> v(n);
	for(int j=0;j <m; j++){
		bool remove = false;
		for(int i=1; i<n; i++) if(!v[i] and M[i][j]<M[i-1][j]) remove = true;
		if(!remove){
			for(int i=1; i<n; i++) if(M[i][j]>M[i-1][j]) v[i] = true;
		}
		else ans++;
	}
	cout << ans << endl;
	
	
	exit(0);
}
