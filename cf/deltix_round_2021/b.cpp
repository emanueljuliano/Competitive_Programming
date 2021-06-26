#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> v(n);
		for (auto &i : v) cin >> i;
		
		cout << n/2*6 << endl;
		for (int i=1; i<=n; i+=2) {
			cout << 2 << " " << i << " " << i+1 << endl;
			cout << 1 << " " << i << " " << i+1 << endl;
			cout << 2 << " " << i << " " << i+1 << endl;
			cout << 1 << " " << i << " " << i+1 << endl;
			cout << 2 << " " << i << " " << i+1 << endl;
			cout << 1 << " " << i << " " << i+1 << endl;
		}
	}
	
	
	
	exit(0);
}
