#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

bool ord(string a, string b) {
	return (a+b < b+a);
}

int main(){ _
	int n; cin >> n;
	vector<string> v(n);
	for (auto &i : v) cin >> i;
	sort(v.begin(), v.end(), ord);
	for (auto u : v) cout << u;
	cout << endl;
	
	
	
	exit(0);
}
