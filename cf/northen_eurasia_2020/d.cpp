#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n;
	cin >> n;

	vector<string> v(n);
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}

	auto simi = [&](int i, int j){
		int sum = 0;
		for (int k = 0; k < 8; k++){
			sum += v[i][k] == v[j][k];
		}
		return sum;
	};

	vector<bool> reach(n, false);
	
	function<void(int)> dfs = [&](int i){
		if (reach[i]) return;
		reach[i] = true;
		for (int j = 1; j <= 8; j++){
			if (i+j >= n) continue;
			int s = simi(i, i+j);
			if (s >= j) dfs(i+j);
		}
	};
	dfs(0);


	vector<bool> wins(n, false);
	wins[0] = false;

	cout << 2;

	bool prev = false;

	for (int i = 1; i < n; i++){
		bool ans;

		if (!reach[i]) {
			ans = prev;
		}
		else{
			bool w = false;
			for (int j = 1; j <= 8; j++){
				if (i-j < 0) continue;
				if (!reach[i-j]) continue;
				int s = simi(i, i-j);
				if (s >= j && !wins[i-j]){
					w = true;
				}
			}
			ans = prev = wins[i] = w;
		}

		if (ans) cout << 1;
		else cout << 2;
	}
	cout << endl;
	exit(0);
}
