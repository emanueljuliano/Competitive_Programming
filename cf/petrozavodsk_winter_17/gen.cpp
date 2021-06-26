#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

int main(int argc, char**argv){ _
	srand(atoi(argv[1]));
	
	int mx = 1e4;
	int n = 10;//uniform(1, mx);

	vector<pair<int, int>> ans;
	for (int i=0; i<n; i++) {
		ans.push_back({uniform(1, 100), uniform(1, 100)});
	}
	
	sort(ans.begin(), ans.end());
	cout << n << endl;
	for (auto [a, b] : ans) cout << a << " " << b << endl;

	exit(0);
}
