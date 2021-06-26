#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int M[1010][10];

int main(){ _
	int n; cin >> n;
	
	pair<int, int> ans = {INF, -1};
	for (int i=0; i<n; i++) {
		int a; cin >> a;
		string s; cin >> s;
		for (auto c : s) 
			M[i][c-'0']++;

		if (M[i][2] >= 2 and M[i][0] and M[i][1] and (pair<int, int>(a, i) < ans))
			ans = {a, i};
	}
	
	cout << ans.second+1 << endl;
	
	
	exit(0);
}
