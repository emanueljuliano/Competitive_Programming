#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;
typedef long double ld;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

template<typename T> T max_dist_manhattan(vector<pair<T, T>> v) {
	T min_sum, max_sum, min_dif, max_dif;
	min_sum = max_sum = v[0].first + v[0].second;
	min_dif = max_dif = v[0].first - v[0].second;
	for (auto [x, y] : v) {
		min_sum = min(min_sum, x+y);
		max_sum = max(max_sum, x+y);
		min_dif = min(min_dif, x-y);
		max_dif = max(max_dif, x-y);
	}
	return max(max_sum - min_sum, max_dif - min_dif);
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
