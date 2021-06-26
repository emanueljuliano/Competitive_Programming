#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;
	bool can = true;
	int zeros = 0;
	vector<int> ans;
	map<int, int> mp;
	

	for (int i=0; i<n; i++) {
		int a; cin >> a;
		if (a == 0) zeros++;
		else if (a > 0) {
			mp[a]++;
		}
		else {
			if (mp[-a]) mp[-a]--;
			else {
				if (!zeros) can = false;
				else zeros--, ans.push_back(-a);
			}
		}
	}

	if (can) {
		cout << "Yes" << endl;
		for (auto u : ans) cout << u << " ";
		while (zeros) cout << 1 << " ", zeros--;
		cout << endl;
	}
	else cout << "No" << endl;
	
	
	
	exit(0);
}
