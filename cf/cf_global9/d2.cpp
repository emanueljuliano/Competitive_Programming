#include <bits/stdc++.h>
using namespace std;

void solve() {
	int N; cin >> N;
	vector<int> A(N);
	vector<int> M(N+1, 0);
	for (auto &x: A) {
		cin >> x;
		M[x]++;
	}
	auto mex = [&]() {
		for (int i = 0; i <= N; i++) {
			if (M[i] == 0) return i;
		}
	};
	vector<int> K;
	for (int ki = 0; ki < N; ki++) {
		int m = mex(), k;
		if (m == N) {
			for (int i = 0; i < N; i++) {
				if (A[i] != i) {
					k = i;
					break;
				}
			}
		} else {
			k = m;
		}
		K.emplace_back(k);
		M[A[k]]--, M[m]++;
		A[k] = m;
		if (m == N) {
			m = mex();
			assert(m != N);
			k = m;
			K.emplace_back(k);
			M[A[k]]--, M[m]++;
			A[k] = m;
		}
	}
	cout << K.size() << "\n";
	for (int i = 0; i < K.size(); i++) {
		if (i) cout << " ";
		cout << K[i]+1;
	}
	cout << "\n";
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int T; cin >> T;
	while (T--) solve();
	return 0;
}
