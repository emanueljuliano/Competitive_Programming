#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	
	vector<int> pref;
	int it = 0;
	for (int i=0; i<n; i++) {
		if(it < m and s[i] == t[it]) pref.push_back(i), it++;
	}

	vector<int> suf;
	it = m-1;
	for (int i=n-1; i>=0; i--) {
		if(it >= 0 and s[i] == t[it]) suf.push_back(i), it--;
	}
	reverse(suf.begin(), suf.end());

	int ans = 0;
	for (int i=0; i<m-1; i++) {
		ans = max(ans, suf[i+1]-pref[i]);
	}

	cout << ans << endl;
	
	
	
	exit(0);
}
