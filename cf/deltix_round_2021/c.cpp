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

		vector<int> v(n+1, 0);
		int cur = 0;

		for (int it=0; it<n; it++) {
			int at; cin >> at;
			string s;
			while (v[cur]+1 != at) {
				v[cur] = 0; cur--;
			}
			for (int j=0; j<cur; j++) s += to_string(v[j]), s += ".";
			s += to_string(v[cur]+1); v[cur]++;
			cur++;
			cout << s << endl;
		}
	
	}
	
	
	
	exit(0);
}
