#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

template<typename T> T max_dist_manhattan(vector<pair<T, T>> v) {
	T ans = 0;
	for (auto [x, y] : v) for (auto [x2, y2] : v)
		ans = max(ans, abs(x - x2) + abs(y - y2));
	return ans;
}

int main(){ _
	int n; cin >> n;
	vector<pair<int, int>> v(n);
	for (int i=0;i <n; i++) {
		int x, y; cin >> x >> y;
		v[i] = {x, y};
	}
	cout << max_dist_manhattan(v) << endl;
	
	exit(0);
}
