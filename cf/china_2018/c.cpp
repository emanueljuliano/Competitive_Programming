#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int t; cin >> t;
	for(int tt=1; tt<=t; tt++){
		cout << "Case #" << tt << ": ";

		int n, m; cin >> n >> m;
		string s1, s2, t2;
		cin >> s1 >> s2 >> t2;
		string t1;
		int shift = s2[0]-s1[0];
		for(auto u : t2){
			int c = u-'A';
			c -= shift;
			c = (c+26)%26;
			t1 += char(c+'A');
		}
		cout << t1 << endl;

	}
	
	
	
	exit(0);
}
