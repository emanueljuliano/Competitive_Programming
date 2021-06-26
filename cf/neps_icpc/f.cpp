#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

template<class T> struct minstack {
	stack<pair<T, T>> s;

	void push(T x) {
		if (!s.size()) s.push({x, x});
		else s.push({x, std::max(s.top().second, x)});
	}
	T top() { return s.top().first;	}
	T pop() {
		T ans = s.top().first;
		s.pop();
		return ans;
	}
	T size() { return s.size(); }
	T max() { return s.top().second; }
};

template<class T> struct minqueue {
	minstack<T> s1, s2;

	void push(T x) { s1.push(x); }
	void move() {
		if (s2.size()) return;
		while (s1.size()) {
			T x = s1.pop();
			s2.push(x);
		}
	}
	T front() { return move(), s2.top(); }
	T pop() { return move(), s2.pop(); }
	T size() { return s1.size()+s2.size(); }
	T max() {
		if (!s1.size()) return s2.max();
		else if (!s2.size()) return s1.max();
		return std::max(s1.max(), s2.max());
	}
};

int main(){ _
	int h, w, k; cin >> h >> w >> k;

	vector M(2, vector (h, vector<int>(w, INF)));
	
	vector<int> sz(w);
	for (int i=1; i<=h*w; i++) {
		int a; cin >> a; a--;
		M[i%2][h-1-sz[a]][a] = i;
		sz[a]++;
	}
	/*for (int t=0; t<2; t++) {
		cout << endl;
		for (int i=0; i<h; i++) {
			for (int j=0; j<w; j++) cout << M[t][i][j] << " ";
			cout << endl;
		}
	}*/
	

	int ans = INF;

	auto solve = [&](int i, int j, int di, int dj) {
		int ii = i, jj = j;
		for (int t=0; t<2; t++) {
			i = ii, j = jj;
			minqueue<int> mq;
			while (i >= 0 and j >= 0 and i < h and j < w) {
				mq.push(M[t][i][j]);
				if (mq.size() > k) mq.pop();
				if (mq.size() == k) ans = min(ans, mq.max());
				i += di, j += dj;
				//cout << t << " " << i << " " << j << "  " << mq.max() << endl;
			}
		}
	};

	for (int i=0; i<h; i++) {
		solve(i, 0, 0, 1);
		solve(i, 0, -1, 1);
		solve(i, 0, 1, 1);
	}
	for (int j=0; j<w; j++) {
		solve(0, j, 1, 0);
		solve(0, j, 1, 1);
		solve(h-1, j, -1, 1);
	}

	if (ans == INF) cout << "D" << endl;
	else if (ans % 2 == 1) cout << "A " << ans << endl;
	else if (ans % 2 == 0) cout << "B " << ans << endl;

	
	
	exit(0);
}
