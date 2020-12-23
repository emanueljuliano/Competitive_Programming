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


int main(){ _
	int n, m; cin >> n >> m;

	auto is_prime = [&](int x){
		if(x==1) return 0;
		for(int j=2; j*j<=x; j++) if(x%j==0) return 0;
		return 1;
	};
	
	vector<vector<ii>> g(n+1);
	int at = 0;
	for(int i=1;i <n-1; i++){
		g[i].pb({i+1, 1}), at++;

	}
	int last = at+1;
	while(!is_prime(last)) last++;
	g[n-1].pb({n, last-at});

	int eg = n-1;
	int maxi = 2*n;
	for(int i=1; i<n and eg<m; i++){
		for(int j=i+2; j<=n and eg<m; j++) g[i].pb({j, maxi}), eg++; 
	}
	
	cout << last << " " << last  << endl;
	for(int v = 1; v<=n; v++) for(auto [u, d]: g[v]) cout << v << " " <<u << " " << d << endl;
	
	
	exit(0);
}
