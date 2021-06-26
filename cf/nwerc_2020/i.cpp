#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int t[440];
int v[3][440];
int n;

vector<pair<int, int>> trip(int a, int i) {
	vector<pair<int, int>> ret(n);
	ret[i] = {0, v[a][i]};
	int time = v[a][i];
	int j = i;
	for (int it=1; it<n; it++) {
		time += t[j];
		j = (j+1)%n;
		ret[j] = {time, time+v[a][j]};
		time += v[a][j];
	}
	/*if ((a==0 and i==0) or (a==1 and i==4)) {
		cout << "trip " << a << " " << i << endl;
		for (auto [l, r] : ret) cout << "(" << l << ", " << r << ") ";
		cout << endl;
	}*/
	return ret;
}

int nxt(int a, int i, int b, int proib) {
	//cout << a << " " << i << " " << b << " " << proib << endl;
	if (i == -1) return -1;
	auto va = trip(a, i);
	for (int it = 1; it<n; it++) {
		int j = (i+it)%n;
		if (j == proib) return -1;
		auto vb = trip(b, j);
		
		bool show = true;
		for (int k = 0; k < n and show; k++) {
			if (max(va[k].first, vb[k].first) < min(va[k].second, vb[k].second))
				show = false;
		}
		if (show) return j;
	}
	return -1;
}

void solve(int a, int b, int c) {
	for (int i=0; i<n; i++) {
		int j = nxt(a, i, b, i);
		int k = nxt(b, j, c, i);
		int l = nxt(c, k, a, (i+1)%n);
		//cout << "nxt " << j << " " << k << " " << l << endl;
		if (j == -1 or k == -1 or l == -1) continue;
		if (b == 1) cout << i+1 << " " << j+1 << " " << k+1 << endl;
		else cout << i+1 << " " << k+1 << " " << j+1 << endl;
		exit(0);
	}
}

int main(){ _
	cin >> n;
	for (int i=0; i<n; i++) cin >> t[i];
	for (int j=0; j<3; j++) for (int i=0; i<n; i++) cin >> v[j][i];
	
	solve(0, 1, 2);
	solve(0, 2, 1);
	cout << "impossible" << endl;
	
	exit(0);
}
