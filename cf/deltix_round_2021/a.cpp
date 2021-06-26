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
		int n, m; cin >> n >> m;
		string s; cin >> s;

		for (int it=0; it<min(m, n+1); it++) {
			string ns = s;
			for (int i=0; i<n; i++) {
				if (s[i] == '0') {
					int nei = 0;
					if (i != 0 and s[i-1] == '1') nei++;
					if (i != n-1 and s[i+1] == '1') nei++;
					if (nei == 1) ns[i] = '1';
				}
			}
			s = ns;
		}
		cout << s << endl;
	}
	
	
	
	exit(0);
}
