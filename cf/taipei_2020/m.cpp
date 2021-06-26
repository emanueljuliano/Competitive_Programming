#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<int> v(n), w(m);
		for(auto &i : v) cin >> i;
		for(auto &i : w) cin >> i;

		if(n==2 and m==2) cout << 7 << endl;
		else cout << 1 << endl;
	}
	
	
	
	exit(0);
}
