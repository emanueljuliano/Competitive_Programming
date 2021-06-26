#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int main(){ _
	int n; cin >> n;
	vector<pair<pair<int, int>, int>> v(n);
	for(int i=0;i <n; i++) {
		int x, y; cin >> x >> y;
		v[i] = {{x, y}, i+1};
	}
	sort(v.begin(), v.end());
	cout << 1+2*(n-1) << endl;
	for(int i=0; i<n; i++) cout << v[i].second << " ";
	for(int i=n-2; i+1; i--) cout << v[i].second << " ";
	cout << endl;
	
	exit(0);
}
