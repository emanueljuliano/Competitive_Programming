#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;
	vector<int> v(n);
	for (auto &i : v) cin >> i;
	
	for (int i=0; i<n; i++) {
		string s(2*n, '1');
		s[n-1-i] = '9';
		while (s.size() > n+v[i]) s.pop_back();
		cout << s << " ";
	}
	cout << endl;
	
	
	
	exit(0);
}
